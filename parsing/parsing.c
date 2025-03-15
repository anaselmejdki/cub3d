#include "../parsing.h"


int is_valid_map_symbol(char c)
{
    return (c == '0' || c == '1' || 
            c == 'N' || c == 'S' || 
            c == 'W' || c == 'E' ||
            c == ' ' || c == '\t' || c == '\n');
}

/**
 * Simple function to check if a line contains only valid map symbols
 * Returns 1 if valid, 0 if invalid
 */
int has_only_valid_map_symbols(char *line)
{
    int i = 0;
    
    while (line[i])
    {
        if (!is_valid_map_symbol(line[i]))
            return 0; // Invalid symbol found
        i++;
    }
    
    return 1; // All symbols are valid
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
	else if (!has_only_valid_map_symbols(line))
    {
        ft_error("Error: Invalid map symbol found in line: %s\n", line);
        // return 1; // Error
    }
	// else 
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
		// free(line); 
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
