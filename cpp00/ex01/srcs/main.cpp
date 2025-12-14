/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:03:47 by kanahash          #+#    #+#             */
/*   Updated: 2025/12/14 22:03:50 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phonebook;
    std::string input;

    while(1)
    {
        if(!std::getline(std::cin, input) || std::cin.eof())
            break;
        if(input == "ADD")
        {
            if(!phonebook.addContact())
                break;
        }
        else if(input == "SEARCH")
        {
            if(!phonebook.searchContact())
                break;
        }
        else if(input == "EXIT")
            break;
    }
    std::cout << std::endl;
    return(0);
}
