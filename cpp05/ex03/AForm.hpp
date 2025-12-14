/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:54:15 by kanahash          #+#    #+#             */
/*   Updated: 2025/09/30 22:09:15 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#define MAX_GRADE 1
#define MIN_GRADE 150

#include <exception>
#include <ostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string name;
		bool is_signed;
		const int sign_grade;
		const int execute_grade;

	public:
		virtual ~AForm();
		AForm(const std::string name, const int sign_grade, const int execute_grade);
		AForm(const AForm &other);

		const std::string& getName() const;
		bool getSignedStatus() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(const Bureaucrat& bureaucrat);

        void execute(Bureaucrat const& executor) const;

        virtual void executeAction() const = 0;

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

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
