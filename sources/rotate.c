/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 00:00:01 by ael-mejd          #+#    #+#             */
/*   Updated: 2025/03/23 00:00:03 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	radian(float degree)
{
	return (degree * M_PI / 180);
}

void	rotate(t_data *data)
{
	if (!data->keys[RIGHT_FLAG] && !data->keys[LEFT_FLAG])
		return ;
	if (data->keys[RIGHT_FLAG])
	{
		data->player.angle += ANGLE;
		if (data->player.angle >= 360)
			data->player.angle -= 360;
	}
	if (data->keys[LEFT_FLAG])
	{
		data->player.angle -= ANGLE;
		if (data->player.angle < 0)
			data->player.angle += 360;
	}
	data->keys[ROTATE_FLAG] = 1;
}
