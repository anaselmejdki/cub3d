#include "../parsing.h"


void ft_check_map_borders(char **map, int height)
{
    (void)height;
	char **ptr = map;
	int i = 0;
	int j = 0;
	while (ptr[i][j])
	{
		printf(" \033[0;35m%c \033[0m", ptr[i][j]);
		if (ptr[i][j] != '1' )
		{
			printf(" \033[0;35m%c \033[0m", ptr[i][j]);
			// ft_error("HOOLA", ptr[i]);
			i++;
		}
		j++;
	}
}






int main(int ac, char *av[])
{
	t_tinfo mapp;
	validation_extantion(&mapp, ac, av);
	validation_exist(&mapp);
	mapp.dbl_ptr = ft_read_map(&mapp);
	ft_height(&mapp);
	check_f_and_last_line(&mapp);
	//checking the border:
	ft_check_map_borders(mapp.dbl_ptr, mapp.hieght);








	// printing the map
	// int i = 0;
	// while (mapp.dbl_ptr[i])
	// {
	// 	printf(":::%s", mapp.dbl_ptr[i]);
	// 	i++;
	// }
	
	return 0;
}