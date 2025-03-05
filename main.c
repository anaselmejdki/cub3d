/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:43:22 by ael-mejd          #+#    #+#             */
/*   Updated: 2025/03/05 17:18:05 by ael-mejd         ###   ########.fr       */
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