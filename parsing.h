#ifndef PARSING_H
#define PARSING_H


# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
#include <unistd.h>

typedef struct s_par
{
	//los colores:
	int floor[3];
	int ceiling[3];
	
}t_par;

// ERROR:
void    ft_error(char *str, char *arg);
// MAP:
void reading_map(int fd);

//	CHECK :
int ft_check_cub(char *filename);
int ft_check_xpm(char *str);
int	ft_check_new_line(char *str);

#endif
