/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:50:47 by kanahash          #+#    #+#             */
/*   Updated: 2025/09/30 22:10:35 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test_creation(const std::string& name, int grade)
{
	try
	{
		Bureaucrat b(name, grade);
		std::cout << "Successfully created " << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed to create " << name << " with grade " << ". Exception: " << e.what() << std::endl;
	}
	
}

void test_increment(Bureaucrat& b)
{
	try
	{
		std::cout << "Attempting to increment " << b << std::endl;
		b.incrementGrade();
		std::cout << "Increment successful: " << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed to increment " << b.getName() << ". Exception: " << e.what() << std::endl;
	}
	
}

void test_decrement(Bureaucrat& b)
{
	try
	{
		std::cout << "Attemnpting to decrement " << b << std::endl;
		b.decrementGrade();
		std::cout << "Decrement successful: " << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed to decrement " << b.getName() << ". Exception: " << e.what() << std::endl;
	}
	
}

int main(void)
{
	std::cout << "--- Ex00 Test ---" << std::endl;
	std::cout << std::endl;

	std::cout << "--- Testing Bureaucrat constructor ---" << std::endl;
	test_creation("John Doe", 75);
	test_creation("GradeTooHigh", 0);
	test_creation("GradeTooLow", 151);
	std::cout << std::endl;

	std::cout << "--- Testing grade increment/decrement ---" << std::endl;
	Bureaucrat normal("Normal", 100);
	test_increment(normal);
	test_decrement(normal);
	std::cout << std::endl;

	std::cout << "--- Testing grade boundaries ---" << std::endl;
	Bureaucrat highest("Highest", 1);
	test_increment(highest);

	std::cout << std::endl;

	Bureaucrat lowest("Lowest", 150);
	test_decrement(lowest);
	std::cout << std::endl;

	return(0);
}
