#include "../parsing.h"


void ft_store_texture(t_tinfo *mapp, t_textura *tex, char *line)
{
    (void)mapp;
    while (*line == 32 || *line == '\t')
        line++;
    
    char **split = ft_split(line, ' ');
    
   ///split[2]
    if (!split || !split[0] || !split[1])
    {
        ft_error("🚨 INVALID TEXTURE LINE!", line);
        return;
    }
    
    if (!strcmp(split[0], "NO")) 
        tex->no = ft_strdup(split[1]);
    else if (!strcmp(split[0], "SO")) 
        tex->so = ft_strdup(split[1]);
    else if (!strcmp(split[0], "WE")) 
        tex->we = ft_strdup(split[1]);
    else if (!strcmp(split[0], "EA")) 
        tex->ea = ft_strdup(split[1]);
    
    // Free the split array (depending on your ft_split implementation)
    // This assumes you have a function to free the split result
    // free_split(split);
}
void ft_store_rgb(t_tinfo *mapp, t_textura *tex, char *line)
{
    (void)mapp;
    while (*line == ' ' || *line == '\t') // ✅ Skip leading spaces/tabs
        line++;

    char **split = ft_split(line, ' '); // ✅ Split identifier (F/C)
    if (!split || !split[0] || (strcmp(split[0], "F") && strcmp(split[0], "C")))
        ft_error("🚨 INVALID COLOR IDENTIFIER! Must be 'F' or 'C'", line);

    // ✅ Remove spaces around commas before splitting
    char clean_rgb[100] = {0}, *ptr = split[1];
    int k = 0, last_was_comma = 0;
    
    while (*ptr)
    {
        if (*ptr == ',' || (*ptr >= '0' && *ptr <= '9'))
        {
            clean_rgb[k++] = *ptr;
            last_was_comma = (*ptr == ',');
        }
        else if (*ptr != ' ' && *ptr != '\t')
            ft_error("🚨 INVALID CHARACTER IN RGB!", line);
        ptr++;
    }
    
    if (last_was_comma) // Prevent trailing comma
        ft_error("🚨 INVALID COLOR FORMAT! No trailing comma", line);

    char **rgb = ft_split(clean_rgb, ','); // ✅ Now split clean values
    if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3]) 
        ft_error("🚨 INVALID COLOR FORMAT! Expected R,G,B (0-255)", line);

    for (int i = 0; i < 3; i++) 
    {
        // ✅ Ensure each value is a valid number
        for (int j = 0; rgb[i][j]; j++)
            if (rgb[i][j] < '0' || rgb[i][j] > '9') 
                ft_error("🚨 RGB values must be numbers only", line);

        int val = ft_atoi(rgb[i]);
        if (val < 0 || val > 255)
            ft_error("🚨 RGB value out of range (0-255)", line);
    }

    int r = ft_atoi(rgb[0]), g = ft_atoi(rgb[1]), b = ft_atoi(rgb[2]);
    if (!strcmp(split[0], "F")) 
        tex->f[0] = r, tex->f[1] = g, tex->f[2] = b;
    else 
        tex->c[0] = r, tex->c[1] = g, tex->c[2] = b;

    printf("%s set to: R:%d G:%d B:%d\n", split[0], r, g, b);
}


void ft_check_xpm(t_textura *tex, t_tinfo *info)
{
    char *file_name[4] = {tex->ea, tex->no, tex->so, tex->we};
    if (!tex->no || !tex->so || !tex->we || !tex->ea) 
        ft_error("Missing at least one texture",NULL);
    info->text_path[0] = tex->no;
    info->text_path[1] = tex->so;
    info->text_path[2] = tex->we;
    info->text_path[3] = tex->ea;
    char *sch;
    int i = 0;
    while (i < 4)
    {
        if (!file_name[i])
            ft_error("ENTER YOUR FILE", NULL);
        int len = ft_strlen(file_name[i]);
        if (len > 0 && file_name[i][len - 1] == '\n')
            file_name[i][len - 1] = '\0';
        sch = ft_strrchr(file_name[i], '.');
        if (!sch || strcmp(sch, ".xpm")!= 0)
            ft_error("extantion error must be .xpm",file_name[i]);
        i++;
    }
}
// void ft_parse_textures(t_tinfo *mapp, t_textura *tex)
// {
//     char *line;
//     int i = 0;

//     while (i < 6 && (line = get_next_line(mapp->fd)))
//     {
//         if (*line != '\n')
//         {
//             ft_store_texture(mapp, tex, line);
//             i++;
//         }
//         // free(line);
//     }
//     // ft_check_tex(tex);
//     ft_check_xpm(tex, mapp);
// }
