/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:09:59 by kanahash          #+#    #+#             */
/*   Updated: 2025/09/30 22:10:10 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
    :name("Default Form"), is_signed(false), sign_grade(MIN_GRADE), execute_grade(MIN_GRADE)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int sign_grade, const int execute_grade)
    : name(name), is_signed(false), sign_grade(sign_grade), execute_grade(execute_grade)
{
    if (sign_grade < MAX_GRADE || execute_grade < MAX_GRADE)
        throw Form::GradeTooHighException();
    if (sign_grade > MIN_GRADE || execute_grade > MIN_GRADE)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
    :name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), execute_grade(other.execute_grade)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

const std::string& Form::getName() const
{
    return name;
}

bool Form::getSignedStatus() const
{
    return(is_signed);
}

int Form::getSignGrade() const
{
    return(sign_grade);
}

int Form::getExecuteGrade() const
{
    return(execute_grade);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if(is_signed)
    {
        return;
    }
    if(bureaucrat.getGrade() > sign_grade)
    {
        throw Form::GradeTooLowException();
    }
    is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return("Form: Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return("Form: Grade is too low");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName() << std::endl;
    os << "Signed: " << (form.getSignedStatus() ? "Yes" : "No") << std::endl;
    os << "Grade required to sign: " << form.getSignGrade() << std::endl;
    os << "Grade required to execute: " << form.getExecuteGrade() << std::endl;

    return(os);
}
