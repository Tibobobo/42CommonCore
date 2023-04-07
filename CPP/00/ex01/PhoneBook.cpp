/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:09:48 by tgrasset          #+#    #+#             */
/*   Updated: 2023/04/07 17:09:34 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void) {
	
	this->contactNumber = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {

	return ;
}

void	PhoneBook::addContact(void) {
	
		std::string first = "", last = "", nick = "", phone = "", secret = "";
		std::cout << "New contact" << std::endl << std::endl;
		while (first.compare("") == 0)
		{
			std::cout << "First Name :";
			std::getline(std::cin, first);
		}
		while (last.compare("") == 0)
		{
			std::cout << "Last Name :";
			std::getline(std::cin, last);
		}
		while (nick.compare("") == 0)
		{
			std::cout << "Nickname :";
			std::getline(std::cin, nick);
		}
		while (phone.compare("") == 0)
		{
			std::cout << "Phone Number :";
			std::getline(std::cin, phone);
		}
		while (secret.compare("") == 0)
		{
			std::cout << "Darkest Secret :";
			std::getline(std::cin, secret);
		}
		
		this->_contacts[this->contactNumber % 8].setInfo(first, last, nick, phone, secret);
		this->contactNumber++;
		std::cout << "---Contact Saved---" << std::endl << std::endl;
}

void	PhoneBook::searchContact(void) const {

	int	index = 0;
	std::string buff, first, last, nick;

	while (index < 1 || index > 8)
	{
		std::cout << std::setw(10) << "index" << "|" << std::setw(10) << "first" << "|" << std::setw(10) << "last" << "|" << std::setw(10) << "nickname" << std::endl;
		for (int i = 0; i < 8; i++)
		{
			first = this->_contacts[i].getFirstName();
			if (first.length() >= 10)
			{
				first.resize(9);
				first.resize(10, '.');
			}
			last = this->_contacts[i].getLastName();
			if (last.length() >= 10)
			{
				last.resize(9);
				last.resize(10, '.');
			}
			nick = this->_contacts[i].getNickname();
			if (nick.length() >= 10)
			{
				nick.resize(9);
				nick.resize(10, '.');
			}
			std::cout << std::setw(10) << i + 1  << "|" << std::setw(10) << first << "|" << std::setw(10) << last << "|" << std::setw(10) << nick << std::endl;
		}
		std::cout << "Please enter a contact index :";
		std::getline(std::cin, buff);
		index = atoi(buff.c_str());
		if (index < 1 || index > 8)
			std::cout << "The index must be a value between 1 and 8." << std::endl;
	}
	std::cout << "First Name : " << this->_contacts[index - 1].getFirstName() << std::endl;
	std::cout << "Last Name : " << this->_contacts[index - 1].getLastName() << std::endl;
	std::cout << "Nickname : " << this->_contacts[index - 1].getNickname() << std::endl;
	std::cout << "Phone Number : " << this->_contacts[index - 1].getNumber() << std::endl;
	std::cout << "Darkest secret : " << this->_contacts[index - 1].getSecret() << std::endl;
	std::cout << std::endl << std::endl;
}