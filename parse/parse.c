#include "../include/main.h"


static int handle_pre_map_content(t_parse *parse, char *line)
{
    while (*line == ' ' || *line == '\t')
        line++;
    
     if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0 ||
        ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
        return parse_textures(parse, line);
    if (ft_strncmp(line,"C", 1) == 0)
        return ft_floor(parse, line + 1);
    if (ft_strncmp(line,"F", 1) == 0 )
         return ft_ceil(parse, line + 1);
    if (parse->floor_color != -1 && parse->ceil_color != -1 && ft_strchr("01NSWE \t\r", *line))
        return get_map_line(parse, line);
    return print_err(NULL, "Invalid configuration", 1), 1;
}


static int handle_line(t_parse *parse, char *line)
{
    if (!parse->found_map && !is_empty_line(line))
    {
        if (handle_pre_map_content(parse, line))
            return close(parse->fd), free(line), 1;
    }
    else if (parse->found_map && get_map_line(parse, line))
    {
        return close(parse->fd), free(line), 1;
    }
    return 0;
}

int ft_parse(t_parse *parse)
{
    char *line;

    while ((line = get_next_line(parse->fd)))
    {
        if (handle_line(parse, line))
            return get_next_line(parse->fd), 1;
        free(line);
    }
    return validate_and_close(parse);
}
