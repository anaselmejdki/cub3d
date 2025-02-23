/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:01 by saait-si          #+#    #+#             */
/*   Updated: 2025/02/23 10:24:44 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchrr(const char *str, char c)
{
	char	*up;

	up = (char *)str;
	while (c != *up)
	{
		if (!*up)
			return (0);
		up++;
	}
	return (up);
}

char	*ft_strjoinn(char *stash, char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*str;

	if (!stash || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(stash) + ft_strlen(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (stash)
		while (stash[++i] != '\0')
			str[i] = stash[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	total_len = ft_strlen(stash) + ft_strlen(buffer);
	str[total_len] = '\0';
	free(stash);
	return (str);
}
