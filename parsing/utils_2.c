#include "../parsing.h"

void ft_error(char *str, char *arg)
{
	printf("Error: %s", str);
	if (arg)
		printf(": %s", arg);
	exit(1);
}

int ft_check_xpm(char *str)
{
	int i = ft_strlen(str);
	return (i > 4 && ft_strncmp(str + i - 4, ".xpm", 4));
}

int ft_check_cub(char *filename)
{
	int len = ft_strlen(filename);
	return (len > 4 && ft_strncmp(filename + len - 4, ".cub", 4) == 0);
}

void	ft_check_new_line(char *str)
{
	char *ptr;

	ptr = str;
	if (ft_strncmp(ptr ,"\n", 1) == 0)
		return ;
	else 
		ft_error("you need new line, instead of", str);
	return ;
}