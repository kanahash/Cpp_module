/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:59:42 by kanahash          #+#    #+#             */
/*   Updated: 2025/12/14 21:59:46 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include<iostream>
#include<string>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact();
		~Contact();

		const std::string& getFirstName() const;
		const std::string& getLastName() const;
		const std::string& getNickName() const;
		const std::string& getPhoneNumber() const;
		const std::string& getDarkestSecret() const;

		void setFirstName(const std::string& name);
		void setLastName(const std::string& name);
		void setNickName(const std::string& name);
		void setPhoneNumber(const std::string& name);
		void setDarkestSecret(const std::string& name);
};

#endif
