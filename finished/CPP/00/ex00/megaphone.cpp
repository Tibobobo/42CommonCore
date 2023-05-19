/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:58:58 by tgrasset          #+#    #+#             */
/*   Updated: 2023/04/07 11:54:13 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av) {
	
	int	i = 1;
	int	j = 0;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			std::cout << (char)toupper(av[i][j]);
			j++;
		}
		if (av[i + 1] != NULL)
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}