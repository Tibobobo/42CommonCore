/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:23:59 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/22 11:55:13 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_conv(va_list args, char c)
{
	int	ret_value;

	if (c == 'c')
		ret_value = print_char(args);
	else if (c == 's')
		ret_value = print_str(args);
	else if (c == 'p')
		ret_value = print_ptr(args);
	else if (c == 'd')
		ret_value = print_dec(args);
	else if (c == 'i')
		ret_value = print_int(args);
	else if (c == 'u')
		ret_value = print_unsigned_dec(args);
	else if (c == 'x')
		ret_value = print_low_hex(args);
	else if (c == 'X')
		ret_value = print_up_hex(args);
	else if (c == '%')
		ret_value = print_percent();
	return (ret_value);
}

int	is_placeholder(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	conversion(va_list args, char c)
{
	if (is_placeholder(c, "cspdiuxX%") == 1)
		return (print_conv(args, c))
	else
	{
		ft_putchar_fd(c, 1);
		return (1);	
	}
}

int	ft_printf(const char str*, ...)
{
	va_list args;
	int	i;
	int	char_count;

	i = 0;
	char_count = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			char_count++;
		}
		else
		{
			if (*(str + 1) != '\0')
			{
				str++;
				char_count = char_count + conversion(args, *str)
			}
		}
		str++;
	}
	va_end(args);
	return (char_count);
}
