
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		j;
	size_t	dstlen;

	i = 0;
	j = 0;
	if (dest == NULL && n == 0)
		return (ft_strlen(src));
	while (dest[j] != '\0')
	{
		j++;
	}
	dstlen = j;
	if (n == 0 || n <= dstlen)
		return (ft_strlen(src) + n);
	while (src[i] != '\0' && i < n - dstlen - 1)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dstlen + ft_strlen(src));
}
