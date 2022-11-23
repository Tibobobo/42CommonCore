/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:33:25 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/23 10:04:58 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr_base(int	n, char *base)
{
	long int	nb;
	int			base_len;

	nb = n;
	base_len = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb = -nb;
	}
	if (nb >= base_len)
	{
		ft_putnbr_base(nb / base_len);
		ft_putnbr_base(nb % base_len, base)
	}
	else
		ft_putchar_fd(base[nb], 1);
}
