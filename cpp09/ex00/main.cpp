/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:48:41 by kanahash          #+#    #+#             */
/*   Updated: 2025/12/10 22:08:56 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return(1);
    }

    try
    {
        BitcoinExchange btc(DB_FILE_NAME);
        btc.execute(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return(1);
    }
    return(0);
}
