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


int main(int ac, char *av[])
{
	if (ac != 2)
	{
		ft_error("argument", NULL);
		return 1;
	}
	// if (!check_exetation(av[1]) || check_name_dot(av[1]))
	if (!ft_check_cub(av[1]))
	{
		ft_error("extension. Must be .cub\n", NULL);
		return 1;
	}
	int fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_error("can not open this file", av[1]);
		return 1;
	}
	reading_map(fd);
	close (fd);
	return 0;
}