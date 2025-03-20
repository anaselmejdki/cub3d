#include "../include/main.h"

char *get_texture_path(char *path)
{
    int len = ft_strlen(path);
    char *line;

    if (len < 5 || ft_strncmp(path + len - 4, ".xpm", 4)) // Ensure .xpm extension
        return print_err(NULL, "Invalid texture path (must be .xpm)", 1), NULL;

    line = ft_strdup(path);
    if (!line)
        return NULL;

    return line;
}

int fill_textures_paths(t_parse *parse, char *path, char c)
{
    char *texture_path = get_texture_path(path);
    if (!texture_path)
        return 1;

    if (c == 'N' && !parse->no_text)
        parse->no_text = texture_path;
    else if (c == 'S' && !parse->so_text)
        parse->so_text = texture_path;
    else if (c == 'W' && !parse->we_text)
        parse->we_text = texture_path;
    else if (c == 'E' && !parse->ea_text)
        parse->ea_text = texture_path;
    else
        return free(texture_path), 1;

    return 0;
}

int parse_textures(t_parse *parse, char *line)
{
    while (*line == ' ' || *line == '\t') 
        line++;

    if (!(*line) || !(*(line + 1))) 
        return (ft_error("Invalid texture line", NULL), 1);

    char identifier = *line;
    line++; 

    while (*line == ' ' || *line == '\t') 
        line++;

    if (!(*line)) 
        return (ft_error("Invalid texture line", NULL), 1);

    char *path = ft_strtrim(line, " \t\r\n"); 
    if (!path)
        return 1;

    if (fill_textures_paths(parse, path, identifier))
        return free(path), 1;

    free(path);
    parse->texture_count++;
    return 0;
}
