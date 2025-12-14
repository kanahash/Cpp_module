/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:50:47 by kanahash          #+#    #+#             */
/*   Updated: 2025/09/30 22:10:18 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// void test_creation(const std::string& name, int grade)
// {
// 	try
// 	{
// 		Bureaucrat b(name, grade);
// 		std::cout << "Successfully created " << b << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "Failed to create " << name << " with grade " << ". Exception: " << e.what() << std::endl;
// 	}
	
// }

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

// void test_decrement(Bureaucrat& b)
// {
// 	try
// 	{
// 		std::cout << "Attemnpting to decrement " << b << std::endl;
// 		b.decrementGrade();
// 		std::cout << "Decrement successful: " << b << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "Failed to decrement " << b.getName() << ". Exception: " << e.what() << std::endl;
// 	}
	
// }

void test_form_creation(const std::string& name, int sign_grade, int exec_grade)
{
	try
	{
		Form f(name, sign_grade, exec_grade);
		std::cout << "Successfully created form: " << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed to create form " << name << "Exception: " << e.what() << std::endl;
	}
	
}

int main(void)
{
	std::cout << "--------------------- Ex01 Test ---------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "--------------------- Form Creation Tests (Grade Boundaries) ---------------------" << std::endl;
	test_form_creation("Standard Form", 50, 50);
	test_form_creation("Bad Sign Grade", 0, 100); //Too high
	test_form_creation("Bad Exec Grade", 100, 151); //Too low
	std::cout << std::endl;

	std::cout << "--------------------- Form Signing Tests ---------------------" << std::endl;
	Bureaucrat high_grade_b("Boss", 5);
	Bureaucrat low_grade_b("Intern", 150);
	Bureaucrat mid_grade_b("MidLevel", 25);

	Form high_req_f("Treaty", 10, 5);
	Form mid_req_f("Vacation", 50, 50);
	Form low_req_f("Receipt", 140, 140);

	std::cout << std::endl;

	std::cout << "--------------------- Test 1: Successful Sign ---------------------" << std::endl;
	high_grade_b.signForm(high_req_f);
	std::cout << "Form status: " << high_req_f << std::endl;

	std::cout << std::endl;

	std::cout << "--------------------- Test 2: Grade Too Low ---------------------" << std::endl;
	low_grade_b.signForm(mid_req_f);
	std::cout << "Form status: " << mid_req_f << std::endl;
	
	std::cout << std::endl;

	std::cout << "--------------------- Test 3: Borderline Sign ---------------------" << std::endl;
	mid_grade_b.signForm(high_req_f);
	mid_grade_b.signForm(mid_req_f);
	std::cout << "Form status: " << mid_req_f << std::endl;

	std::cout << "--------------------- Test 4: Successful Sign ---------------------" << std::endl;
	low_grade_b.signForm(low_req_f);
	
	test_increment(low_grade_b);
	test_increment(low_grade_b);
	test_increment(low_grade_b);
	test_increment(low_grade_b);
	test_increment(low_grade_b);
	test_increment(low_grade_b);
	test_increment(low_grade_b);
	test_increment(low_grade_b);
	test_increment(low_grade_b);
	test_increment(low_grade_b);

	low_grade_b.signForm(low_req_f);
	std::cout << "Form status: " << low_req_f << std::endl;
	
	std::cout << std::endl;

	return(0);
}
