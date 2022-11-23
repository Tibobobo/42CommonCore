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

int	print_int(int n)
{
    char    *str;

    str = ft_itoa(n);
    print_str(str);
	free(str);
    return (ft_strlen(str));
}
