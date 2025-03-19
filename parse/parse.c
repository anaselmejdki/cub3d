#include "../include/main.h"


static int	handle_pre_map_content(t_parse *parse, char *line)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
		return (parse_textures(parse, line));
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (parse_colors(parse, line));
	else if (parse->floor_color != -1 && parse->ceil_color != -1
		&& ft_strchr("01NSWE \t\r", *line))
		return (get_map_line(parse, line));
	else
		return (print_err(NULL, "Invalid T, C, or M", 1), 1);
	return (0);
}

int	handle_line(t_parse *parse, char *line)
{
	bool	line_empty;

	line_empty = ft_empty_line(line);
	if (line_empty == false)
	{
		if (handle_pre_map_content(parse, line) == 1)
			return (close(parse->fd), free(line), 1);
	}
	else if (parse->found_map)
	{
		if (get_map_line(parse, line) == 1)
			return (close(parse->fd), free(line), 1);
	}
	return (0);
}

int	ft_parse(t_parse *parse)
{
	char	*line;

	
	line = get_next_line(parse->fd);
	while (line)
	{
		if (handle_line(parse, line) == 1)
			return (get_next_line(parse->fd), 1);
		(void)(free(line), line = get_next_line(parse->fd));
		// printf("%s", line);
	}
	if (validate_and_close(parse) == 1)
		return (1);
	return (0);
}