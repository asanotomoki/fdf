/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:58:24 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/29 07:29:38 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_all(char **args)
{
	size_t i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

char **paese_line(int fd)
{
	char *tmp;
	char **res;

	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	res = ft_split(tmp, ' ');
	free(tmp);
	if (!res)
		perror_exit("ft_split", EXIT_FAILURE);
	return (res);
}

void z_minmax(t_fdf *fdf, int z)
{
	if (fdf->map->z_max < z)
		fdf->map->z_max = z;
	else if (fdf->map->z_min > z)
		fdf->map->z_min = z;
}

t_maplst *map_new_data(int x, int y, int z, int color)
{
	t_maplst *res;

	res = (t_maplst *)malloc(sizeof(t_maplst));
	if (!res)
		perror_exit("new map lst", EXIT_FAILURE);
	res->p.x = x;
	res->p.y = y;
	res->p.z = z;
	res->p.color = color;
	res->next = NULL;
	return (res);
}

t_maplst *map_lstlast(t_maplst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void map_add_back(t_maplst *lst, t_maplst *new)
{
	if (new == NULL)
		return;
	if (lst == NULL)
		lst = new;
	else
		map_lstlast(lst)->next = new;
}

void create_z_col(t_fdf *fdf, t_maplst *lst, char **data, int x)
{
	char **tmp;
	int color;
	int z;

	tmp = ft_split(*data, ',');
	if (!tmp)
		perror_exit("ft_split", EXIT_FAILURE);
	z = ft_atoi(tmp[0]);
	color = -1;
	if (tmp[1])
		color = ft_strtol(tmp[1], NULL, 16);
	map_add_back(lst, map_new_data(x, 0, z, color));
	z_minmax(fdf, z);
	free_all(tmp);
}

void check_width(t_fdf *fdf, int x)
{
	if (fdf->map->width == 0)
		fdf->map->width = x;
	else if (fdf->map->width != x)
		err_msg("Map ERROR", EXIT_FAILURE);
}

void pase_map(t_fdf *fdf, char **line_data, t_maplst *maplst, int y)
{
	int x;
	t_maplst *lsttmp;

	lsttmp = map_lstlast(maplst);
	x = 0;
	while (*line_data)
	{
		create_z_col(fdf, lsttmp, line_data++, x);
		lsttmp = lsttmp->next;
		lsttmp->p.y = y;
		x++;
	}
	check_width(fdf, x);
}

t_maplst *create_maplst(t_fdf *fdf, int fd)
{
	char **line_data;
	int y;
	t_maplst *maplst;
	
	maplst = (t_maplst *)malloc(sizeof(t_maplst));
	maplst->next = NULL;
	y = 0;
	while (1)
	{
		line_data = paese_line(fd);
		if (!line_data)
			break;
		pase_map(fdf, line_data, maplst, y);
		free(line_data);
		y++;
	}
	fdf->map->height = y;
	return (maplst);
}

void malloc_array(t_fdf *fdf, int width, int height)
{
	int i;
	
	fdf->map->data =  (t_point **)malloc(sizeof(t_point) * height);
	if (!fdf->map->data)
		perror_exit("malloc array", EXIT_FAILURE);
	i = 0;
	while (i < height)
	{
		fdf->map->data[i] = malloc(sizeof(t_point) * width);
		if (!fdf->map->data[i])
			perror_exit("malloc array", EXIT_FAILURE);
		i++;
	}
	
}

void chenge_array(t_fdf *fdf, t_maplst *maplst)
{
	int x;
	int y;
	t_maplst *tmp;

	malloc_array(fdf, fdf->map->width, fdf->map->height);
	y = 0;
	maplst = maplst->next;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			tmp = maplst;
			fdf->map->data[y][x] = maplst->p;
			maplst = maplst->next;
			free(tmp);
			x++;
		}
		y++;
	}
}

void create_map(char *file_name, t_fdf *fdf)
{
	int fd;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		perror_exit("File not open", EXIT_FAILURE);
	chenge_array(fdf, create_maplst(fdf, fd));
	close(fd);
}