/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:47:29 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/23 09:48:06 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list args)
{
    char    *str;

    str = ft_itoa(va_arg, int);
    ft_putstr_fd(str, 1);
	free(str);
    return (ft_strlen(str));
}
