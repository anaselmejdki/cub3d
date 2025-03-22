#include "../include/main.h"

static void from_new_line_to_ziroo(char *line)
{
	size_t len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n') {
		line[len - 1] = '\0'; 
	}
}

char	**duplicate_map(t_parse *parse,char **map, int *height)
{
	char	**new;
	int		i;

	if (*height <= 0 || !map)
		return (NULL);
	new = ft_calloc(*height + 1, sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	while (map[++i])
		new[i] = ft_strdup(map[i]);
	i = *height - 1;
	while (i >= 0 && is_empty_line(new[i]))
	{
		free(new[i]);
		free(map[i]);
		map[i] = NULL;
		new[i] = NULL;
		(*height)--;
		i--;
	}
	parse->map_height = *height;
	return (new);
}

char	**ft_read_map(char **arr, char *new, int *size)
{
	char	**new_arr;
	int		i;

	new_arr = malloc(sizeof(char *) * (*size + 2));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (i < *size)
	{
		// printf("arr[%d]: %s\n", i, arr[i]);
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[i] = ft_strdup(new);
	new_arr[i + 1] = NULL;
	*size += 1;
	free(arr);
	return (new_arr);
}

int	check_valid_map_chars(char *line, char *valid_chars)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(valid_chars, line[i]) && !ft_isspace(line[i]))
			return (ft_error( "Invalid character in map", &line[i]),1);
		i++;
	}
	return (0);
}

int	get_map_line(t_parse *parse, char *line)
{
	from_new_line_to_ziroo(line);
	// if (line[ft_strlen(line) - 1] == '\n') // this is not needed
	// 	line[ft_strlen(line) - 1] = '\0';
	if (check_valid_map_chars(line, parse->valid_set) == 1)
		return (1);
	parse->map = ft_read_map(parse->map, line, &parse->map_height);
	if (!parse->map)
		return (ft_error("Could not allocate memory", NULL),1);
	parse->found_map = true;
	return (0);
}
