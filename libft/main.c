/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:40:15 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/10 17:31:53 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
	

char	ft_uppercaseafter10(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z' && i >= 10)
	{
		c = c -32;
	}
	return (c);
}

void	ft_uppercaseafter13(unsigned int i, char *str)
{
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' && i >= 13)
			str[i] = str[i] -32;
		i++;
	}
}

int	main(void)
{
	char	(*pf)(unsigned int, char);
	void	(*pf2)(unsigned int, char *);
	pf = &ft_uppercaseafter10;
	pf2 = &ft_uppercaseafter13;

	printf("ft_isalpha(0) = %d\n", ft_isalpha(0));
	printf("ft_isalpha(5) = %d\n", ft_isalpha(5));
	printf("ft_isalpha(65) = %d\n", ft_isalpha(65));
	printf("ft_isalpha('h') = %d\n", ft_isalpha('h'));
	printf("ft_isalpha('4') = %d\n", ft_isalpha('4'));
	printf("-----------------------------------------------------\n\n");
	
	printf("ft_isdigit(0) = %d\n", ft_isdigit(0));
	printf("ft_isdigit(5046) = %d\n", ft_isdigit(5046));
	printf("ft_isdigit(48) = %d\n", ft_isdigit(48));
	printf("ft_isdigit('5') = %d\n", ft_isdigit('5'));
	printf("ft_isdigit('8') = %d\n", ft_isdigit('8'));
	printf("-----------------------------------------------------\n\n");

	printf("ft_isalnum('z') = %d\n", ft_isalnum('z'));
	printf("ft_isalnum(-7654) = %d\n", ft_isalnum(-7654));
	printf("ft_isalnum(77) = %d\n", ft_isalnum(77));
	printf("ft_isalnum('7') = %d\n", ft_isalnum('7'));
	printf("ft_isalnum(' ') = %d\n", ft_isalnum(' '));
	printf("-----------------------------------------------------\n\n");
		
	printf("ft_isascii(-25) = %d\n", ft_isascii(-25));
	printf("ft_isascii(127) = %d\n", ft_isascii(127));
	printf("ft_isascii(200) = %d\n", ft_isascii(200));
	printf("ft_isascii('#') = %d\n", ft_isascii('#'));
	printf("ft_isascii('\\n') = %d\n", ft_isascii('\n'));
	printf("-----------------------------------------------------\n\n");
	
	printf("ft_isprint(0) = %d\n", ft_isprint(0));
	printf("ft_isprint(123) = %d\n", ft_isprint(123));
	printf("ft_isprint(-123456) = %d\n", ft_isprint(-123456));
	printf("ft_isprint('&') = %d\n", ft_isprint('&'));
	printf("ft_isprint('\\b') = %d\n", ft_isprint('\b'));
	printf("-----------------------------------------------------\n\n");

	printf("ft_strlen(42) = %zu\n", ft_strlen("42"));
	printf("ft_strlen(vide) = %zu\n", ft_strlen(""));
	printf("ft_strlen(Coucou les copains) = %zu\n", ft_strlen("Coucou les copains"));
	printf("ft_strlen(L) = %zu\n", ft_strlen("L"));
	printf("ft_strlen(Thibaut) = %zu\n", ft_strlen("Thibaut"));
	printf("-----------------------------------------------------\n\n");

	void	*memset;
	char	memset1[] = "Salut ca va?";
	memset = &memset1;
	ft_memset(memset, 65, 4);
	printf("ft_memset(octets a l'adresse pointee : Salut ca va?, 65, 4) = %s\n", memset1);
	printf("-----------------------------------------------------\n\n");

	void	*bzero;
	char	bzero1[] = "Salut ca va?";
	int		index;
	index = 0;
	bzero = &bzero1;
	ft_bzero(bzero, 5);
		printf("ft_bzero(octets a l'adresse pointee : Salut ca va?, 5) = \n");
	while (index <= 5)
	{
		printf("%d\n", *(bzero1 + index));
		index++;
	}
	printf("-----------------------------------------------------\n\n");

	void	*memcpydest;
	void	*memcpysrc;
	char	memcpydest1[] = "Tres chiante a tester cette fonction";
	char	memcpysrc1[] = "LOL  ";
	memcpydest = &memcpydest1;
	memcpysrc = &memcpysrc1;
	printf("ft_memcpy(\"Tres chiante a tester cette fonction\", \"LOL\", 3) = %s\n", (char *)ft_memcpy(memcpydest, memcpysrc, 3));
	printf("-----------------------------------------------------\n\n");
	char	testlcpy[50];
	char	test2lcpy[50];
	printf("ft_strlcpy: src = \"Hello World\" size = 12\n");
	printf("     return value : %zu\n", ft_strlcpy(testlcpy, "Hello World", 12));
	printf("     dest string: %s\n", testlcpy);	
	printf("ft_strlcpy: src = \"Hello World\" size = 4\n");
	printf("     return value : %zu\n", ft_strlcpy(testlcpy, "Hello World", 4));
	printf("     dest string: %s\n", testlcpy);
	printf("ft_strlcpy: src = \"Hello World\" size = 1\n");
	printf("     return value : %zu\n", ft_strlcpy(testlcpy, "Hello World", 1));
	printf("     dest string: %s\n", testlcpy);
	printf("ft_strlcpy: src = \"Hello World\" size = 0\n");
	printf("     return value : %zu\n", ft_strlcpy(test2lcpy, "Hello World", 1));
	printf("     dest string: %s\n", test2lcpy);
	printf("-----------------------------------------------------\n\n");

	char	srcat[] = " World";
	char	destcat[6] = "Hello";
	printf("ft_strlcat: src = \" World\", dest = \"Hello\", size = 50\n");
	printf("     return value : %zu\n", ft_strlcat(destcat, srcat, 50));
	printf("     dest string: %s\n", destcat);
	char	srcat2[] = " World";
	char	destcat2[6] = "Hello";
	printf("ft_strlcat: src = \" World\", dest = \"Hello\", size = 8\n");
	printf("     return value : %zu\n", ft_strlcat(destcat2, srcat2, 8));
	printf("     dest string: %s\n", destcat2);
	char	srcat3[] = " World";
	char	destcat3[6] = "Hello";
	printf("ft_strlcat: src = \" World\", dest = \"Hello\", size = 0\n");
	printf("     return value : %zu\n", ft_strlcat(destcat3, srcat3, 0));
	printf("     dest string: %s\n", destcat3);
	printf("-----------------------------------------------------\n\n");

	printf("ft_toupper('t') = %c\n", ft_toupper('t'));	
	printf("ft_toupper(100) = %c\n", ft_toupper(100));
	printf("ft_toupper('A') = %c\n", ft_toupper('A'));
	printf("ft_toupper('1') = %c\n", ft_toupper('1'));
	printf("ft_toupper('z') = %c\n", ft_toupper('z'));
	printf("-----------------------------------------------------\n\n");

	printf("ft_tolower('T') = %c\n", ft_tolower('T'));	
	printf("ft_tolower(66) = %c\n", ft_tolower(66));
	printf("ft_tolower('r') = %c\n", ft_tolower('r'));
	printf("ft_tolower('$') = %c\n", ft_tolower('$'));
	printf("ft_tolower('X') = %c\n", ft_tolower('X'));
	printf("-----------------------------------------------------\n\n");
	
	printf("ft_strchr(\"Hello World\", 101) = %s\n", ft_strchr("Hello World", 101));
	printf("ft_strchr(\"Hello World\", 108) = %s\n", ft_strchr("Hello World", 108));
	printf("ft_strchr(\"Hello World\", 0) = %s\n", ft_strchr("Hello World", 0));
	printf("ft_strchr(\"Hello World\", -45) = %s\n", ft_strchr("Hello World", -45));
	printf("ft_strchr(\"\", 65) = %s\n", ft_strchr("", 65));
	printf("-----------------------------------------------------\n\n");
		
	printf("ft_strrchr(\"Hello World\", 108) = %s\n", ft_strrchr("Hello World", 108));
	printf("ft_strrchr(\"Hello World\", 111) = %s\n", ft_strrchr("Hello World", 111));
	printf("ft_strrchr(\"Hello World\", -45) = %s\n", ft_strrchr("Hello World", -45));
	printf("ft_strrchr(\"Hello World\", 0) = %s\n", ft_strrchr("Hello World", 0));
	printf("ft_strrchr(\"\", 65) = %s\n", ft_strrchr("", 65));
	printf("-----------------------------------------------------\n\n");
	
	printf("ft_strncmp(\"Salut\", \"Salut\", 5) = %d\n", ft_strncmp("Salut", "Salut", 5));
	printf("ft_strncmp(\"Salut\", \"Salut\", 8) = %d\n", ft_strncmp("Salut", "Salut", 8));
	printf("ft_strncmp(\"Salut\", \"Salllllut\", 3) = %d\n", ft_strncmp("Salut", "Salllllut", 3));
	printf("ft_strncmp(\"Salut\", \"Salllllut\", 4) = %d\n", ft_strncmp("Salut", "Salllllut", 4));
	printf("ft_strncmp(\"Salut\", \"Ssalut\", 5) = %d\n", ft_strncmp("Salut", "Ssalut", 5));
	printf("ft_strncmp(\"Salut\", \"Bonjour\", 0) = %d\n", ft_strncmp("Salut", "Bonjour", 0));
	printf("-----------------------------------------------------\n\n");

	printf("ft_strnstr(\"Coucou les loulous\",\"les\", 11) = %s\n", ft_strnstr("Coucou les loulous", "les", 11));
	printf("ft_strnstr(\"Coucou les loulous\",\"les\", 9) = %s\n", ft_strnstr("Coucou les loulous", "les", 9));
	printf("ft_strnstr(\"Coucou les loulous\",\"\", 11) = %s\n", ft_strnstr("Coucou les loulous", "", 11));
	printf("ft_strnstr(\"Coucoule leleleslesles loulous\",\"les\", 1000) = %s\n", ft_strnstr("Coucoule leleleslesles loulous", "les", 1000));
	printf("ft_strnstr(\"\",\"les\", 11) = %s\n", ft_strnstr("", "les", 11));	
	printf("-----------------------------------------------------\n\n");

	printf("ft_atoi(\"      -1234\") = %d\n", ft_atoi("       -1234"));
	printf("ft_atoi(\"      +9\") = %d\n", ft_atoi("       +9"));
	printf("ft_atoi(\"\") = %d\n", ft_atoi(""));
	printf("ft_atoi(\"      ashduooj138\") = %d\n", ft_atoi("       ashduooj138"));
	printf("ft_atoi(\"     2147483647  \") = %d\n", ft_atoi("      2147483647   "));
	printf("ft_atoi(\"-2147483648\") = %d\n", ft_atoi("-2147483648"));
	printf("ft_atoi(\"0000000000000qwerty\") = %d\n", ft_atoi("00000000000qwerty"));
	printf("-----------------------------------------------------\n\n");

	printf("ft_strdup(\"Marre de ce main interminable\") = %s\n", ft_strdup("Marre de ce main interminable"));	
	printf("ft_strdup(\"\") = %s\n", ft_strdup(""));
	printf("ft_strdup(\"Ca marche c'est bon?\") = %s\n", ft_strdup("Ca marche c'est bon?"));
	printf("-----------------------------------------------------\n\n");

	printf("ft_substr(\"More strings...\", 4, 8) = %s\n", ft_substr("More strings...", 3, 8));
	printf("ft_substr(\"More strings...\", 1, 100) = %s\n", ft_substr("More strings...", 1, 100));
	printf("ft_substr(\"More strings...\", 100, 1) = %s\n", ft_substr("More strings...", 100, 1));
	printf("ft_substr(\"More strings...\", 0, 8) = %s\n", ft_substr("More strings...", 0, 8));
	printf("ft_substr(\"More strings...\", 8, 0) = %s\n", ft_substr("More strings...", 8, 0));
	printf("-----------------------------------------------------\n\n");

	printf("ft_strjoin(\"Salut \", \"les gens\") = %s\n", ft_strjoin("Salut ", "les gens"));
	printf("ft_strjoin(\"\", \"les gens\") = %s\n", ft_strjoin("", "les gens"));
	printf("ft_strjoin(\"Salut \", \"\") = %s\n", ft_strjoin("Salut ", ""));
	printf("ft_strjoin(\"\", \"\") = %s\n", ft_strjoin("", ""));
	printf("ft_strjoin(NULL, \"Test avec pointeur null\") = %s\n", ft_strjoin(NULL, "test avec pointeur null"));
	printf("-----------------------------------------------------\n\n");

	printf("ft_strtrim(\"Salut les gens \", \"san\") = %s\n", ft_strtrim("Salut les gens", "san"));
	printf("ft_strtrim(\"abcdefSalut abcdef les gens fbax fce\", \"abecfd\") = %s\n", ft_strtrim("abcdefSalut abcdef les gens fbax fce", "abecfd"));
	printf("ft_strtrim(\"Salut les gens \", \"\") = %s\n", ft_strtrim("Salut les gens", ""));
	printf("ft_strtrim(\"\", \"san\") = %s\n", ft_strtrim("", "san"));
	printf("ft_strtrim(\"Salut les gens \", NULL) = %s\n", ft_strtrim("Salut les gens", NULL));
	printf("-----------------------------------------------------\n\n");
	
	printf("ft_split(\"  Legere envie de crever avec ce main...   \", ' ') = \n");
	int	i = 0;
	char	**split = ft_split("   Legere envie de crever avec ce main...   ", ' ');
	while (split[i])
	{
		printf("		%s\n", split[i]);
		i++;
	}
	printf("ft_split(\"Legere envie de crever avec ce main...\", ' ') = \n");
	i = 0;
	char	**split2 = ft_split("   Legere envie de crever avec ce main...   ", ' ');
	while (split2[i])
	{
		printf("		%s\n", split2[i]);
		i++;
	}
	printf("ft_split(\"  Legere envie de crever avec ce main...   \", 'e') = \n");
	i = 0;
	char	**split3 = ft_split("   Legere envie de crever avec ce main...   ", 'e');
	while (split3[i])
	{
		printf("		%s\n", split3[i]);
		i++;
	}
	printf("-----------------------------------------------------\n\n");

	printf("ft_itoa(0) = %s\n", ft_itoa(0));
	printf("ft_itoa(5) = %s\n", ft_itoa(5));
	printf("ft_itoa(123) = %s\n", ft_itoa(123));
	printf("ft_itoa(2147483647) = %s\n", ft_itoa(2147483647));
	printf("ft_itoa(-2147483648) = %s\n", ft_itoa(-2147483648));
	printf("ft_itoa(1) = %s\n", ft_itoa(1));
	printf("-----------------------------------------------------\n\n");

	printf("ft_strmapi(\"JPP C'est trop long..  \", pointeur sur fonction ft_uppercaseafter10) =\n");
	printf("%s\n", ft_strmapi("JPP C'est trop long..   ", pf));
	printf("-----------------------------------------------------\n\n");
	
	char	striteri[] = "JPP C'est vraiment trop long..   ";
	ft_striteri(striteri, pf2);
	printf("ft_striteri(\"JPP C'est vraiment trop long..   \", pointeur sur fonction ft_uppercaseafter13 = \n");
	printf("%s\n", striteri);
	printf("-----------------------------------------------------\n\n");

	printf("ft_putchar_fd('!', 1) = \n");
	ft_putchar_fd('!', 1);
	ft_putchar_fd('\n', 1);
	printf("-----------------------------------------------------\n\n");

	printf("ft_putstr_fd(\"  coucou les copains  \", 1) = \n");
	ft_putstr_fd("  coucou les copains  ", 1);
	ft_putchar_fd('\n', 1);
	printf("-----------------------------------------------------\n\n");
	
	printf("ft_putendl_fd(\"  coucou les copains  \", 1) = \n");
	ft_putendl_fd("  coucou les copains  ", 1);
	ft_putchar_fd('\n', 1);
	printf("-----------------------------------------------------\n\n");

	printf("ft_putnbr_fd(0, 1) =\n");
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	printf("ft_putnbr_fd(-1, 1) =\n");
	ft_putnbr_fd(-1, 1);
	ft_putchar_fd('\n', 1);
	printf("ft_putnbr_fd(1234, 1) =\n");
	ft_putnbr_fd(1234, 1);
	ft_putchar_fd('\n', 1);
	printf("ft_putnbr_fd(2147483647, 1) =\n");
	ft_putnbr_fd(2147483647, 1);
	ft_putchar_fd('\n', 1);
	printf("ft_putnbr_fd(-2147483648, 1) =\n");
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);
}	
