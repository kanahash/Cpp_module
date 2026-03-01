/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:52:50 by kanahash          #+#    #+#             */
/*   Updated: 2026/03/01 19:16:44 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if(ac < 2)
    {
        std::cerr << "Error: No arguments provided." << std::endl;
        return(1);
    }
    PmergeMe solver;

    solver.run(ac, av);

    return(0);
}
