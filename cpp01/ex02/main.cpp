/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:53:56 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/16 23:10:07 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";

	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "--- Memory address ---" << std::endl;
	std::cout << "Memory address of str: " << &str << std::endl;
	std::cout << "Memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl;
	std::cout << "----------------------" << std::endl; 
	std::cout << std::endl;

	std::cout << "------- Values -------" << std::endl;
	std::cout <<"Value of str: " << str << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;

	return(0);
}
