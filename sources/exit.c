/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:59:49 by ael-mejd          #+#    #+#             */
/*   Updated: 2025/03/05 15:59:59 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    clean_exit(t_data *data, int flag)
{
    if (!data)
        exit(flag);
    if (data->win && data->mlx)
        mlx_destroy_window(data->mlx, data->win);
    if (data->mlx)
    {
        mlx_destroy_display(data->mlx);
        mlx_loop_end(data->mlx);
        free(data->mlx);
    }
    free_data(data);
    exit(flag);
}

int quiter(t_data *data)
{
    clean_exit(data, 0);
    return (0);
}
