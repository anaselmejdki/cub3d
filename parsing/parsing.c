#include "../parsing.h"


void ft_check_map_borders(char **map, int height)
{
    int width = ft_strlen(map[0]); // Get map width

    // ✅ Check first and last row
    for (int j = 0; j < width; j++)
    {
        if (map[0][j] != '1' || map[height - 1][j] != '1')
        {
            ft_error("Map is not enclosed at row borders", NULL);
            return;
        }
    }

    // ✅ Check first and last column of each row
    for (int i = 0; i < height; i++)
    {
        if (map[i][0] != '1' || map[i][width - 1] != '1')
        {
            ft_error("Map is not enclosed at column borders", NULL);
            return;
        }
    }

    printf("✅ Map is correctly enclosed by walls!\n");
}

int main(int ac, char *av[])
{
	t_tinfo mapp;
	validation_extantion(&mapp, ac, av);
	validation_exist(&mapp);
	mapp.dbl_ptr = ft_read_map(&mapp);
	// ft_check_map_borders(mapp.dbl_ptr, mapp.hieght);








	// printing the map
	int i = 0;
	while (mapp.dbl_ptr[i])
	{
		printf(":::%s", mapp.dbl_ptr[i]);
		i++;
	}
	
	return 0;
}