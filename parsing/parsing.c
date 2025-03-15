#include "../parsing.h"



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
        if (rgb[3]) // checking for the 4th color;
            ft_error("nop", rgb[3]);

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



int check_line(t_tinfo *mapp, t_textura *tex, char *line)
{
    char *trimmed_line;
    
    // Skip leading whitespace
    trimmed_line = skip_spaces(line);
    
    // Check for empty line
    if (!trimmed_line || !*trimmed_line)
        return 0;
    
    // Check for texture identifiers
    if (!ft_strncmp(trimmed_line, "NO ", 3) || 
        !ft_strncmp(trimmed_line, "SO ", 3) ||
        !ft_strncmp(trimmed_line, "WE ", 3) || 
        !ft_strncmp(trimmed_line, "EA ", 3))
    {
        ft_store_texture(mapp, tex, trimmed_line);
    }
	// Check for texture Colors
	else if (!ft_strncmp(trimmed_line, "F ", 2) || !ft_strncmp(trimmed_line, "C ", 2))
	{
		ft_store_rgb(mapp,tex, trimmed_line);
	}
	// goodo
	// else
	// 	return (ft_error("Invalid configuration", trimmed_line), 1);
	return 0;
}


int ft_parsing(t_tinfo *mapp,t_textura *tex, int ac, char *av[])
{
	validation_extantion(mapp, ac, av);
	validation_exist(mapp);
	char *line = get_next_line(mapp->fd);
	while (line)
	{
		check_line(mapp, tex, line);
			// ft_error("KAYNA INAA", line);
		// printf("%s", line);
		
		line = get_next_line(mapp->fd);
	}
	
	// mapp->dbl_ptr = ft_read_map(mapp);
	// ft_height(mapp);
	// check_f_and_last_line(mapp);
	// ft_check_map_borders(mapp->dbl_ptr, mapp->hieght);
	// ft_check_special_chars(mapp->dbl_ptr, mapp->hieght);
	// ft_check_32(mapp->dbl_ptr, mapp->hieght);


	// close (mapp->fd);
	// validation_exist(mapp);
	

    // ft_parse_textures(mapp, tex);
    // printf("Loading texture %d: '%s'\n", 0, tex->no);
    printf("NO: %s\n", tex->no);
    printf("SO: %s\n", tex->so);
    printf("WE: %s\n", tex->we);
    printf("EA: %s\n", tex->ea);
	printf("Floor RGB Values: R:%d G:%d B:%d\n", tex->f[0], tex->f[1], tex->f[2]);
    printf("Ceiling RGB Values: R:%d G:%d B:%d\n", tex->c[0], tex->c[1], tex->c[2]);
    // printf("Floor: %d, %d, %d\n", tex->f[0], tex->f[1], tex->f[2]);
    // printf("Ceiling: %d, %d, %d\n", tex->c[0], tex->c[1], tex->c[2]);

	// printf("ceiling data : %d\n", tex.c[0]);


	// printing the map
	// t_tinfo mapp;

	// int i = 0;
	// while (mapp->dbl_ptr[i])
	// {
	// 	printf("%s", mapp->dbl_ptr[i]);
	// 	i++;
	// }
	// close (mapp->fd);
	return 1;
}
