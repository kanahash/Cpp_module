/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:32:05 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:32:07 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    int i;

    ClapTrap clap("CL4P-TP");
    ClapTrap defaultClap;
    
    std::cout << "--- Attack Test ---" << std::endl;
    clap.attack("a bad guy");
    clap.attack("another bad guy");
    std::cout << std::endl;

    std::cout << "--- Take Damage Test ---" << std::endl;
    clap.takeDamage(5);
    clap.takeDamage(10);
    std::cout << std::endl;

    std::cout << "--- Repair Test ---" << std::endl;
    clap.beRepaired(5);
    std::cout << std::endl;

    std::cout << "--- Default ClapTrap Test ---" << std::endl;
    defaultClap.attack("target");
    defaultClap.takeDamage(3);
    defaultClap.beRepaired(2);
    std::cout << std::endl;

    std::cout << "--- Energy Exhaustion Test ---" << std::endl;
    ClapTrap runner("RUNNER");
    i = 0;
    while(i < 11)
    {
        runner.attack("a tree");
        i++;
    }
    runner.beRepaired(1);
    std::cout << std::endl;

    return(0);    
}