#include "../cub3d.h"

int	check_keys(t_data *data)
{
	if (data->keys[ROTATE_FLAG] && data->keys[MOVE_FLAG] && data->keys[CLOSE_FLAG])
		return (0);
	return (1);
}

// void init_keys(t_data *data)
// {
//     data->keys[RIGHT_FLAG] = 0;
//     data->keys[LEFT_FLAG] = 0;
//     data->keys[W_FLAG] = 0;
//     data->keys[S_FLAG] = 0;
//     data->keys[D_FLAG] = 0;
//     data->keys[A_FLAG] = 0;
//     data->keys[CLOSE_FLAG] = 0;
//     data->keys[ROTATE_FLAG] = 0;
//     data->keys[MOVE_FLAG] = 0;

// }

int render(t_data *data)
{
    // init_keys(data);
    if (!data->keys[CLOSE_FLAG])
        quiter(data);
    rotate(data);
    move_player(data);
    if (!check_keys(data))
        return (0);
    raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
    data->keys[ROTATE_FLAG] = 0;
	data->keys[MOVE_FLAG] = 0;
	return (0);
}
