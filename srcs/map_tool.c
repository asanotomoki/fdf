/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:47:15 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/31 14:58:04 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	z_minmax(t_map *map, int z)
{
	if (map->z_max < z)
		map->z_max = z;
	else if (map->z_min > z)
		map->z_min = z;
}

void	free_all(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	malloc_array(t_map *map, int width, int height)
{
	int	i;

	map->data = malloc(sizeof(t_point) * height);
	if (!map->data)
		perror_exit("malloc array", EXIT_FAILURE);
	i = 0;
	while (i < height)
	{
		map->data[i] = malloc(sizeof(t_point) * width);
		if (!map->data[i])
			perror_exit("malloc array", EXIT_FAILURE);
		i++;
	}
}

void	check_width(t_map *map, int x)
{
	if (map->width == 0)
		map->width = x;
	else if (map->width != x)
		err_msg(ERR_MAP, EXIT_FAILURE);
}
