/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 23:34:35 by kanahash          #+#    #+#             */
/*   Updated: 2025/09/30 22:09:54 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << this->name << " destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
// {
//     std::cout << "Bureaucrat copy constructor called" << std::endl;
//     if(this != &src)
//         this->grade = src.getGrade();
//     return(*this);
// }

Bureaucrat::Bureaucrat(const std::string&name, int grade) : name(name)
{
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
    std::cout << "Bureaucrat" << this->name << " create with grade " << this->grade << std::endl;
}

const std::string& Bureaucrat::getName() const
{
    return(this->name);
}

int Bureaucrat::getGrade() const
{
    return(this->grade);
}

void Bureaucrat::incrementGrade()
{
    if(this->grade <= 1)
	{
        throw Bureaucrat::GradeTooHighException();
	}
	this->grade--;
    std::cout << this->name << " grade incremented to " << this->grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
    if(this->grade >= 150)
	{
        throw Bureaucrat::GradeTooLowException();
	}
	this->grade++;
    std::cout << this->name << " grade decremented to " << this->grade << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade is too low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return(os);
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);

        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cout << this->name << "couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
    
}
