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
void ft_check_texture(char *str)
{
	char *ptr;
	char *dup;
	int fd;

	ptr = str;
	if((ptr[0] == 'N' && ptr[1] == 'O') || (ptr[0] == 'S' && ptr[1] == 'O') || (ptr[0] == 'W' && ptr[1] == 'E') || (ptr[0] == 'E' && ptr[1] == 'A'))
	{
		ptr += 2;
		while (*ptr == 32)
			ptr++;
		if(*ptr == '.' || *ptr == '/')
		{
			dup = ft_strdup(ptr);
			int len = ft_strlen(dup);
			if(len > 0 && dup[len - 1] == '\n')	
				dup[len - 1] = '\0';
			if (ft_check_xpm(dup))
				ft_error("check extension .xpm", dup);
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
	else
		ft_error("Texture", str);
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