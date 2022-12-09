/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:06:13 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/11/01 22:31:27 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_background(t_fdf *fdf, int color)
{
	int	i;
	int	*image_addr;

	image_addr = (int *)(fdf->img.addr);
	i = 0;
	while (i < WINDOW_HEIGHT * WINDOW_WIDTH)
	{
		image_addr[i] = color;
		i++;
	}
}

void	bresenham(t_point from, t_point to, t_fdf *fdf)
{
	t_point	delta;
	t_point	p;
	int		error[2];

	delta = get_delta(from, to);
	error[0] = delta.x - delta.y;
	p = from;
	while (p.x != to.x || p.y != to.y)
	{
		my_mlx_pixel_put(fdf, p.x, p.y, cal_color(p, from, to, delta));
		error[1] = 2 * error[0];
		if (error[1] > -delta.y)
		{
			p.x += 2 * (from.x < to.x) - 1;
			error[0] -= delta.y;
		}
		if (error[1] < delta.x)
		{
			p.y += 2 * (from.y < to.y) - 1;
			error[0] += delta.x;
		}
	}
}

t_point	projection(t_fdf *fdf, t_point p)
{
	t_point	tmp;

	p.x *= fdf->camera->zoom;
	p.y *= fdf->camera->zoom;
	p.z *= fdf->camera->zoom;
	if (fdf->camera->mode == ISO)
	{
		tmp = p;
		p.x = (tmp.x - tmp.y) * cos(0.5);
		p.y = (tmp.x + tmp.y) * sin(0.5) - tmp.z;
	}
	p.x += fdf->camera->shift_x;
	p.y += fdf->camera->shift_y;
	return (p);
}

void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	draw_background(fdf, fdf->camera->background);
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
