/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:39:33 by saait-si          #+#    #+#             */
/*   Updated: 2025/03/23 21:37:27 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static int	validate_line_for_spaces(const char *line)
{
	int	in_number;
	int	i;

	i = 0;
	in_number = 0;
	while (line[i] && (line[i] == 'F' || line[i] == 'C' || 
			line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line[i])
	{
		if (isdigit(line[i]))
		{
			in_number = 1;
		}
		else if (line[i] == ' ' || line[i] == '\t')
		{
			int j = i + 1;
			while (line[j] && (line[j] == ' ' || line[j] == '\t'))
				j++;
			if (in_number && line[j] && isdigit(line[j]))
				return (1);
		}
		else if (line[i] == ',')
			in_number = 0; 
		else
			return (1);
		i++;
	}
	return (0);
}

static void ft_check_comma(char *line,  t_parse *parse)
{
	int i = 0;
	parse->comma_count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			parse->comma_count++;
		if (parse->comma_count > 2)
			ft_error(parse, "Must have exactly two commas", line);
		i++;
	}
}

void ft_put_rgb(int r, int g, int b, t_parse *parse)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error(parse, "🚨 INVALID RGB VALUES: Must be between 0-255", NULL);
	
	if (parse->identifier == 'F' && ft_strncmp(&parse->identifier, "F", 1) == 0)
	{
		parse->floor_color = (r << 16) | (g << 8) | b;
		printf("Floor color: %d, %d, %d\n", r, g, b);
	}
	else if (parse->identifier == 'C' && ft_strncmp(&parse->identifier, "C",1) == 0)
	{
		parse->ceil_color = (r << 16) | (g << 8) | b;
		printf("Floor color: %d, %d, %d\n", r, g, b);
	}
}
int	ft_color(t_parse *parse, char *line)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	from_new_line_to_ziroo(line);
	
	char *ptr = line;
	while (*ptr && (*ptr == ' ' || *ptr == '\t'))
		ptr++;
		
	parse->identifier = *ptr;
	
	if (validate_line_for_spaces(line))
		return (ft_error(parse, "🚨 INVALID RGB FORMAT: No spaces within numbers", line), 1);
	ft_check_comma(line, parse);
	
	split = ft_split(ptr, ',');
	if (!split || !split[0] || !split[1] || !split[2])
		return (free_mapping(split), ft_error(parse,"🚨 INVALID RGB FORMAT: Missing components", line), 1);
	
	if (split[3])
		return (free_mapping(split), ft_error(parse, "🚨 INVALID RGB FORMAT: Too many components", line), 1);
	
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	free_mapping(split);
	ft_put_rgb(r, g, b, parse);
	return (0);
}
