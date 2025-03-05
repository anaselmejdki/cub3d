
#include "libft.h"

int	ft_isalpha(int str)
{
	if (str < 'A' || (str > 'Z' && str < 'a') || str > 'z')
	{
		return (0);
	}
	return (1);
}
