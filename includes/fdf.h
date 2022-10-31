/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanotomoki <asanotomoki@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:45 by asanotomoki       #+#    #+#             */
/*   Updated: 2022/10/31 14:33:14 by asanotomoki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_errno.h"
# include "libft.h"
# include "mlx.h"
# include "color.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
#include <stdio.h>

# define WINDOW_WIDTH 1440
# define WINDOW_HEIGHT 800
# define ISO 1
# define PAR 0

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
	int mode;
	int background;
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
void	draw_background(t_fdf *fdf, int color);

//init
t_fdf *fdf_init(char *filename);

//error
void err_msg(char *msg, int status);
void perror_exit(char *msg, int status);

//hooks
int	hooks(t_fdf	*fdf);

void	shift(t_fdf *fdf, int key);
void	zoom(t_fdf *fdf, int key);
void	mode(t_fdf *fdf, int key);
void	background(t_fdf *fdf, int key);

//create_map
void	create_map(char *file_name, t_map *map);
void	chenge_array(t_map *map, t_maplst *maplst);
void	z_minmax(t_map *map, int z);
void	free_all(char **args);
void	malloc_array(t_map *map, int width, int height);
void	check_width(t_map *map, int x);

//maplst
t_maplst *map_new_data(int x, int y, int z, int color);
t_maplst	*map_lstlast(t_maplst *lst);
void	map_add_back(t_maplst *lst, t_maplst *new);

//color_tool
int	get_color(t_map *map, t_point p);
int cal_color(t_point p, t_point from, t_point to, t_point delta);

# endif