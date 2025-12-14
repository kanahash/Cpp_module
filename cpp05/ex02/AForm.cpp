/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:09:10 by kanahash          #+#    #+#             */
/*   Updated: 2025/09/30 22:09:11 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

AForm::AForm(const std::string name, const int sign_grade, const int execute_grade)
    : name(name), is_signed(false), sign_grade(sign_grade), execute_grade(execute_grade)
{
    if (sign_grade < MAX_GRADE || execute_grade < MAX_GRADE)
        throw AForm::GradeTooHighException();
    if (sign_grade > MIN_GRADE || execute_grade > MIN_GRADE)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    :name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), execute_grade(other.execute_grade)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

const std::string& AForm::getName() const
{
    return name;
}

bool AForm::getSignedStatus() const
{
    return(is_signed);
}

int AForm::getSignGrade() const
{
    return(sign_grade);
}

int AForm::getExecuteGrade() const
{
    return(execute_grade);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if(is_signed)
    {
        return;
    }
    if(bureaucrat.getGrade() > sign_grade)
    {
        throw AForm::GradeTooLowException();
    }
    is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return("AForm: Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return("AForm: Grade is too low");
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "AForm: " << form.getName() << std::endl;
    os << "Signed: " << (form.getSignedStatus() ? "Yes" : "No") << std::endl;
    os << "Grade required to sign: " << form.getSignGrade() << std::endl;
    os << "Grade required to execute: " << form.getExecuteGrade() << std::endl;

    return(os);
}

void AForm::execute(Bureaucrat const& executor) const
{
    if(!is_signed)
    {
        throw AForm::FormNotSignedException();
    }

    if(executor.getGrade() > execute_grade)
    {
        throw AForm::GradeTooLowException();
    }

    executeAction();
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return("AForm: Form is not signed");
}
