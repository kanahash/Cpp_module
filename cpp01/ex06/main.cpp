/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:39:11 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/24 14:42:20 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	if(ac != 2)
	{
		std::cout << "Usage: ./harlFilter <LOG_LEVEL>" << std::endl;
		std::cout << "Available levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return(1);
	}
	harl.complain(av[1]);
	return(0);
}
