/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:14:23 by saait-si          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/23 21:36:43 by ael-mejd         ###   ########.fr       */
=======
/*   Updated: 2025/03/23 14:59:50 by saait-si         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../get_next_line/get_next_line.h"
# include "color.h"
# include "../include/new.h"
# include "../libft/libft.h"
# include <ctype.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int		ft_isspace(int c);
int	    ft_error(t_parse *parse, char *str, char *arg);
bool	is_empty_line(char *line);
int		ft_color(t_parse *parse, char *line);
void	calculate_map_width(t_parse *parse, char **map);
void	ft_check_rgb_f(t_parse *parse, int r, int g, int b);
void	ft_check_rgb_c(t_parse *parse, int r, int g, int b);
void	from_new_line_to_ziroo(char *line);
void	free_parser(t_parse **parse);
#endif