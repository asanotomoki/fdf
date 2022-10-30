/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:45 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/30 18:26:54 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_errno.h"
# include "libft.h"
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
#include <stdio.h>

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 640

# define PURPLE 0x392270
# define RIGHT_PURPLE 0xba55d3
# define BLUE 0x4169e1
# define RIGHT_BLUE 0x5de8e5
# define GREEN 0x7fffd4
# define YELLOW 0xffd700
# define ORANGE 0xf4a460
# define PINK 0xf44d9b
# define RED 0xc71585
# define RIGHT_RED 0xe9275b
# define WHITE 0xffffff
# define BLACK 0x101010
# define GRAY 0x888888

typedef struct s_point
{
	int	x;
	int y;
	int	z;
	int	color;
} 	t_point;

typedef struct s_maplst
{
	t_point			p;
	struct s_maplst	*next;
} 	t_maplst;


typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_camera
{
	int	zoom;
	int shift_x;
	int shift_y;
} t_camera;

typedef	struct s_map
{
	int		width;
	int		height;
	int		z_min;
	int		z_max;
	t_point **data;
} t_map;


typedef struct s_fdf
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	t_map		*map;
	t_camera	*camera;
} t_fdf;


int fdf(char *argv);

//draw_tool
void	draw(t_fdf *fdf);
t_point	get_delta(t_point from, t_point to);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void 	put_string(t_fdf *fdf);

//init
void fdf_init(t_fdf *fdf, char *filename);

//error
void err_msg(char *msg, int status);
void perror_exit(char *msg, int status);

//hooks
int	hooks(t_fdf	*fdf);

//create_map
void create_map(char *file_name, t_fdf *fdf);

//check_map
void	check_map(int fd, t_fdf *fdf);

//color_tool
int	get_color(t_fdf *fdf, t_point p);
int cal_color(t_point p, t_point from, t_point to, t_point delta);

# endif