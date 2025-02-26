#include "../parsing.h"



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
		ft_error("Not textures!!!", str);
}
void ft_check_rgb_rang(char *str)
{
	int red = ft_atoi(str);
	printf("red:\033[1;35m%d\033[0m", red);
	printf("str:\033[1;35m%s\033[0m", str);
}
void ft_check_rgb(char *str)
{
	char *ptr = str;
	char *dup;
	

	if (ptr[0] == 'F' || ptr[0] == 'C')
	{
		dup = ft_strdup(ptr);
		// printf("%s", dup);
		ft_check_rgb_rang(dup);
	}

	return ;
}

void reading_map(int fd)
{
	char *temp;
	int i = 0;
	while ((temp = get_next_line(fd)))
	{
		printf("i = %d, str:%s", i, temp);
		if (i <= 3)
			ft_check_texture(temp);
		if (i == 4 && ft_check_new_line(temp) == 1)
			ft_error("you need new line, instead of", temp);

		// if(i == 5 && ft_check_new_line(temp) == 1)
		// 	printf("Hayed dik nwe line achrifa");
		// if(i == 5 || i == 6)
		// 	ft_check_rgb(temp);
		// else
		// 	printf("==>\033[1;35m%s\033[0m", temp);
		i++;
		free(temp);
	}
	return ;
}