#include "../parsing.h"

int ft_parsing(t_tinfo *mapp,t_textura *tex, int ac, char *av[])
{
	validation_extantion(mapp, ac, av);
	validation_exist(mapp);
	mapp->dbl_ptr = ft_read_map(mapp);
	ft_height(mapp);
	// printf("==> %d\n", mapp->width);exit(0);
	check_f_and_last_line(mapp);
	ft_check_map_borders(mapp->dbl_ptr, mapp->hieght);
	ft_check_special_chars(mapp->dbl_ptr, mapp->hieght);
	ft_check_32(mapp->dbl_ptr, mapp->hieght);


	close (mapp->fd);
	validation_exist(mapp);
	

    ft_parse_textures(mapp, tex);
	close (mapp->fd);
	return 1;
}
