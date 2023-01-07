/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:42:05 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/28 09:33:41 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/ft_printf.h"

int	main(void)
{
	char	*test = "toto";
	printf("%p\n", test);
	ft_printf("%p\n", test);
	printf("%s\n", test);
	ft_printf("%s\n", test);
	printf("test avec un pointeur : %p\n", test);
	ft_printf("test avec un pointeur : %p\n", test);
	printf("test avec une string : %s\n", test);
	ft_printf("test avec une string : %s\n", test);
	printf("%c %s %d %i %u %x %X \n" , 'a' , "😉"  , -443, -443 , 23456 , 123424, 123424);
	ft_printf("%c %s %d %i %u %x %X \n" , 'a' , "😉" , -443, -443 , 23456, 123424, 123424);  
	ft_printf("%d\n", ft_printf(NULL));
	printf("%d\n", printf(NULL));
	printf(NULL);
	printf("test % buiskl\n");
	ft_printf("test % buiskl\n");
	printf("%x\n", -100);
	ft_printf("%x\n", -100);
	printf("%c %s %d %i %u %x %X %\n" , 'a' , "😉", -443, -443 , 0xFF00 , 0b11110000);
	ft_printf("%c %s %d %i %u %x %X %\n" , 'a' , "😉", -443, -443 , 0xFF00 , 0b11110000); 
}
