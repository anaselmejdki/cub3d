#include "../parsing.h"

void ft_error(char *str, char *arg)
{
	printf("Error: %s", str);
	if (arg)
		printf(": %s", arg);
	exit(1);
}

void ft_check_texture(char *str)
{
	char *ptr;
	char *dup;
	int fd;

	ptr = str;
	if(ptr[0] == 'N' && ptr[1] == 'O')
	{
		ptr += 2;
		while (*ptr == 32)
			ptr++;
		if(*ptr == '.')
		{
			dup = ft_strdup(ptr);
			fd = open (dup, O_RDONLY);
			if(fd < 0)
			{
				ft_error("File does not exist", dup);
				free(dup);
			}
			close (fd);
			free(dup);
		}
		else 
			ft_error("Path is  not existed!", NULL);
	}
}

void reading_map(int fd)
{
	char *temp;
	int i = 0;
	while ((temp = get_next_line(fd)))
	{
		ft_check_texture(temp);
			i++;
		free(temp);
	}
	printf("------->%d",i);
	
	return ;
}