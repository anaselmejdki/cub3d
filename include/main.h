
#ifndef MAIN_H
# define MAIN_H

# include "../get_next_line/get_next_line.h"
# include "../include/color.h"
# include "../include/new.h"
# include "../libft/libft.h"
# include <ctype.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int		ft_isspace(int c);
void	ft_error(char *str, char *arg);
bool	is_empty_line(char *line);
int		ft_floor(t_parse *parse, char *line);
int		ft_ceil(t_parse *parse, char *line);
void	calculate_map_width(t_parse *parse, char **map);

#endif