#ifndef MAIN_H
# define MAIN_H

#include "../include/new.h"
#include <stdbool.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "../include/color.h"


int	ft_isspace(int c);
void ft_error(char *str, char *arg);
bool	ft_empty_line(char *line);
#endif