#ifndef NEW_H
# define NEW_H

// # include "cub3d.h"
#include <stdbool.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "../include/color.h"

typedef struct s_parse
{
	char	*file_name;
	char	*valid_set;
	char	**map;
	int		map_height;
	char	*no_text;
	char	*so_text;
	char	*we_text;
	char	*ea_text;
	int		floor_color;
	int		ceil_color;
	char	player_dir;
	int		player_x;
	int		player_y;
	int		fd;
	bool	found_map;
	int		texture_count;
	int		consecutive_blanks;
}			t_parse;

int			ft_parse(t_parse *parse);
char		**duplicate_map(char **map, int *height);
void		free_2d_array(char **str);
bool		validate_map(t_parse *parse);
bool		check_player(t_parse *parse);
void		free_parser(t_parse *parse);
int			print_err(char *info, char *str, int code);
int			get_map_line(t_parse *parse, char *line);
bool		is_empty_line(char *line);
int			parse_textures(t_parse *parse, char *line);
int			parse_colors(t_parse *parse, char *line);
bool		check_top_and_bottom(char **map, int rows);
bool		check_boundaries(char *line);
bool		check_empty_gaps(t_parse *parse, char **map, int i);
int			set_rgb_colors(char *line);
int			validate_and_close(t_parse *parse);

#endif