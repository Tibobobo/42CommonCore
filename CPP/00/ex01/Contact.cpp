/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:09:30 by tgrasset          #+#    #+#             */
/*   Updated: 2023/04/07 16:19:35 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {

	this->_firstName = "<empty>";
	this->_lastName = "<empty>";
	this->_nickname = "<empty>";
	this->_number = "<empty>";
	this->_secret = "<empty>";
	return ;
}

Contact::~Contact(void) {
	
	return ;
}

void	Contact::setInfo(std::string first, std::string last, std::string nick, std::string number, std::string secret) {

	this->_firstName = first;
	this->_lastName = last;
	this->_nickname = nick;
	this->_number = number;
	this->_secret = secret;
}

std::string	Contact::getFirstName(void) const {
	
	return (this->_firstName);
}

std::string	Contact::getLastName(void) const {
	
	return (this->_lastName);
}

std::string	Contact::getNickname(void) const {
	
	return (this->_nickname);
}

std::string	Contact::getNumber(void) const {
	
	return (this->_number);
}

std::string	Contact::getSecret(void) const {
	
	return (this->_secret);
}