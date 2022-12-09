/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasano <tasano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:28:44 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/12/09 16:51:36 by tasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf(char *argv)
{
	t_fdf	*fdf;

	fdf = fdf_init(argv);
	draw(fdf);
	hooks(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
