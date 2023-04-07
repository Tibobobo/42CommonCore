/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:09:41 by tgrasset          #+#    #+#             */
/*   Updated: 2023/04/07 16:39:25 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	std::string firstName, lastName, nickname, number, secret, command;
	PhoneBook book;

	std::cout << "Welcome to your Awesome PhoneBook" << std::endl << std::endl << std::endl;
	std::cout << "Available commands : ADD, SEARCH and EXIT" << std::endl;
	while (42)
	{
		std::cout << "Please enter a command : ";
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0)
			book.addContact();
		else if (command.compare("SEARCH") == 0)
			book.searchContact();
		else if (command.compare("EXIT") == 0)
			break ;
		else if (command.compare("") == 0)
			continue ;
		else
			std::cout << "Unknown command. Available commands : ADD, SEARCH and EXIT" << std::endl;
	}
	std::cout << "Thanks for using this Awesome PhoneBook" <<std::endl;
	return (0);
}