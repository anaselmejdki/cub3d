#include "../include/main.h"



void	free_2d_array(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		free(str[i]);
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	free_parser(t_parse *parse)
{
	if (parse->map != NULL)
		free_2d_array(parse->map);
	if (parse->no_text != NULL)
		free(parse->no_text);
	if (parse->so_text != NULL)
		free(parse->so_text);
	if (parse->we_text != NULL)
		free(parse->we_text);
	if (parse->ea_text != NULL)
		free(parse->ea_text);
}