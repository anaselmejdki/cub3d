#ifndef PARSING_H
#define PARSING_H


# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct s_textura
{
    char *no;
    char *so; 
    char *we; 
    char *ea; 
    int f[3];
    int c[3]; 
} t_textura;

typedef struct s_tinfo
{
	//MAP:
	char** dbl_ptr; //hadi wax d map ? ah sajida
	int 	counting_line;
	int 	hieght;
	int 	width; // hadi mkhdemtch biha 
	char* 	file_name;
	int 	fd;
	char    *text_path[4];
	t_textura *tex;
}t_tinfo;



// 		ERROR:
void    ft_error(char *str, char *arg);



//  	CHECK :
int		validation_extantion(t_tinfo *mapp, int ac, char **av);

// ALL:
int ft_parsing(t_tinfo *mapp,t_textura *tex, int ac, char *av[]);

//  	CHECK :
// void	validation_extantion(t_tinfo *mapp, int ac, char **av);
void	validation_exist(t_tinfo *mapp);

//		MAP:
char	**ft_read_map(t_tinfo *mapp);
void	check_f_and_last_line(t_tinfo *mapp);
void	ft_check_map_borders(char **map, int height);
void	ft_check_special_chars(char **map, int height);
void	ft_check_32(char **map, int height);
void ft_store_texture(t_textura *tex, char *line);
void ft_parse_textures(t_tinfo *mapp, t_textura *tex);


// 		UTILS:
int ft_height(t_tinfo *mapp);
// 		UTILS:
int ft_height(t_tinfo *mapp);

// MAP:
// void reading_map(int fd);
// char **ft_read_map(&map_info);

// 		UTILS:
int	validation_extantion(t_tinfo *mapp, int ac, char **av);
int ft_count_height_map(t_tinfo *mapp);

void    free_map(char **map);
/// ljadiiid 
int    ft_check_directions(char *line);
#endif







