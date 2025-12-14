/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:59:53 by kanahash          #+#    #+#             */
/*   Updated: 2025/12/14 22:00:05 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iomanip>
#include <sstream>

class PhoneBook
{
	private:
		int index;
		Contact contact_lists[8];
		int num_contacts;
		void printContactlist();
		void incrementIndex();
		void printContact(int index);
		bool getIndexFromUser(int& selected_index);
		bool getContactDetails(Contact& contact);
	public:
	PhoneBook();
	~PhoneBook();

	bool addContact();
	bool searchContact();

};

#endif
