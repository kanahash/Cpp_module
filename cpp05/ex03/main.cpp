/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:09:05 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/02 20:27:43 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
	std::srand(std::time(NULL));

	std::cout << "--------------------- Ex03 Intern Test ---------------------" << std::endl;
	std::cout << std::endl;

	Bureaucrat boss("Zaphod", 1);
	Bureaucrat high_mid("Arthur", 40);
	Intern someRandomIntern;
	AForm* form1 = NULL;
	AForm* form2 = NULL;
	AForm* form3 = NULL;
	AForm* form_fail = NULL;

	std::cout << "--------------------- Intern makeForm Test ---------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "[2.1] Creating 'robotomy request' for 'Bender':" << std::endl;
	form1 = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << std::endl;

	std::cout << "[2.2] Creating 'shrubbery creation' for 'Forest':" << std::endl;
	form2 = someRandomIntern.makeForm("shrubbery creation", "Forest");
	std::cout << std::endl;

	std::cout << "[2.3] Creating 'presidential pardon' for 'Lister':" << std::endl;
	form3 = someRandomIntern.makeForm("presidential pardon", "Lister");
	std::cout << std::endl;

	std::cout << "[2.4] Attempting to create 'unknown form':" << std::endl;
	form_fail = someRandomIntern.makeForm("unknown form", "ErrorTarget");
	std::cout << std::endl;

	std::cout << "--------------------- FORM EXECUTION TEST ---------------------" << std::endl;
	std::cout << std::endl;

	if(form1)
	{
		std::cout << "[3.1] Testing created Robotomy Form (G40 Arthur):" << std::endl;
		high_mid.signForm(*form1);
		for(int i = 0; i < 2; ++i)
		{
			high_mid.signForm(*form1);
		}
		std::cout << std::endl;
	}

	if(form2)
	{
		std::cout << "[3.2] Testing created Shrubbery Form (G1 Boss):" << std::endl;

		boss.signForm(*form2);
		boss.executeForm(*form2);
		
		std::cout << std::endl;
	}

	if(form3)
	{
		std::cout << "[3.3] Testing created Pardon Form (G1 Boss):" << std::endl;
		boss.signForm(*form3);
		boss.executeForm(*form3);

		std::cout << std::endl;
	}

	std::cout << "\n--------------------- CLEANUP ---------------------" << std::endl;
	delete form1;
	delete form2;
	delete form3;
	delete form_fail;
	
	return (0);
}
