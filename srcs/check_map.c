/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:51:25 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/21 15:17:39 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	count_space(char *line)
{
	size_t	count;

	count = 0;
	while (*line)
	{
		if (ft_isspace(*line))
		{
			count++;
			while (ft_isspace(*line))
				line++;
		} 
		else
			line++;
	}
	return (count);
}

void check_width(t_fdf *fdf, char *line)
{
	if (fdf->map->width != count_space(line) + 1)
		err_msg("Map ERROR", EXIT_FAILURE);
}

void	check_map(int fd, t_fdf *fdf)
{
	char *tmp;

	tmp = get_next_line(fd);
	fdf->map->width = count_space(tmp) + 1;
	free(tmp);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		check_width(fdf, tmp);
		fdf->map->height++;
		free(tmp);
	}
}
