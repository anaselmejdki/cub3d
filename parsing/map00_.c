#include "../parsing.h"

int is_valid_map_symbol(char c)
{
        

    if (c == '0' || c == '1' || 
            c == 'N' || c == 'S' || 
            c == 'W' || c == 'E' ||
            c == ' ' || c == '\t' || c == '\n')
        return 1; 
        
    return 0; 
}

int ft_check_special_chars(char *line)
{
    int i = 0;
    // int j;
    // int player_count = 0;

    
        while (line[i] && line[i] != '\n')
        {
            printf("\033[36m%c\033m", line[i]);
            // if (!is_valid_map_symbol(line[i]))  
            //     ft_error(" INVALID CHARACTER FOUND IN MAP!", map[i]);

            // if (line[i] == 'N' || line[i] == 'S' ||
            //     line[i] == 'E' || line[i] == 'W')
            //     player_count++;

            i++;
        }
return 0;
    // if (player_count == 0)
    //     ft_error("YOU NEED A PLAYER", NULL);
    // if (player_count > 1)
    //     ft_error("MULTIPLE PLAYERS FOUND IN MAP!", NULL);
}

int has_only_valid_map_symbols(char *line)
{
    int i = 0;
    
    while (line[i])
    {
        if (!is_valid_map_symbol(line[i]))
            return 0;
        i++;
    }
    return 1; 
}

void ft_get_player_position(char **map, int height, int *player_x, int *player_y, char *player_dir)
{
    int i = 0;
    int j;

    while (i < height)
    {
        j = 0;
        while (map[i][j] && map[i][j] != '\n')
        {
            if (map[i][j] == 'N' || map[i][j] == 'S' ||
                map[i][j] == 'E' || map[i][j] == 'W')
            {
                *player_x = j;
                *player_y = i;
                *player_dir = map[i][j];
                return;
            }
            j++;
        }
        i++;
    }
}