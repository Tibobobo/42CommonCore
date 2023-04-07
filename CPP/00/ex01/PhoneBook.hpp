/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:09:53 by tgrasset          #+#    #+#             */
/*   Updated: 2023/04/07 14:24:25 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook {

	public:
	
		PhoneBook(void);
		~PhoneBook(void);
		
		void	addContact(void);
		void	searchContact(void) const;

	private:
		int	contactNumber;
		Contact _contacts[8];
};

#endif