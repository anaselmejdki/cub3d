
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		l;
	char	*p1;

	l = 0;
	p1 = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (p1 == NULL)
	{
		return (NULL);
	}
	while (src[l])
	{
		p1[l] = src[l];
		l++;
	}
	p1[l] = '\0';
	return (p1);
}
