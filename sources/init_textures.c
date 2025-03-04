/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:31:12 by ael-mejd          #+#    #+#             */
/*   Updated: 2025/03/03 15:39:14 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int *xpm_to_img(t_data *data, char *path)
{
    t_img image;
    int *buffer;
    int x;
    int y;

    y = 0;
    init_texture_img(data, &image, path);
    buffer = ft_calloc(1, sizeof * buffer * data->texinfo.size * data->texinfo.size);
    if (!buffer)
        clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
    while (y < data->texinfo.size)
    {
        x = 0;
        while (x < data->texinfo.size)
        {
            buffer[y * data->texinfo.size + x] = image.addr[y * data->texinfo.size + x];
            x++;
        }
        y++;
    }
    mlx_destroy_image(data->mlx, image.img);
    return (buffer);
}

void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
	data->textures[NORTH] = xpm_to_img(data, data->texinfo.north);
	data->textures[SOUTH] = xpm_to_img(data, data->texinfo.south);
	data->textures[EAST] = xpm_to_img(data, data->texinfo.east);
	data->textures[WEST] = xpm_to_img(data, data->texinfo.west);
}

void	init_texinfo(t_texinfo *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = 0;
	textures->ceiling = 0;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = 64;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x = 0;
	textures->y = 0;
}
