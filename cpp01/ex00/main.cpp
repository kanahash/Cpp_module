/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:44:29 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/16 00:08:34 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *new_Zombie;

	new_Zombie = newZombie("New_Zombie");
	new_Zombie->announce();
	randomChump("random_Zombie");
	delete(new_Zombie);
	return(0);
}
