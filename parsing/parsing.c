#include "../parsing.h"

int check_exetation(char *filename)
{
	int len = ft_strlen(filename);
	return (len > 4 && ft_strncmp(filename + len - 4, ".cub", 4) == 0);
}
int main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("argument error");
		return 1;
	}
	if (!check_exetation(av[1]))
	{
		printf("error extension. Must be .cub\n");
		return 1;
	}
	return 0;
}