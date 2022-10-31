/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:38:09 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/31 15:49:36 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		err_msg(ERR_ARG, EXIT_FAILURE);
	argv++;
	if (!*argv || !*argv[0])
		err_msg(ERR_ARG, EXIT_FAILURE);
	fdf(*argv);
	return (0);
}
