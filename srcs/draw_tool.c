/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:20:27 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/31 14:42:49 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_string(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->mlx_win, 30, 30, RED, "42 FDF");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 30, 60, RED, "Move : Arrow");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 30, 80, RED, "Zoom : Scroll or +/-");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 30, 100, RED, "MODE");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 45, 120, RED, "Isometric : I");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 45, 140, RED, "Parallel : P");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 30, 160, RED, "Background");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 45, 180, RED, "Dark   : >");
	mlx_string_put(fdf->mlx, fdf->mlx_win, 45, 200, RED, "Bright : <");
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (0 <= x && x < WINDOW_WIDTH && 0 <= y && y < WINDOW_HEIGHT)
	{
		dst = fdf->img.addr + \
		(y * fdf->img.line_length + x * (fdf->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

t_point	get_delta(t_point from, t_point to)
{
	t_point	res;

	res.x = abs(to.x - from.x);
	res.y = abs(to.y - from.y);
	return (res);
}
