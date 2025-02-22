#include "../parsing.h"

void ft_error(char *str, char *arg)
{
	printf("Error:%s", str);
	if (arg)
		printf(":%s", arg);
	exit(1);
}