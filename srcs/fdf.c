/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:28:44 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/30 23:27:05 by asanotomoki      ###   ########.fr       */
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
