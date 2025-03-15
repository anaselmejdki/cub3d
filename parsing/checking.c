#include "../parsing.h"

void check_f_and_last_line(t_tinfo *mapp)
{
	char *first;
	char *last;
	// int i;
	int f;

	first = mapp->dbl_ptr[0];
	last = mapp->dbl_ptr[mapp->hieght - 1];
	// i = 0;
	f = 0;

	while (first[f])
	{
		if (first[f] != '1' && first[f] != 32 && first[f] != '\n')
			ft_error("👾 YOU NEED '1' IN FIRST ROW 👾", first);
		f++;
	}
	f = 0;
	while (last[f])
	{
		if (last[f] != '1' && last[f] != 32 && last[f] != '\n')
			ft_error("👾 YOU NEED '1' IN LAST ROW 👾", last);
		f++;
	}
}

void ft_check_special_chars(char **map, int height)
{
    int i = 0;
	int j;
    int player_count = 0;
    while (i < height)
    {
        j = 0;
        while (map[i][j] && map[i][j] != '\n')
        {
            if (map[i][j] != '1' && map[i][j] != '0' &&
                map[i][j] != 'N' && map[i][j] != 'S' &&
                map[i][j] != 'E' && map[i][j] != 'W' &&
                map[i][j] != ' ') 
                ft_error(" INVALID CHARACTER FOUND IN MAP!", map[i]);
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
				player_count++;
            j++;
        }
        i++;
    }
	if (player_count == 0)
		ft_error("YOU NEED A PLAYER", NULL);
	if (player_count > 1)
		ft_error(" MULTIPLE PLAYERS FOUNDED IN MAP!", NULL);
}

void ft_check_32(char **map, int height)
{
    int i, j;

    i = 0;
    while (i < height)
    {
        j = 0;
        while (map[i][j] && map[i][j] != '\n')
        {
            if (map[i][j] == ' ')
            {
                if ((j > 0 && map[i][j - 1] != '1' && map[i][j - 1] != ' ') || 
                    (map[i][j + 1] != '\0' && map[i][j + 1] != '1' && map[i][j + 1] != ' '))
                    ft_error("LEFT & RIGHT BY WALL!", map[i]);
                if (i > 0 && map[i - 1][j] != '1' && map[i - 1][j] != ' ')
                    ft_error(" ABOVE BY WALLS!", map[i]);
                if (i < height - 1 && map[i + 1][j] != '1' && map[i + 1][j] != ' ')
                    ft_error("BELOW BY WALLS!", map[i]);
            }
            if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W') &&
                (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i - 1][j] == ' ' || map[i + 1][j] == ' '))
                ft_error("PLAYER CANNOT HAVE ACCESS TO EMPTY SPACE", map[i]);
            j++;
        }
        i++;
    }
}