/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:58:24 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/30 20:16:47 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**paese_line(int fd)
{
	char	*tmp;
	char	**res;

	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	res = ft_split(tmp, ' ');
	free(tmp);
	if (!res)
		perror_exit("ft_split", EXIT_FAILURE);
	return (res);
}

void	create_z_col(t_map *map, t_maplst *lst, char **data, int x)
{
	char	**tmp;
	int		color;
	int		z;

	tmp = ft_split(*data, ',');
	if (!tmp)
		perror_exit("ft_split", EXIT_FAILURE);
	z = ft_atoi(tmp[0]);
	color = -1;
	if (tmp[1])
		color = ft_strtol(tmp[1], NULL, 16);
	map_add_back(lst, map_new_data(x, 0, z, color));
	z_minmax(map, z);
	free_all(tmp);
}

void	pase_map(t_map *map, char **line_data, t_maplst *maplst, int y)
{
	int			x;
	t_maplst	*lsttmp;

	lsttmp = map_lstlast(maplst);
	x = 0;
	while (*line_data)
	{
		create_z_col(map, lsttmp, line_data++, x);
		lsttmp = lsttmp->next;
		lsttmp->p.y = y;
		x++;
	}
	check_width(map, x);
}

t_maplst	*create_maplst(t_map *map, int fd)
{
	char		**line_data;
	int			y;
	t_maplst	*maplst;

	maplst = (t_maplst *)malloc(sizeof(t_maplst));
	maplst->next = NULL;
	y = 0;
	while (1)
	{
		line_data = paese_line(fd);
		if (!line_data)
			break ;
		pase_map(map, line_data, maplst, y);
		free(line_data);
		y++;
	}
	map->height = y;
	return (maplst);
}

void	create_map(char *file_name, t_map *map)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		perror_exit("File not open", EXIT_FAILURE);
	chenge_array(map, create_maplst(map, fd));
	close(fd);
}
