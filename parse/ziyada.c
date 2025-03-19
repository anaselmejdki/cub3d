#include "../include/main.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\b');
}

void ft_error(char *str, char *arg)
{
	printf("\033[0;31m Error: %s \033[0m", str);
	if (arg)
		printf(":\033[38;5;121m %s \033[0m", arg);
	exit(1);
}
bool	ft_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] != ' ' && !(line[i] >= 9 && line[i] <= 13))
			return (false);
		i++;
	}
	return (true);
}