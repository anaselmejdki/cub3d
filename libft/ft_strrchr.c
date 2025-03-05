
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	*str;

	str = (char *)s;
	count = ft_strlen(s);
	while (count >= 0)
	{
		if (str[count] == (char)c)
			return (&str[count]);
		count--;
	}
	return (NULL);
}
