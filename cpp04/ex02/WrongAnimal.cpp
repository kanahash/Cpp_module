/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:10:51 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/05 23:14:21 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if(this != &src)
		this->type = src.type;
	return(*this);
}

std::string WrongAnimal::getType() const
{
	return(this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound... " << std::endl;
}
