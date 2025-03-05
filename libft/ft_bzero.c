
#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	char	*p;
	int		i;

	i = 0;
	p = str;
	while (n-- > 0)
	{
		p[i] = '\0';
		i++;
	}
}
