#include "../cub3d.h"

void	init_key_flags(t_data *data)
{
	data->keys[RIGHT_FLAG] = 0;
	data->keys[LEFT_FLAG] = 0;
	data->keys[W_FLAG] = 0;
	data->keys[S_FLAG] = 0;
	data->keys[D_FLAG] = 0;
	data->keys[A_FLAG] = 0;
	data->keys[CLOSE_FLAG] = 0;
	data->keys[ROTATE_FLAG] = 0;
	data->keys[MOVE_FLAG] = 0;
}

int	key_press_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		quiter(data);
	if (key == XK_Left)
		data->keys[LEFT_FLAG] = 1;
	if (key == XK_Right)
		data->keys[RIGHT_FLAG] = 1;
	if (key == XK_w)
		data->keys[W_FLAG] = 1
	if (key == XK_a)
		data->keys[A_FLAG] = 1;
	if (key == XK_s)
		data->keys[S_FLAG] = 1;
	if (key == XK_d)
		data->keys[D_FLAG] = 1
	return (0);
}

static int	key_release_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		quitter(data);
	if (key == XK_left)
		data->keys[LEFT_FLAG] = false;
	if (key == XK_w)
		data->keys[W_FLAG] = false;
	if (key == XK_s)
		data->keys[S_FLAG] = false;
	if (key == XK_d)
		data->keys[D_FLAG] = false;
	if (key == XK_a)
		data->keys[A_FLAG] = false;
	return (0);
}

void	input_handler(t_data *data)
{
	mlx_hook(data->win, ClientMessage, NoEventMask, quitter, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release_handler, data);
}