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
int is_valid_number(char *str)
{
    int i = 0;
    
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    
    if (!str[i])
        return 0;
    
    while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;  
        i++;
    }
    
    return 1;  
}
void ft_store_rgb(t_tinfo *mapp,t_textura *tex,char *line)
{
	(void)mapp;
	while (*line == 32 || *line == '\t')
        line++;
	char **split =  ft_split(line, ' ');
    if (!strcmp(split[0], "F") || !strcmp(split[0], "C"))
    {
        while (*split[1] == 32 || *split[1] == '\t')
            split[1]++;

        char **rgb = ft_split(split[1], ',');
        if (!rgb || !rgb[0] || !rgb[1] || !rgb[2]) 
            ft_error("🚨 INVALID COLOR FORMAT!", line);
        if (rgb[3] != NULL)
        {
            // free_map(rgb);
            ft_error("🚨 TOO MANY COLOR VALUES! Expected exactly 3 values", line);
        }

        // hna radi tciki ldigit mantsayx 
        if (!is_valid_number(rgb[0]) || !is_valid_number(rgb[1]) || !is_valid_number(rgb[2]))
        {
            // free_map(rgb);
            ft_error("🚨 number only", line);
        }
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
