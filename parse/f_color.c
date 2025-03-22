
#include "../include/main.h"

static void	from_new_line_to_ziroo(char *line)
{
	size_t	len;

	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
	}
}

static int	validate_line_for_spaces(const char *line)
{
	int	found_digit;

	found_digit = 0;
	while (*line)
	{
		if (isdigit(*line))
		{
			found_digit = 1;
		}
		else if (*line == ' ' || *line == '\t')
		{
			if (found_digit && isdigit(*(line + 1)))
			{
				return (1);
			}
		}
		else
		{
			found_digit = 0;
		}
		line++;
	}
	return (0);
}

static void	clean_line(char *line)
{
	char	*ptr;
	char	*temp;
	char	*temp;
	char	*temp;

	ptr = line;
	while (*ptr)
	{
		if (*ptr == ' ' || *ptr == '\t')
		{
			temp = ptr;
			while (*temp)
			{
				*temp = *(temp + 1);
				temp++;
			}
			continue ;
		}
		if (*ptr == ',')
		{
			if (ptr > line && (*(ptr - 1) == ' ' || *(ptr - 1) == '\t'))
			{
				temp = ptr - 1;
				while (*temp)
				{
					*temp = *(temp + 1);
					temp++;
				}
				ptr--;
			}
			if (*(ptr + 1) == ' ' || *(ptr + 1) == '\t')
			{
				temp = ptr + 1;
				while (*temp)
				{
					*temp = *(temp + 1);
					temp++;
				}
			}
		}
		ptr++;
	}
}

int	ft_floor(t_parse *parse, char *line)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	from_new_line_to_ziroo(line);
	if (validate_line_for_spaces(line))
		return (ft_error("🚨 INVALID RGB FORMAT! Spaces between digits are not allowed",
				line), 1);
	clean_line(line);
	split = ft_split(line, ',');
	if (!split || !split[0] || !split[1] || !split[2])
	{
		return (ft_error("🚨 INVALID COLOR IDENTIFIER! Must be 'F' or 'C'",
				line), 1);
	}
	if (split[3])
		return (ft_error("🚨 INVALID RGB FORMAT! Too many components", line), 1);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ft_error("🚨 RGB values must be between 0 and 255", line), 1);
	free_mapping(split);
	parse->floor_color = (r << 16 | g << 8 | b);
	return (0);
}
