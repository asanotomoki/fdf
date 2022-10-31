/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:30:43 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/31 14:22:17 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key.h"

int	close_program(void)
{
	exit(EXIT_SUCCESS);
}

int	key_hooks(int key, t_fdf *fdf)
{
	if (key == KEY_ESC || key == KEY_X)
		close_program();
	else if (KEY_LEFT <= key && key <= KEY_UP)
		shift(fdf, key);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		zoom(fdf, key);
	else if (key == KEY_P || key == KEY_I)
		mode(fdf, key);
	else if (key == KEY_LESS || key == KEY_MORE)
		background(fdf, key);
	return (0);
}

int	mouse_hooks(int key, int x, int y, t_fdf *fdf)
{
	x = y;
	y = x;
	if (key == MOUSE_DOWN || key == MOUSE_UP)
		zoom(fdf, key);
	return (0);
}

int	hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->mlx_win, key_hooks, fdf);
	mlx_mouse_hook(fdf->mlx_win, mouse_hooks, fdf);
	mlx_hook(fdf->mlx_win, 17, 1L << 17, close_program, fdf);
	return (0);
}
