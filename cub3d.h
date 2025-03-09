/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:16:34 by ael-mejd          #+#    #+#             */
/*   Updated: 2025/03/09 16:24:54 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H


#define WIDTH 1280
#define HEIGHT 620
# define MOVESPEED 0.0125
# define ROTSPEED 0.015
# define TILE_SIZE 1000
# define FOV 60

# define RIGHT_FLAG 0
# define LEFT_FLAG 1
# define W_FLAG 2
# define S_FLAG 3
# define D_FLAG 4
# define A_FLAG 5
# define CLOSE_FLAG 6
# define ROTATE_FLAG 7
# define MOVE_FLAG 8
# define KEYS_NB 9

# define ERR_MALLOC "Could not allocate memory"

#include "parsing.h"
#include "mlx.h"
#include <math.h>
#include <stdbool.h>
# include <errno.h>
#include <X11/keysym.h>
#include <X11/X.h>


typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float   fov;
	float	angle;
	float   distance;
	float   angle_step;
}	t_player;

typedef struct s_texture
{
	void	*img;
	char	*iter;
	int		line_length;
	int		pixel_bits;
	int		endianess;
	int		width;
	int		hight;
}	t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	int			map_height;
	int			map_width;
	char		**map;
	int			ceilieng_color;
	int			floor_color;
	int 		keys[KEYS_NB];
	t_player	player;
	t_ray		ray;
	t_img		image;
	t_texture	texinfo[4];
}	t_data;

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};


void init_textures(t_data *data, t_tinfo *info);
void	free_tab(void **tab);
int	quitter(t_data *data);
void	input_handler(t_data *data);
#endif