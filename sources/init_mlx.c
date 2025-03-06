/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:37:04 by ael-mejd          #+#    #+#             */
/*   Updated: 2025/03/05 16:08:21 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    init_img(t_data *data, t_img *image, int width, int height)
{
    init_img_clean(image);
    image->img = mlx_new_image(data->mlx, width, height);
    if (image->img == NULL)
        clean_exit(data, err_msg("mlx", "Could not create mlx image", 1));
    image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits, &image->size_line, &image->endian);
    return;
}

void    init_texture_img(t_data *data, t_img *image, char *path)
{
    init_img_clean(image);
    printf("Initialization data : %s\n", path);
    image->img = mlx_xpm_file_to_image(data->mlx, path, &data->texinfo.size, &data->texinfo.size);
    if (image->img == NULL)
        clean_exit(data, err_msg("mlx", "Could not create mlx image", 1));
    printf("hna\n");
    image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits, &image->size_line, &image->endian);
    return;
}

void    init_mlx(t_data *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
        clean_exit(data, err_msg("mlx", "Could not start mlx", 1));
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
    if (!data->win)
        clean_exit(data, err_msg("mlx", "Could not create mlx window", 1));
    return ;   
}