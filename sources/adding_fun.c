/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:15:24 by saait-si          #+#    #+#             */
/*   Updated: 2025/03/24 00:10:16 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float normalize_angle(float angle)
{
    while (angle < 0)
        angle += 360;
    while (angle >= 360)
        angle -= 360;
    return angle;
}

void	clean_exit(t_data *data, int code)
{
	int	i;
	i = 0;
    while (i < 4)
    {
        if (data->parse->tex_path[i])
            free(data->parse->tex_path[i]);
        i++;
    }
	free(data->parse);
    data->parse = NULL;
	free_texture(data->mlx, data->texinfo);
	mlx_destroy_image(data->mlx, data->image.img);
	mlx_destroy_window(data->mlx, data->win);
	free_map(data->map);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(code);
}

int	quiter(t_data *data)
{
	clean_exit(data, 0);
	return (0);
}
