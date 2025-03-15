#include "../parsing.h"


int    ft_check_directions(char *line)
{
    if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "WE ", 3)
    || !ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "EA ", 3))
        printf("%s", line);
    return 1;
}