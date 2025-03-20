#include "../cub3d.h"

void clean_exit(t_data *data, int code)
{
	free_texture(data->mlx, data->texinfo);
	mlx_destroy_image(data->mlx, data->image.img);
	mlx_destroy_window(data->mlx, data->win);
	free_map(data->map);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(code);
}

int quiter(t_data *data)
{
	clean_exit(data, 0);
	return (0);
}

void init_key_flags(t_data *data)
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

int key_press_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		data->keys[CLOSE_FLAG] = 1;
	if (key == XK_Left)
		data->keys[LEFT_FLAG] = 1;
	if (key == XK_Right)
		data->keys[RIGHT_FLAG] = 1;
	if (key == XK_w)
		data->keys[W_FLAG] = 1;
	if (key == XK_a)
		data->keys[A_FLAG] = 1;
	if (key == XK_s)
		data->keys[S_FLAG] = 1;
	if (key == XK_d)
		data->keys[D_FLAG] = 1;
	return (0);
}

int key_release_handler(int key, t_data *data)
{
	if (key == XK_Left)
		data->keys[LEFT_FLAG] = 0;
	if (key == XK_Right)
		data->keys[RIGHT_FLAG] = 0;
	if (key == XK_w)
		data->keys[W_FLAG] = 0;
	if (key == XK_s)
		data->keys[S_FLAG] = 0;
	if (key == XK_d)
		data->keys[D_FLAG] = 0;
	if (key == XK_a)
		data->keys[A_FLAG] = 0;
	return (0);
}

void input_handler(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_press_handler, data);
	mlx_hook(data->win, 3, 1L << 1, key_release_handler, data);
	mlx_hook(data->win, 17, 1L << 17, quiter, data);
}
