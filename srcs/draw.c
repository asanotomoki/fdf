/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:06:13 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/30 18:27:46 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void bresenham(t_point from, t_point to, t_fdf *fdf)
{
	t_point delta;
	t_point	p;
	int error[2];

	delta = get_delta(from, to);
	error[0] = delta.x - delta.y;
	p = from;
	while (p.x != to.x || p.y != to.y)
	{
		my_mlx_pixel_put(fdf, p.x, p.y, cal_color(p, from, to, delta));
		error[1] = 2 * error[0];
		if (error[1] > -delta.y)
		{
			p.x += 1;
			error[0] -= delta.y;
		}
		if (error[1] < delta.x)
		{
			p.y += 1;
			error[0] += delta.x;
		}
	}
}

t_point projection(t_fdf *fdf, t_point p)
{
	p.x *= fdf->camera->zoom;
	p.y *= fdf->camera->zoom;
	if (p.color == -1)
		p.color = get_color(fdf, p);
	p.x += fdf->camera->shift_x;
	p.y += fdf->camera->shift_y;
	return (p);
}

void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
				bresenham(projection(fdf, fdf->map->data[y][x]), \
						projection(fdf, fdf->map->data[y][x + 1]), fdf);
			if (y < fdf->map->height - 1)
				bresenham(projection(fdf, fdf->map->data[y][x]), \
						projection(fdf, fdf->map->data[y + 1][x]), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	put_string(fdf);
}