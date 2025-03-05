#ifndef PARSING_H
#define PARSING_H


# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
#include <unistd.h>
#include <string.h>
typedef struct s_tinfo
{
	//MAP:
	char** dbl_ptr;
	int 	counting_line;
	int 	hieght;
	// int 	width;
	char* 	file_name;
	int 	fd;
	//los colores:
	int floor[3];
	int ceiling[3];
	
}t_tinfo;

// 		ERROR:
void    ft_error(char *str, char *arg);


//  	CHECK :
void	validation_extantion(t_tinfo *mapp, int ac, char **av);
void	validation_exist(t_tinfo *mapp);

//		MAP:
char	**ft_read_map(t_tinfo *mapp);
void check_f_and_last_line(t_tinfo *mapp);

// 		UTILS:
int ft_height(t_tinfo *mapp);
int ft_count_height_map(t_tinfo *mapp);

#endif







