/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:26:15 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/25 21:16:32 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << fractionalBits;
}
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &src)
		this->value = src.getRawBits();
	return(*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return((float)this->value / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return(this->value >> fractionalBits);
}


bool Fixed::operator>(const Fixed& other) const
{
		return(this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
		return(this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
		return(this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
		return(this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
		return(this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
		return(this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return(Fixed(this->getRawBits() + other.getRawBits()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return(Fixed(this->getRawBits() - other.getRawBits()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return(Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if(other.getRawBits() == 0)
	{
		std::cerr << "Error: Division by zero!" << std::endl;
		return(Fixed(0));
	}
	return(Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++()
{
	this->value++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->value++;
	return(tmp);
}

Fixed& Fixed::operator--()
{
	this->value--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->value--;
	return(tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return((a.getRawBits() < b.getRawBits()) ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return((a.getRawBits() > b.getRawBits()) ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return((a.getRawBits() < b.getRawBits()) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return((a.getRawBits() > b.getRawBits()) ? a : b);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return(os);
}
