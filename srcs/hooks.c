/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:30:43 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/30 18:04:03 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key.h"

int close_program()
{
	exit(EXIT_SUCCESS);
}

void shift(t_fdf *fdf, int key)
{
	// if (key == B_UP)
	// 	fdf->camera->shift_y += 50;
	// else if (key == B_DOWN)
	// 	fdf->camera->shift_y -= 50;
	// else if (key == B_LEFT)
	// 	fdf->camera->shift_x -= 50;
	// else if (key == B_RIGHT)
	// 	fdf->camera->shift_x -= 50;
	printf("key : %d %d\n", key, fdf->camera->shift_x);
	// draw(fdf);
}

int	key_hooks(int key, t_fdf *fdf)
{
	if (key == B_ESC || key == B_X)
		close_program();
	else if (B_LEFT <= key || key <= B_UP)
		shift(fdf, key);
	return (0);
}

int mouse_hooks(int keycode, t_fdf *fdf)
{
	if (keycode)
		printf("%d\n", keycode);
	else
		fdf->map->height = 1;
	return (0);
}

int hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->mlx_win, key_hooks, &fdf);
	// mlx_mouse_hook(fdf->mlx_win, mouse_hooks, &fdf);
	mlx_hook(fdf->mlx_win, 17, 1L<<17, close_program, &fdf);
	return (0);
}