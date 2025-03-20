#include "../cub3d.h"

float get_distance(t_data *data, float x, float y)
{
    return (sqrt(pow((data->player.pos_x - x), 2) + pow((data->player.pos_y - y), 2)));
}

float calculate_delta_y(t_data *data, float *horizontal_x, float *horizontal_y, float rayangle)
{
    float delta_y;

    if (rayangle > 180)
    {
        if (*horizontal_x == data->player.pos_x && *horizontal_y == data->player.pos_y)
        {
            delta_y = *horizontal_y - (((int)(*horizontal_y / TILE_SIZE)) * (TILE_SIZE));
            if (delta_y == 0)
                delta_y = TILE_SIZE;
        }
        else
            delta_y = TILE_SIZE;
    }
    else
    {
        if (*horizontal_x == data->player.pos_x && *horizontal_y == data->player.pos_y)
            delta_y = (*horizontal_y) - (((int)((*horizontal_y) / TILE_SIZE) + 1) * TILE_SIZE);
        else
            delta_y = -TILE_SIZE;
    }
    return (delta_y);
}

void find_horizontal_point(t_data *data, float rayangle, float *horizontal_x, float *horizontal_y)
{
    float delta_x;
    float delta_y;

    if (rayangle == 0 || rayangle == 180)
        return;
    delta_y = calculate_delta_y(data, horizontal_x, horizontal_y, rayangle);
    delta_x = delta_y / tan(radian(rayangle));
    *horizontal_x = *horizontal_x - delta_x;
    *horizontal_y = *horizontal_y - delta_y;
}

static int check_next_position(t_data *data, t_ray *ray, int *x, int *y)
{
    float check_y;

    // if (data->debug == 2) {
    //     // printf("y: %d || x: %d\n", *y, *x);
    //     // printf("hieght: %d || len: %d\n", data->map_height, (int)ft_strlen(data->map[*y]));exit(0);
    //     printf("RA: %f || hieght: %d || wid: %d\n", ray->rayangle, data->map_height, data->map_width);
    //     exit(0);
    // }
    if (ray->rayangle == 0 || ray->rayangle == 180 || ray->horizontal_y > data->map_height || ray->horizontal_y < 0 || ray->horizontal_x > data->map_width || ray->horizontal_x < 0)
        return (1);
    // printf("==> hna\n");exit(0);
    check_y = ray->horizontal_y;
    if (ray->horizontal_y < data->player.pos_y)
        check_y -= 1;
    // printf("check y: %f\n", check_y);exit(0);
    *x = ray->horizontal_x / TILE_SIZE;
    *y = check_y / TILE_SIZE;
    if ((*y < data->map_height && *y >= 0) && (*x >= 0 && *x < (int)ft_strlen(data->map[*y])))
    {
        if (data->map[*y][*x] == ' ')
            return (1);
    }
    else
        return (1);
    // printf("0000000000\n");
    return (0);
}

void horizontal(t_data *data, t_ray *ray, float rayangle)
{
    int x;
    int y;

    ray->horizontal_y = data->player.pos_y;
    ray->horizontal_x = data->player.pos_x;
    ray->horizontal_distance = -1.0;
    while (1)
    {
        data->debug++;
        find_horizontal_point(data, rayangle, &ray->horizontal_x, &ray->horizontal_y);
        // printf("Hx: %f || Hy: %f || Hd: %f\n", ray->horizontal_x, ray->horizontal_y, ray->horizontal_distance);
        // if (data->debug == 2)
        //     exit(0);
        // exit(0);
        if (check_next_position(data, ray, &x, &y)) {
            // printf("debug ==> %d\n", data->debug);
            // printf("here\n");
            break; 
        }
        if (data->map[y][x] == '1')
        {
            ray->horizontal_distance = get_distance(data, ray->horizontal_x, ray->horizontal_y);
            // printf("ray horiz dis is %f\n", ray->horizontal_distance);
            break;
        }
    }
    // printf("Hx: %f || Hy: %f || Hd: %f\n", data->ray.horizontal_x, data->ray.horizontal_y, data->ray.horizontal_distance);
    // exit(0);
}
