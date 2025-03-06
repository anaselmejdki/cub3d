/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:43:22 by ael-mejd          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/05 02:58:58 by saait-si         ###   ########.fr       */
=======
/*   Updated: 2025/03/05 17:18:05 by ael-mejd         ###   ########.fr       */
>>>>>>> 784c0db4191273817a140ead724abb1fb5871e17
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_data data;
    t_tinfo mapp;
    

    init_data(&data);
    if (validation_extantion(&mapp, ac, av) != 0)
        return (1);
    init_mlx(&data);
    init_textures(&data);
    render_images(&data);
    listen_for_input(&data);
    mlx_loop_hook(data.mlx, render, &data);
    mlx_loop(data.mlx);
    return (0);
}
