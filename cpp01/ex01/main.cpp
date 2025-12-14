/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:53:55 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/16 01:01:26 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *Zombie_horde;
	int N;
	int i;

	i = 0;
	N = 5;
	Zombie_horde = zombieHorde(N, "Zombie_Horde"); 
	while(i < N)
	{
		std::cout << "Index " << i << ": " << std::endl;
		Zombie_horde[i].announce();
		i++;
	}
	delete[] Zombie_horde;
	return(0);
}
