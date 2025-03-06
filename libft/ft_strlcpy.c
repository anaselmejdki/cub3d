<<<<<<< HEAD
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:20:26 by ael-mejd          #+#    #+#             */
/*   Updated: 2023/11/05 15:20:41 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
>>>>>>> 784c0db4191273817a140ead724abb1fb5871e17

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclenth;
	size_t	i;

	i = 0;
	srclenth = ft_strlen((char *)src);
	if (dstsize)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclenth);
}
