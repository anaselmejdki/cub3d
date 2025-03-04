/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:06:51 by ael-mejd          #+#    #+#             */
/*   Updated: 2025/03/03 15:34:22 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    free_tab(void **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    if (tab)
    {
        free(tab);
        tab = NULL;
    }
}

void    free_map(t_data *data)
{
    if (data->mapinfo.fd > 0)
        close(data->mapinfo.fd);
    if (data->mapinfo.file)
        free_tab((void **)data->mapinfo.file);
    if (data->map)
        free_tab((void **)data->map);
}

void	free_texinfo(t_texinfo *textures)
{
	if (textures->north)
		free(textures->north);
	if (textures->south)
		free(textures->south);
	if (textures->west)
		free(textures->west);
	if (textures->east)
		free(textures->east);
	if (textures->floor)
		free(textures->floor);
	if (textures->ceiling)
		free(textures->ceiling);
}

int free_data(t_data *data)
{
    if (data->textures)
    {
        free_tab((void **)data->textures);
    }
    if (data->texture_pixels)
    {
        free_tab((void **)data->texture_pixels);
    }
    free_texinfo(&data->texinfo);
    free_map(data);
    return (1);
}
