/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:47:26 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/02 20:08:42 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

typedef AForm* (*FormCreator)(const std::string& target);

static AForm* createRobotomyRequestForm(const std::string& target)
{
	return(new RobotomyRequestForm(target));
}

static AForm* createPresidentialPardonForm(const std::string& target) {
    return (new PresidentialPardonForm(target));
}

static AForm* createShrubberyCreationForm(const std::string& target) {
    return (new ShrubberyCreationForm(target));
}

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern copy assignment operator  called" << std::endl;
	(void)other;
	return(*this);
}


AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	struct FormInfo
	{
		std::string name;
		FormCreator creator;
	};

    const FormInfo formTable[] = 
	{
        {"robotomy request", createRobotomyRequestForm},
        {"presidential pardon", createPresidentialPardonForm},
        {"shrubbery creation", createShrubberyCreationForm}
    };

	const int numForms = sizeof(formTable) / sizeof(formTable[0]);
	AForm* newForm = NULL;
	int foundIndex = -1;

	for(int i = 0; i < numForms; ++i)
	{
		if(formTable[i].name == formName)
		{
			foundIndex = i;
			break;
		}
	}
	if(foundIndex != -1)
	{
		newForm = formTable[foundIndex].creator(target);
		std::cout << "Intern creates " << newForm->getName() << std::endl;
	}
	else
	{
		std::cerr << "Intern error: Form name '" << formName << "' does not exist." << std::endl;
	}

	return(newForm);
}
