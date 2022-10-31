/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:47:19 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/31 14:37:59 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef KEY_H
# define KEY_H

# ifdef __APPLE__
# define KEY_PLUS 41
# define KEY_MINUS 27
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 	126
# define KEY_ESC 53
# define KEY_X 7
# define KEY_I	34
# define KEY_P	35
# define KEY_LESS 43
# define KEY_MORE 47
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# endif

# ifdef __linux__
#  define MOUSE_UP	4
#  define MOUSE_DOWN	5
#  define KEY_LEFT		65361
#  define KEY_RIGHT		65363
#  define KEY_DOWN		65364
#  define KEY_UP		65362
#  define KEY_PLUS		59
#  define KEY_MINUS		45
#  define KEY_ESC		65307
#  define KEY_I			105
#  define KEY_P			112
#  define KEY_LESS		44
#  define KEY_MORE		46
# endif

# endif