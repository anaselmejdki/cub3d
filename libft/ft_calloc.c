/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:41:50 by ael-mejd          #+#    #+#             */
/*   Updated: 2023/11/25 21:41:57 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;

	if (count != 0 && size != 0 && size > SIZE_MAX / count)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero((void *)p, count * size);
	return ((void *)p);
}
