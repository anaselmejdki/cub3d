/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:16:34 by ael-mejd          #+#    #+#             */
/*   Updated: 2025/03/09 16:31:24 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H


#define WIDTH 1280
#define HEIGHT 620
# define MOVESPEED 0.0125
# define ROTSPEED 0.015
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
	int		pixel_bits;
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
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
}	t_mapinfo;

typedef struct s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texinfo;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	t_mapinfo	mapinfo;
	char		**map;
	t_player	player;
	t_ray		ray;
	int			**texture_pixels;
	int			**textures;
	t_texinfo	texinfo;
	t_img		minimap;
}	t_data;

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};


void    init_img_clean(t_img *img);
int free_data(t_data *data);
void    free_tab(void **tab);
int quiter(t_data *data);
void    clean_exit(t_data *data, int flag);
int	err_msg_val(int detail, char *str, int flag);
int err_msg(char *s1, char *s2, int flag);
void    init_img(t_data *data, t_img *image, int width, int height);
void    init_texture_img(t_data *data, t_img *image, char *path);
void    init_mlx(t_data *data);
void	init_texinfo(t_texinfo *textures);
void	init_data(t_data *data);
void	init_ray(t_ray *ray);
void	init_textures(t_data *data);
void	listen_for_input(t_data *data);
int	move_player(t_data *data);
int	validate_move(t_data *data, double new_x, double new_y);
int	rotate_player(t_data *data, double rotdir);
int	raycasting(t_player *player, t_data *data);
int	render(t_data *data);
void	init_texture_pixels(t_data *data);
void	get_texture_index(t_data *data, t_ray *ray);
void	update_texture_pixels(t_data *data, t_texinfo *tex, t_ray *ray, int x);
void	render_images(t_data *data);
#endif