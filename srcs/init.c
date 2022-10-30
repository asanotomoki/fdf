/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:23:44 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/30 18:27:29 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_init(t_fdf *fdf)
{
	fdf->img.img = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!(fdf->img.img))
		err_msg("Error : mlx_new_imgage", EXIT_FAILURE);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	if (!(fdf->img.addr))
		err_msg("Error : mlx_get_data_addr", EXIT_FAILURE);
}

void	map_init(t_fdf *fdf, char *filename)
{
	fdf->map = (t_map *)malloc(sizeof(t_map));
	fdf->map->width = 0;
	fdf->map->height = 0;
	fdf->map->z_max = INT_MIN;
	fdf->map->z_min = INT_MAX;
	create_map(filename, fdf);
}

void	camera_init(t_fdf *fdf)
{
	fdf->camera = (t_camera *)malloc(sizeof(t_camera));
	fdf->camera->zoom = 25;
	fdf->camera->shift_x = (WINDOW_WIDTH / 2) - 50;
	fdf->camera->shift_y = (WINDOW_HEIGHT / 2) - 50;
}

void	fdf_init(t_fdf *fdf, char *filename)
{
	fdf->mlx = mlx_init();
	if (!(fdf->mlx))
		err_msg("Error : mlx_init", EXIT_FAILURE);
	fdf->mlx_win = mlx_new_window(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!(fdf->mlx_win))
		err_msg("Error : mlx_new_window", EXIT_FAILURE);
	map_init(fdf, filename);
	camera_init(fdf);
	image_init(fdf);
}