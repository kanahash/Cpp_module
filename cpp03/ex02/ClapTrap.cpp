/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:54:19 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:54:21 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    :name("Default"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    :name(other.name), hit_points(other.hit_points), energy_points(other.energy_points),attack_damage(other.attack_damage)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if(this != &other)
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return(*this);
}

ClapTrap::ClapTrap(std::string name)
    : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(this->energy_points > 0 && this->hit_points > 0)
    {
        this->energy_points--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " has no energy or hit points left to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->hit_points > amount)
    {
        this->hit_points -= amount;
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl; 
    }
    else
    {
        this->hit_points = 0;
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage and is now dead!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->energy_points > 0 && this->hit_points > 0)
    {
        this->energy_points--;
        this->hit_points += amount;
        std::cout <<"ClapTrap " << this->name << " repairs itself for " <<amount << " hit points!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " has no energy or hit points left to repair itself!" << std::endl;
}

