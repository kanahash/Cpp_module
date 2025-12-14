/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:54:15 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/02 19:42:15 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#define MAX_GRADE 1
#define MIN_GRADE 150

#include <exception>
#include <ostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int sign_grade;
		const int execute_grade;

	public:
		Form();
		~Form();
		Form(const std::string name, const int sign_grade, const int execute_grade);
		Form(const Form &other);

		const std::string& getName() const;
		bool getSignedStatus() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
