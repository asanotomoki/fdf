/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:20:27 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/30 17:59:45 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void put_string(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->mlx_win, 10, 20, RED, "test");
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	// int	i;

	// if (0 <= x && x < WINDOW_WIDTH && 0 <= y && y < WINDOW_HEIGHT)
	// {
	// 	i = (y * fdf->img.line_length) + x * (fdf->img.bits_per_pixel / 8);
	// 	fdf->img.addr[i] = color;
	// 	fdf->img.addr[++i] = color >> 8;
	// 	fdf->img.addr[++i] = color >> 16;
	// 	fdf->img.addr[++i] = 1;
	// }
	char	*dst;

	dst = fdf->img.addr + (y * fdf->img.line_length + x * (fdf->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_point	get_delta(t_point from, t_point to)
{
	t_point res;

	res.x = abs(to.x - from.x);
	res.y = abs(to.y - from.y);
	return (res);
}
