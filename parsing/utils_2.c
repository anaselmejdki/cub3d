#include "../parsing.h"

// void ft_error(char *str, char *arg)
// {
// 	printf("\033[0;31m Error: %s \033[0m", str);
// 	if (arg)
// 		printf(":\033[38;5;121m %s \033[0m", arg);
// 	exit(1);
// }

int ft_check_xpm(char *str)
{
	int i = ft_strlen(str);
	return (i > 4 && ft_strncmp(str + i - 4, ".xpm", 4));
}

int	ft_check_new_line(char *str)
{
	char *ptr;

	ptr = str;
	if (ft_strncmp(ptr ,"\n", 1) == 0)
		return 0;
	return 1;
}

int ft_count_height_map(t_tinfo *mapp)
{
	char* line = get_next_line(mapp->fd);
	int i = 0;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(mapp->fd);
	}
	return (i);
}