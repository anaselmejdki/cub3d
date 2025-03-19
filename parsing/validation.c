#include "../parsing.h"

int validation_extantion(t_tinfo *mapp, int ac, char **av)
{
    char *ptr;
    if (ac != 2)
        ft_error("Incorrect number of arguments!", NULL);
    ptr = ft_strrchr(av[1], '.');
    if (!ptr)
        ft_error("Missing file extension (.cub)!", NULL);
    if (ft_strncmp(ptr, ".cub", ft_strlen(".cub") + 1) != 0)
        ft_error("Invalid extension! Must be .cub", NULL);
    mapp->file_name = av[1];
    return (1);
}

void	validation_exist(t_tinfo *mapp)
{
	mapp->fd = open (mapp->file_name, O_RDONLY);
	if (mapp->fd < 0)
		ft_error("can not open this file", mapp->file_name);
}