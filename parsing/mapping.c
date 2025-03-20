#include "../parsing.h"

char	**ft_read_map(t_tinfo *mapp)
{
	char	**temp;
	char	*line;
	int		i;
	int  	map_start;

	i = 0;
	map_start = 0;
	mapp->hieght = ft_count_height_map(mapp);
	mapp->fd = open(mapp->file_name, O_RDONLY);
	temp = malloc((mapp->hieght + 1) * sizeof(char *));
	if (!temp)
		return (NULL);
	while ((line = get_next_line(mapp->fd)))
	{
		char *ptr = line;
		while (*ptr == ' ')
			ptr++;
		
		if ((ptr[0] == '1' || ptr[0] == '0' )&& !map_start )
			map_start = 1;

		if (map_start)
		{
			if (*ptr == '\n' || *ptr == '\0') 
				ft_error("Check the map", NULL);
			// printf("\033[0;33m%s\033[0m", ptr);;
			temp[i] = ft_strdup(line);
			i++;
		}
		free(line);
	}
	temp[i] = NULL;
	mapp->width = i;
	// printf("========>%d", mapp->width);
	return (temp);
}
