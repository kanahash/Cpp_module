/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:41:09 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/17 00:33:21 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : type("unarmed")
{
}

Weapon::Weapon(std::string type) : type(type)
{
	
}

Weapon::~Weapon(void)
{
}

const std::string& Weapon::getType() const
{
	return(this->type);
}

void Weapon::setType(const std::string& newType)
{
	this->type = newType;
}
