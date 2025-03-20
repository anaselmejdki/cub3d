#include "../cub3d.h"

void free_texture(void *mlx, t_texture *texture)
{
    int i;

    i = 0;
    while (i < 4)
    {
        mlx_destroy_image(mlx, texture[i].img);
        i++;
    }
}

void    free_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        map[i] = NULL;
        i++;
    }
    free(map);
    map = NULL;
}
