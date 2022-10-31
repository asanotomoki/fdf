/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:32:15 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/31 15:06:35 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key.h"

void	shift(t_fdf *fdf, int key)
{
	if (key == KEY_UP)
		fdf->camera->shift_y -= 50;
	else if (key == KEY_DOWN)
		fdf->camera->shift_y += 50;
	else if (key == KEY_LEFT)
		fdf->camera->shift_x -= 50;
	else if (key == KEY_RIGHT)
		fdf->camera->shift_x += 50;
	draw(fdf);
}

void	zoom(t_fdf *fdf, int key)
{
	if (key == KEY_PLUS || key == MOUSE_UP)
		fdf->camera->zoom += 1;
	else if (key == KEY_MINUS || key == MOUSE_DOWN)
		fdf->camera->zoom -= 1;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	draw(fdf);
}

void	mode(t_fdf *fdf, int key)
{
	if (key == KEY_P && fdf->camera->mode == ISO)
	{
		fdf->camera->mode = PAR;
		fdf->camera->shift_x -= 100;
		fdf->camera->shift_y -= 100;
		draw(fdf);
	}
	else if (key == KEY_I && fdf->camera->mode == PAR)
	{
		fdf->camera->mode = ISO;
		fdf->camera->shift_x += 100;
		fdf->camera->shift_y += 100;
		draw(fdf);
	}
}

void	background(t_fdf *fdf, int key)
{
	if (key == KEY_MORE)
		fdf->camera->background -= 0x111111;
	else if (key == KEY_LESS)
		fdf->camera->background += 0x111111;
	if (fdf->camera->background < BLACK)
		fdf->camera->background = BLACK;
	else if (fdf->camera->background > WHITE)
		fdf->camera->background = WHITE;
	draw(fdf);
}
