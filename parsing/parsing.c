#include "../parsing.h"

//example:
int ft_parsing(t_tinfo *mapp,t_textura *tex, int ac, char *av[])
{
	(void)tex;
	validation_extantion(mapp, ac, av);
	validation_exist(mapp);

	char *line = get_next_line(mapp->fd);
	while (line)
	{
		if (!ft_check_directions(line))
    		printf("0");
			
			
		line = get_next_line(mapp->fd);
	}
	
	// mapp->dbl_ptr = ft_read_map(mapp);
	// ft_height(mapp);
	// check_f_and_last_line(mapp);
	// ft_check_map_borders(mapp->dbl_ptr, mapp->hieght);
	// ft_check_special_chars(mapp->dbl_ptr, mapp->hieght);
	// ft_check_32(mapp->dbl_ptr, mapp->hieght);


	// close (mapp->fd);
	// validation_exist(mapp);
	

    // printf("Loading texture %d: '%s'\n", 0, tex->no);
    // printf("NO: %s\n", tex.no);
    // printf("SO: %s\n", tex.so);
    // printf("WE: %s\n", tex.we);
    // printf("EA: %s\n", tex.ea);
    // printf("Floor: %d, %d, %d\n", tex->f[0], tex->f[1], tex->f[2]);
    // printf("Ceiling: %d, %d, %d\n", tex->c[0], tex->c[1], tex->c[2]);

	// printf("ceiling data : %d\n", tex.c[0]);


	// printing the map
	// t_tinfo mapp;

	// int i = 0;
	// while (mapp->dbl_ptr[i])
	// {
	// 	printf("%s", mapp->dbl_ptr[i]);
	// 	i++;
	// }
	// close (mapp->fd);
	return 1;
}
