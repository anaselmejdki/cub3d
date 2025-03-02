#include "../parsing.h"

//	🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥
// int check_name_dot(char *filename)
// {
// 	if (ft_strncmp(&filename[0],".", 1) == 0)
// 	{
// 		return 1;
// 	}
// 	return 0;
// }
//	🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥
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
// char **ft_read_map(t_tinfo *mapp)
// {
// 	char **temp;
// 	char  *line;
// 	int i = 0;
// 	mapp->hieght  = ft_count_height_map(mapp);
// 	mapp->fd = open(mapp->file_name, O_RDONLY);
// 	line = get_next_line(mapp->fd);
	
// 	temp = malloc(sizeof(char *) * (mapp->hieght + 1));
// 	if (!temp)
// 	return (NULL);
// 	while (line)
// 	{
// 		printf("\033[0;31m%s\033[0m", line);
// 		//checl the first line if is it a new line
// 		printf("line:%d:: %s", i, temp[i]);
// 		temp[i] = strdup(line);
// 		i++;
// 		free(line);
// 		line = get_next_line(mapp->fd);
// 	}	
// 	temp[i] = NULL;
// 	return temp;
// }
char	**ft_read_map(t_tinfo *mapp)
{
	char	**temp;
	char	*line;
	int		i;

	mapp->hieght = ft_count_height_map(mapp);
	mapp->fd = open(mapp->file_name, O_RDONLY);
	line = get_next_line(mapp->fd);
	i = 0;
	temp = malloc((mapp->hieght + 1) * sizeof(char *));
	if (!temp)
		return (NULL);
	while (line)
	{
		// printf("\033[0;31m%s\033[0m", line);
		// printf("\033[0;31m%s\033[0m", temp[i]);

		// if (line[0] == '\n')
		// 	ft_error("🐸 Your map contains an empty line 🐸\n", NULL);
		temp[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(mapp->fd);
	}
	temp[i] = NULL;
	return (temp);
}
int main(int ac, char *av[])
{
	t_tinfo mapp;
	validation_extantion(&mapp, ac, av);
	validation_exist(&mapp);
	mapp.dbl_ptr = ft_read_map(&mapp);
	int i = 0;
	int x = 0;
	while (mapp.dbl_ptr[i])
	{
		printf(":::%s", mapp.dbl_ptr[i]);
		i++;
	}
	
	// // reading_map(fd);
	// close (fd);
	return 0;
}