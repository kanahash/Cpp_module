/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:00:49 by kanahash          #+#    #+#             */
/*   Updated: 2025/12/14 22:03:06 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact():
	first_name(""),
	last_name(""),
	nickname(""),
	phone_number(""),
	darkest_secret("")
	{
	}

Contact::~Contact()
{
}

const std::string& Contact::getFirstName() const
{
	return(first_name);
}

const std::string& Contact::getLastName() const
{
	return(last_name);
}

const std::string& Contact::getNickName() const
{
	return(nickname);
}

const std::string& Contact::getPhoneNumber() const
{
	return(phone_number);
}

const std::string& Contact::getDarkestSecret() const
{
	return(darkest_secret);
}

void Contact::setFirstName(const std::string& name)
{
	first_name = name;
}

void Contact::setLastName(const std::string& name)
{
	last_name = name;
}

void Contact::setNickName(const std::string& name)
{
	nickname = name;
}

void Contact::setPhoneNumber(const std::string& name)
{
	phone_number = name;
}

void Contact::setDarkestSecret(const std::string& name)
{
	darkest_secret = name;
}
