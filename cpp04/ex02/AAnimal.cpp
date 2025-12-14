/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:46:21 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 14:55:58 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal" )
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal &src)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if(this != &src)
		this->type = src.type;
	return(*this);
}

std::string AAnimal::getType() const
{
	return(this->type);
}
