/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 06:08:24 by ael-mejd          #+#    #+#             */
/*   Updated: 2023/11/11 06:08:41 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc((size + 1) * sizeof(char));
	if (!join)
		return (NULL);
	join[0] = '\0';
	ft_strlcat(join, s1, (size + 1));
	ft_strlcat(join, s2, (size + 1));
	return (join);
}
