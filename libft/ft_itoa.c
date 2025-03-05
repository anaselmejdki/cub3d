/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:39:43 by ael-mejd          #+#    #+#             */
/*   Updated: 2023/11/15 15:33:36 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*snum;
	int		count;
	long	num;

	num = n;
	count = count_size(num);
	snum = (char *)malloc(sizeof(char) * (count + 1));
	if (!snum)
		return (NULL);
	snum[count--] = '\0';
	if (num < 0)
	{
		snum[0] = '-';
		num *= -1;
	}
	while (num > 9)
	{
		snum[count--] = num % 10 + '0';
		num /= 10;
	}
	snum[count] = num % 10 + '0';
	return (snum);
}
