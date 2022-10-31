/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tool2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:56:36 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/31 04:01:50 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_maplst	*map_new_data(int x, int y, int z, int color)
{
	t_maplst	*res;

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

t_maplst	*map_lstlast(t_maplst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	map_add_back(t_maplst *lst, t_maplst *new)
{
	if (new == NULL)
		return ;
	if (lst == NULL)
		lst = new;
	else
		map_lstlast(lst)->next = new;
}

void	chenge_array(t_map *map, t_maplst *maplst)
{
	int			x;
	int			y;
	t_maplst	*tmp;

	malloc_array(map, map->width, map->height);
	y = 0;
	maplst = maplst->next;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			tmp = maplst;
			if (maplst->p.color == -1)
				maplst->p.color = get_color(map, maplst->p);
			map->data[y][x] = maplst->p;
			maplst = maplst->next;
			free(tmp);
			x++;
		}
		y++;
	}
}
