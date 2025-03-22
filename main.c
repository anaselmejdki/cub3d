#include "cub3d.h"

int	validation_extantion(t_parse *mapp, int ac, char **av)
{
	char	*ptr;

	if (ac != 2)
		ft_error("Incorrect number of arguments!", NULL);
	ptr = ft_strrchr(av[1], '.');
	if (!ptr)
		ft_error("Missing file extension (.cub)!", NULL);
	if (ft_strncmp(ptr, ".cub", ft_strlen(".cub") + 1) != 0)
		ft_error("Invalid extension! Must be .cub", NULL);
	mapp->fd = open(av[1], O_RDONLY);
	if (mapp->fd < 0)
		ft_error("Failed to open file!", NULL);
	mapp->file_name = av[1];
	return (1);
}
static bool	check_empty_gaps(t_parse *parse)
{
	int	i;
	int	j;

	i = -1;
	while (parse->map[++i])
	{
		j = -1;
		while (parse->map[i][++j])
		{
			if (parse->map[i][j] == '0')
			{
				if (i == 0 || j == 0 || i == parse->map_height - 1
					|| j >= (int)ft_strlen(parse->map[i]) - 1
					|| ft_isspace(parse->map[i - 1][j])
					|| ft_isspace(parse->map[i + 1][j])
					|| ft_isspace(parse->map[i][j - 1])
					|| ft_isspace(parse->map[i][j + 1]) || parse->map[i
					- 1][j] == '\0' || parse->map[i + 1][j] == '\0'
					|| parse->map[i][j - 1] == '\0' || parse->map[i][j
					+ 1] == '\0' || parse->map[i - 1][j] == ' ' || parse->map[i
					+ 1][j] == ' ' || parse->map[i][j - 1] == ' '
					|| parse->map[i][j + 1] == ' ')
				{
					return (ft_error("Map error: '0' is not properly surrounded by '1's!",
							NULL), false);
				}
			}
		}
	}
	return (true);
}
int	main(int ac, char **av)
{
	t_parse	parse;

	ft_memset(&parse, 0, sizeof(t_parse));
	parse.floor_color = -1;
	parse.ceil_color = -1;
	parse.valid_set = "01NEWS";
	validation_extantion(&parse, ac, av);
	if (ft_parse(&parse))
		return (free_parser(&parse), EXIT_FAILURE);
	if (!check_empty_gaps(&parse))
		return (free_parser(&parse), EXIT_FAILURE);
	merge(&parse); // sojod
	return (0);
}
