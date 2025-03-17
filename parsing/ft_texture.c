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
    // free(split); // hadi friyiha
}


int ft_parse_rgb_value(char **line, char *original_line)
{
    while (**line == ' ' || **line == '\t')
        (*line)++;

    if (!ft_isdigit(**line))
        ft_error("🚨 MISSING RGB VALUE", original_line);

    int rgb_value = 0;
    
    while (ft_isdigit(**line)) {
        rgb_value = rgb_value * 10 + (**line - '0');
        (*line)++;
    }

    if (rgb_value < 0 || rgb_value > 255)
        ft_error("🚨 COLOR VALUE OUT OF RANGE (0-255)!", original_line);

    while (**line == ' ' || **line == '\t')
        (*line)++;

    return rgb_value;
}

void ft_store_rgb(t_tinfo *mapp, t_textura *tex, char *line)
{
    (void)mapp;
    char *original_line = line; 
    
    while (*line == ' ' || *line == '\t')
        line++;

    if (!*line || (*line != 'F' && *line != 'C'))
        ft_error("🚨 INVALID COLOR IDENTIFIER! Must be 'F' or 'C'", original_line);
    
    char identifier = *line++;
    
    while (*line == ' ' || *line == '\t' )
        line++;

    int rgb[3] = {0, 0, 0};
    
    for (int i = 0; i < 3; i++) {
        // Parse each color value
        rgb[i] = ft_parse_rgb_value(&line, original_line);

        if (i < 2) {
            if (*line != ',')
                ft_error("🚨 EXPECTED COMMA BETWEEN RGB VALUES", original_line);
            line++; // Skip the comma
        }
    }
    
    while (*line == ' ' || *line == '\t' || *line == '\n')
        line++;

    if (*line != '\0')
        ft_error("🚨 UNEXPECTED CHARACTERS AFTER RGB VALUES", original_line);
    
    if (identifier == 'F') {
        tex->f[0] = rgb[0];
        tex->f[1] = rgb[1];
        tex->f[2] = rgb[2];
        printf("Floor color set to: R:%d G:%d B:%d\n", rgb[0], rgb[1], rgb[2]);
    } else {
        tex->c[0] = rgb[0];
        tex->c[1] = rgb[1];
        tex->c[2] = rgb[2];
        printf("Ceiling color set to: R:%d G:%d B:%d\n", rgb[0], rgb[1], rgb[2]);
    }
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
