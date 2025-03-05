
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	if (size != 0)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < (count * size))
	{
		*((char *)ptr + i) = 0;
		i++;
	}
	return (ptr);
}
