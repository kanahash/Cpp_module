/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:54:23 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:54:24 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
    protected:
            std::string name;
            unsigned int hit_points;
            unsigned int energy_points;
            unsigned int attack_damage;
    public:
            ClapTrap();
            virtual ~ClapTrap();
            ClapTrap(const ClapTrap& other);
            ClapTrap& operator=(const ClapTrap& other);
            ClapTrap(std::string name);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
