#ifndef PARSING_H
#define PARSING_H


# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
#include <unistd.h>

typedef struct s_tinfo
{
	//MAP:
	char** dbl_ptr;
	int 	counting_line;
	int 	hieght;
	char* 	file_name;
	int 	fd;
	//los colores:
	int floor[3];
	int ceiling[3];
	
}t_tinfo;

// ERROR:
void    ft_error(char *str, char *arg);
// MAP:
// void reading_map(int fd);
// char **ft_read_map(&map_info);

// //	CHECK :
// int ft_check_cub(char *filename);
// int ft_check_xpm(char *str);
// int	ft_check_new_line(char *str);

#endif
