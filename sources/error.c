/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejd <ael-mejd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:23:08 by ael-mejd          #+#    #+#             */
/*   Updated: 2025/02/28 23:45:10 by ael-mejd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int err_msg(char *s1, char *s2, int flag)
{
    ft_putstr_fd("cub3D : Error", 2);
    if (s1)
    {
        ft_putstr_fd(": ", 2);
        ft_putstr_fd(s1, 2);
    }
    if (s2)
    {
        ft_putstr_fd(": ", 2);
        ft_putstr_fd(s2, 2);
    }
    return (flag);
}

int	err_msg_val(int detail, char *str, int flag)
{
	ft_putstr_fd("cub3D: Error: ", 2);
	ft_putnbr_fd(detail, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	return (flag);
}
