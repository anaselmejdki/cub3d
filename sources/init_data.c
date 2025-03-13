#include "../cub3d.h"

void    player_first_cordinate(t_data *data)
{
    int x;
    int y;

    y = 0;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (ft_strchr("NSEW", data->map[y][x]))
            {
                data->player.pos_x = (x * TILE_SIZE + TILE_SIZE / 2);
                data->player.pos_y = (y * TILE_SIZE + TILE_SIZE / 2);
                return ;
            }
            x++;
        }
        y++;
    }
}

void init_data(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
    data->image.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bpp, &data->image.size_line, &data->image.endian);
    data->width = data->map_width * TILE_SIZE;
    data->height = data->map_height * TILE_SIZE;
    player_first_cordinate(data);
    data->player.fov = FOV;
    data->player.distance_to_project_plan = ((float)WIDTH / 2) / tan(radian(data->player.fov / 2));
}

void	first_view(t_data *data)
{
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
}

void merge(t_tinfo *info, t_textura *tex)
{
    t_data data;

    data.map = info->dbl_ptr;
    data.ceilieng_color[0] = tex->c[0];
    data.ceilieng_color[1] = tex->c[1];
    data.ceilieng_color[2] = tex->c[2];
    data.floor_color[0] = tex->f[0];
    data.floor_color[1] = tex->f[1];
    data.floor_color[2] = tex->f[2];
    data.height = info->hieght;
    data.width = info->width;
    data.player.angle = -1;
    data.player.angle_step = ((float)(FOV) / (float)WIDTH);
    init_data(&data);
    init_textures(&data, info);
    info->dbl_ptr = NULL;
    input_handler(&data);
	first_view(&data);
	// // mlx_loop_hook(data.mlx, render, &data);
    mlx_loop(data.mlx);
}
