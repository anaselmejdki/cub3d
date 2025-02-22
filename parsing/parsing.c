#include "../parsing.h"

int check_exetation(char *filename)
{
	int len = ft_strlen(filename);
	return (len > 4 && ft_strncmp(filename + len - 4, ".cub", 4) == 0);
}
int check_name_dot(char *filename)
{
	if (ft_strncmp(&filename[0],".", 1) == 0)
	{
		// printf("FIHA DOT");
		return 1;
	}
	return 0;
}
int main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("argument error");
		return 1;
	}
	if (!check_exetation(av[1]) || check_name_dot(av[1]))
	{
		printf("error extension. Must be .cub\n");
		return 1;
	}
	int fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("ERROR can not open this file:%s", av[1]);
		return 1;
	}
	close (fd);
	printf("The file is exist:%s", av[1]);
	return 0;
}