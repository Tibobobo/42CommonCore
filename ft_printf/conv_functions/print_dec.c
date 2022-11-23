/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:46:55 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/23 16:29:42 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	print_dec(int n)
{
	char	*str;

	str = ft_itoa(n);
	print_str(str);
	free(str);
	return (ft_strlen(str));
}
