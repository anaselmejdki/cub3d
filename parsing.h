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
<<<<<<< HEAD


//  	CHECK :
void	validation_extantion(t_tinfo *mapp, int ac, char **av);
void	validation_exist(t_tinfo *mapp);

//		MAP:
char	**ft_read_map(t_tinfo *mapp);
void check_f_and_last_line(t_tinfo *mapp);

// 		UTILS:
int ft_height(t_tinfo *mapp);
=======
// MAP:
// void reading_map(int fd);
// char **ft_read_map(&map_info);

// 		UTILS:
int	validation_extantion(t_tinfo *mapp, int ac, char **av);
>>>>>>> 31119c9260564e479a3fed590611d639b8dcb9ee
int ft_count_height_map(t_tinfo *mapp);

#endif







