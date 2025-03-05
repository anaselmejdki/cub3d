#include "../parsing.h"

void ft_error(char *str, char *arg)
{
	printf("\033[0;31m Error: %s \033[0m", str);
	if (arg)
		printf(":\033[38;5;121m %s \033[0m", arg);
	exit(1);
}

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

int ft_height(t_tinfo *mapp)
{
	int i;

	i = 0;
	while (mapp->dbl_ptr[i])
		i++;
	mapp->hieght = i;
	return (mapp->hieght);
}

void ft_check_map_borders(char **map, int height)
{
    int i;
    int width;
    int first_index;
	int last_index;
	
    i = 0;
    while (i < height)
    {
        width = ft_strlen(map[i]); 
        first_index = 0;
        last_index = width - 1;

        while (map[i][first_index] == ' ')
            first_index++;

        while (map[i][last_index] == ' ' || map[i][last_index] == '\n')
            last_index--;

        if (map[i][first_index] != '1' || map[i][last_index] != '1')
            ft_error(" MAP BORDER : First or last non-space column must be 1!", map[i]);
        i++;
    }
    printf("✅ MAP BORDERS ARE VALID!\n");
}
