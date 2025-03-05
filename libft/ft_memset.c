
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*p;
	int		val;
	size_t	i;

	i = 0;
	val = c;
	p = (char *)str;
	while (i < n)
	{
		p[i] = val;
		i++;
	}
	return (str);
}
