/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:09:30 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/31 03:59:58 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_percent(int from, int to, int current)
{
	float	position;
	float	distance;

	position = current - from;
	distance = to - from;
	if (distance == 0)
		return (1.0);
	else
		return (position / distance);
}

int	get_color(t_map *map, t_point p)
{
	float	percent;

	percent = get_percent(map->z_min, map->z_max, p.z);
	if (percent < 0.15)
		return (PURPLE);
	else if (percent < 0.25)
		return (RIGHT_PURPLE);
	else if (percent < 0.35)
		return (BLUE);
	else if (percent < 0.5)
		return (RIGHT_BLUE);
	else if (percent < 0.7)
		return (GREEN);
	else if (percent < 0.75)
		return (YELLOW);
	else if (percent < 0.8)
		return (ORANGE);
	else if (percent < 0.9)
		return (PINK);
	else
		return (RIGHT_RED);
}

int	get_rgb(int start, int end, float percent)
{
	return ((end - start) * percent + start);
}

int	cal_color(t_point p, t_point from, t_point to, t_point delta)
{
	float	percent;
	int		red;
	int		green;
	int		blue;

	if (p.color == to.color)
		return (p.color);
	if (delta.x > delta.y)
		percent = get_percent(from.x, to.x, p.x);
	else
		percent = get_percent(from.y, to.y, p.y);
	red = get_rgb((from.color >> 16) & 0xFF,
			(to.color >> 16) & 0xFF, percent);
	green = get_rgb((from.color >> 8) & 0xFF,
			(to.color >> 8) & 0xFF, percent);
	blue = get_rgb(from.color & 0xFF,
			to.color & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}
