/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:02:45 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/30 20:10:42 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <errno.h>

void	err_msg(char *msg, int status)
{
	ft_putendl_fd(msg, 2);
	exit(status);
}

void	perror_exit(char *msg, int status)
{
	perror(msg);
	exit(status);
}
