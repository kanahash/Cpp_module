/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:46:21 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/05 22:59:07 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal" )
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal& Animal::operator=(const Animal &src)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if(this != &src)
		this->type = src.type;
	return(*this);
}

std::string Animal::getType() const
{
	return(this->type);
}

void Animal::makeSound() const
{
	std::cout << "Animal doesn't make any sound... " << std::endl;
}
