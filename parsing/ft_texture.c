#include "../parsing.h"

void ft_store_texture(t_tinfo *mapp,t_texture *tex, char *line)
{
	(void)mapp;
    char **split = ft_split(line, ' ');
    if (!split || !split[0] || !split[1])
    {
        ft_error("🚨 INVALID TEXTURE LINE!", line);
        return;
    }

    if (!strcmp(split[0], "NO")) tex->no = ft_strdup(split[1]);
    else if (!strcmp(split[0], "SO")) tex->so = ft_strdup(split[1]);
    else if (!strcmp(split[0], "WE")) tex->we = ft_strdup(split[1]);
    else if (!strcmp(split[0], "EA")) tex->ea = ft_strdup(split[1]);
    else if (!strcmp(split[0], "F") || !strcmp(split[0], "C"))
    {
        char **rgb = ft_split(split[1], ','); 
        if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
            ft_error("🚨 INVALID COLOR FORMAT!", line);

        int r = ft_atoi(rgb[0]);
        int g = ft_atoi(rgb[1]);
        int b = ft_atoi(rgb[2]);

        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
            ft_error("🚨 COLOR VALUE OUT OF RANGE (0-255)!", line);

        if (!strcmp(split[0], "F")) 
        {
            tex->f[0] = r;
            tex->f[1] = g;
            tex->f[2] = b;
        }
        else 
        {
            tex->c[0] = r;
            tex->c[1] = g;
            tex->c[2] = b;
        }
        free(rgb);
    }
    free(split);
}

void ft_parse_textures(t_tinfo *mapp, t_texture *tex)
{
    char *line;
    int i = 0;

    while (i < 6 && (line = get_next_line(mapp->fd)))
    {
        if (*line != '\n')
        {
            ft_store_texture(mapp, tex, line);
            i++;
        }
        free(line);
    }
}
