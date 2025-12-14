/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 23:40:39 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/12 23:56:07 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void test_easyfind(T& container, int value)
{
	std::cout << "--- Searching for value: " << value << " ---" << std::endl;

	try
	{
		typename T::iterator it = easyfind(container, value);

		std::cout <<"Success: value " << *it << " found at position " << std::distance(container.begin(), it) << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Failue (Expected): " << e.what() << std::endl;
	}
}

int main(void)
{

	std::cout << "--------------------- (Test) std::vector ---------------------" << std::endl;
	std::cout << std::endl;

	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(20);
	vec.push_back(50);

	test_easyfind(vec, 20);
	test_easyfind(vec, 50);
	test_easyfind(vec, 99);

	std::cout << std::endl;

	std::cout << "--------------------- (Test) std::list ---------------------" << std::endl;
	std::cout << std::endl;

	std::list<int> list;
	list.push_back(5);
	list.push_back(15);
	list.push_back(25);

	test_easyfind(list, 15);
	test_easyfind(list, 0);

	std::cout << std::endl;

	std::cout << "--------------------- (Test) empty container ---------------------" << std::endl;
	std::cout << std::endl;

	std::vector<int> empty_vec;
	
	test_easyfind(empty_vec, 1);

	std::cout << std::endl;

	std::cout << "--------------------- finish!!!!! ---------------------" << std::endl;
	return(0);
}
