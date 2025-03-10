#include "../cub3d.h"

void init_textures(t_data *data, t_tinfo *info)
{
    int i;

    i = 0;
    while (i < 4)
    {
        data->texinfo[i].img = mlx_xpm_file_to_image(data->mlx, info->text_path[i], &data->texinfo[i].width, &data->texinfo[i].hight);
        data->texinfo[i].iter = mlx_get_data_addr(data->texinfo[i].img, &data->texinfo[i].pixel_bits, &data->texinfo[i].line_length, &data->texinfo[i].endianess);
        i++;
    }
}

