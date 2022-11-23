/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:24:11 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/22 11:24:19 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_printf(const char *, ...);
int	print_char(int c);
int	print_dec(int n);
int	print_int(int n);
int	print_up_hex(unsigned int n);
int	print_percent(void);
int	print_ptr(unsigned long long n);
int	print_str(char *str);
int	print_unsigned_dec(unsigned int n);
int	print_low_hex(unsigned int n);

#endif
