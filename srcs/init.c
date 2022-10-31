/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:23:44 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/31 14:21:53 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!(fdf->mlx))
		err_msg("Error : mlx_init", EXIT_FAILURE);
	fdf->mlx_win = mlx_new_window(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!(fdf->mlx_win))
		err_msg("Error : mlx_new_window", EXIT_FAILURE);
	fdf->img.img = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!(fdf->img.img))
		err_msg("Error : mlx_new_imgage", EXIT_FAILURE);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, \
	&fdf->img.line_length, &fdf->img.endian);
	if (!(fdf->img.addr))
		err_msg("Error : mlx_get_data_addr", EXIT_FAILURE);
}

t_map	*map_init(char *filename)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		perror_exit("map init", EXIT_FAILURE);
	map->width = 0;
	map->height = 0;
	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	create_map(filename, map);
	return (map);
}

int	get_zoom(int w, int h)
{
	int	i;

	i = 0;
	while (i * w < (WINDOW_WIDTH / 2) && i * h < (WINDOW_HEIGHT / 2))
		i++;
	return (i - 1);
}

t_camera	*camera_init(t_map *map)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		perror_exit("camera init", EXIT_FAILURE);
	camera->zoom = get_zoom(map->width, map->height);
	camera->shift_x = 600;
	camera->shift_y = 400;
	camera->mode = ISO;
	camera->background = BLACK;
	return (camera);
}

t_fdf	*fdf_init(char *filename)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		perror_exit("fdf_init", EXIT_FAILURE);
	fdf->map = map_init(filename);
	fdf->camera = camera_init(fdf->map);
	image_init(fdf);
	return (fdf);
}
