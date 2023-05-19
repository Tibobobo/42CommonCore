/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:09:36 by tgrasset          #+#    #+#             */
/*   Updated: 2023/04/07 16:11:49 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {

public:
	
	Contact(void);
	~Contact(void);

	void	setInfo(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getNumber(void) const;
	std::string getSecret(void) const;

private:

	std::string _firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_number;
	std::string	_secret;
};

#endif