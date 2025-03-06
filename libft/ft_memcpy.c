<<<<<<< HEAD
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:15:51 by ael-mejd          #+#    #+#             */
/*   Updated: 2023/11/05 12:16:11 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
>>>>>>> 784c0db4191273817a140ead724abb1fb5871e17

#include "libft.h"

void	*ft_memcpy(void *dst, const char *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (dst != src)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
