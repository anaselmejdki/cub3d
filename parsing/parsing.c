#include "../parsing.h"

//	🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥
// int check_name_dot(char *filename)
// {
// 	if (ft_strncmp(&filename[0],".", 1) == 0)
// 	{
// 		return 1;
// 	}
// 	return 0;
// }
//	🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥
// int ft_count_height_map(t_tinfo *mapp)
// {
// 	char* line;

// 	while (line == get_next_line(fd))
// 	{
// 		/* code */
// 	}
	
// }
// char **ft_read_map(t_tinfo *mapp)
// {
// 	mapp->hieght  = ft_count_height_map(mapp);
// 	return 0;
// }
int	validation_extantion(t_tinfo *mapp, int ac, char **av)
{
	char	*ptr;

	if (ac != 2)
		ft_error("argument", NULL);
	ptr = ft_strrchr(av[1], '.');
	if (ft_strncmp(av[1], ".cub", ft_strlen(".cub")) == 0)
		ft_error("Name your file 🐸\n", NULL);
	if (!ptr || ft_strncmp(ptr, ".cub", ft_strlen(ptr)))
		ft_error("extension. Must be .cub\n", NULL);
	// if you want to check on .cub.cub
	mapp->file_name = av[1];
	return (0);
}
void	validation_exist(t_tinfo *mapp)
{
	mapp->fd = open (mapp->file_name, O_RDONLY);
	if (mapp->fd < 0)
		ft_error("can not open this file", mapp->file_name);
}
// int main(int ac, char *av[])
// {
// 	t_tinfo mapp;
// 	validation_extantion(&mapp, ac, av);
// 	validation_exist(&mapp);

// 	// // reading_map(fd);
// 	// map_info.dbl_ptr = ft_read_map(&mapp);
// 	// close (fd);
// 	return 0;
// }