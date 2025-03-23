/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 02:39:33 by saait-si          #+#    #+#             */
/*   Updated: 2025/03/23 13:27:38 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

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
			printf(";;;;;;;;;;;%s", line );
			// if (found_digit && isdigit(*(line + 1)))
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

static int	clean_space_around_comma(char *line, char *ptr)
{
	char	*temp;
	int		shift;

	shift = 0;
	if (*ptr == ',')
	{
		if (ptr > line && (*(ptr - 1) == ' ' || *(ptr - 1) == '\t'))
		{
			temp = ptr - 1;
			while (*temp++)
				*temp = *(temp + 1);
			ptr--;
			shift = 1;
		}
		if (*(ptr + 1) == ' ' || *(ptr + 1) == '\t')
		{
			temp = ptr + 1;
			while (*temp++)
				*temp = *(temp + 1);
		}
	}
	return (shift);
}

static void	clean_line(char *line)
{
	char	*ptr;
	char	*temp;
	int		shift;

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
		shift = clean_space_around_comma(line, ptr);
		if (shift)
			continue ;
		ptr++;
	}
}

int	ft_floor(t_parse *parse, char *line)
{
	char	**split;
	int		r;
	int		g;
	int		b;
	int		flag_comma = 0;
	from_new_line_to_ziroo(line);
	if (validate_line_for_spaces(line))
		return (ft_error("🚨 INVALID RGB FORMAT: digit!", line), 1);
	clean_line(line);
	printf("line: %s\n", line);
	int i = -1;
	while (line[++i])
	{
		if (line[i] == ',')
		{
			flag_comma++;
			if (flag_comma > 2)
				return (ft_error("🚨 INVALID RGB FORMAT: Too many commas", line), 1);
		}
	}
	split = ft_split(line, ',');
	if (!split || !split[0] || !split[1] || !split[2])
	{
		return (ft_error("🚨Must be f and c", line), 1);
	}
	printf("line: %s\n", line);
	if (split[3])
		return (ft_error("🚨 INVALID RGB FORMAT! Too many components", line), 1);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	free_mapping(split);
	printf("aloha color: %d, %d, %d\n", r, g, b);

	ft_check_rgb_f(parse, r, g, b);
	return (0);
}
// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_color.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: Sajida-Ait-si-mhand                        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025-03-23 11:55:52 by Sajida-Ait-si-mhand #+#    #+#          */
// /*   Updated: 2025-03-23 11:55:52 by Sajida-Ait-si-mhand ###   ########.fr   */
// /*                                                                            */
// /* ************************************************************************** */

// int	ft_floor(t_parse *parse, char *line)
// {
// 	char	**split;
// 	int		r;
// 	int		g;
// 	int		b;
// 	char	*trimmed_line;
// 	char	identifier;

// 	printf("line: %s\n", line);
// 	from_new_line_to_ziroo(line);
// 	trimmed_line = ft_strtrim(line, " \t");
// 	if (!trimmed_line || ft_strlen(trimmed_line) < 3)
// 		return (free(trimmed_line), ft_error("🚨 INVALID COLOR FORMAT", line), 1);
// 	printf("trimmed_line: %c\n", trimmed_line[0]);
// 	identifier = trimmed_line[0];
// 	if (identifier != 'F' && identifier != 'C')
// 		return (free(trimmed_line), ft_error("🚨 INVALID IDENTIFIER: Must be F or C", line), 1);
	
// 	if (validate_line_for_spaces(trimmed_line + 1))
// 		return (free(trimmed_line), ft_error("🚨 INVALID RGB FORMAT: Invalid spacing!", line), 1);
	
// 	clean_line(trimmed_line + 1); // Skip the identifier
// 	split = ft_split(trimmed_line + 1, ',');
// 	free(trimmed_line);
	
// 	if (!split || !split[0] || !split[1] || !split[2])
// 		return (free_mapping(split), ft_error("🚨 INVALID RGB FORMAT: Missing components", line), 1);
	
// 	if (split[3])
// 		return (free_mapping(split), ft_error("🚨 INVALID RGB FORMAT: Too many components", line), 1);
	
// 	r = ft_atoi(split[0]);
// 	g = ft_atoi(split[1]);
// 	b = ft_atoi(split[2]);
// 	free_mapping(split);
	
// 	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
// 		return (ft_error("🚨 INVALID RGB VALUES: Must be between 0-255", line), 1);
	
// 	printf("Color %c: %d, %d, %d\n", identifier, r, g, b);
	
// 	if (identifier == 'F')
// 	{
// 		parse->floor_color = (r << 16) | (g << 8) | b;
// 		parse->found_floor = true;
// 	}
// 	else // identifier == 'C'
// 	{
// 		parse->ceil_color = (r << 16) | (g << 8) | b;
// 		parse->found_ceil = true;
// 	}
	
// 	return (0);
// }