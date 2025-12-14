/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:54:35 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:54:36 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    std::cout << "--- Creating a FragTrap named FRAG-1 ---" << std::endl;
    FragTrap frag1("FRAG-1");
    std::cout << std::endl;

    std::cout << "--- Testing inherited functions ---" << std::endl;
    frag1.attack("enemy Robot");
    frag1.takeDamage(30);
    frag1.beRepaired(20);
    std::cout << std::endl;

    std::cout << "--- Testing FragTrap's unique function ---" << std::endl;
    frag1.highFivesGuys();
    std::cout << std::endl;

    std::cout << "--- Testing copy constructor and assignment operator ---" << std::endl;
    FragTrap frag2 = frag1;
    FragTrap frag3("FRAG-3");
    frag3 = frag1;
    std::cout << std::endl;

    std::cout << "--- Program ending, destructor will be called ---" << std::endl;

    return(0);    
}
