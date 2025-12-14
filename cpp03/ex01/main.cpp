/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:45:30 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:45:32 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "--- Creating a ScavTrap named SCV-1 ---" << std::endl;
    ScavTrap scav1("SCV-1");
    std::cout << std::endl;

    std::cout << "--- Testing inherited and overridden functions ---" << std::endl;
    scav1.attack("a Robot");
    scav1.takeDamage(10);
    scav1.beRepaired(5);
    std::cout << std::endl;

    std::cout << "--- Testing copy constructor and assignment operator ---" << std::endl;
    ScavTrap scav2 = scav1;
    ScavTrap scav3("SCV-3");
    scav3 = scav1;
    std::cout << std::endl;

    std::cout << "--- Program ending, destructor will be called ---" << std::endl;

    return(0);    
}
