/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:48:20 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/16 00:57:46 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombieHorde;
	int i;

	zombieHorde = new Zombie[N];

	i = 0;
	while(i < N)
	{
		zombieHorde[i] = Zombie(name);
		i++;
	}
	return(zombieHorde);
}
