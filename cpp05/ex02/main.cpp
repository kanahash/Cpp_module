/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:09:05 by kanahash          #+#    #+#             */
/*   Updated: 2025/09/30 22:09:25 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

void test_form_creation(const std::string& name, int sign_grade, int exec_grade)
{
    (void)name, (void)sign_grade, (void)exec_grade;
}

int main(void)
{
    std::srand(std::time(NULL));

    std::cout << "--------------------- Ex02 Test ---------------------" << std::endl;
    std::cout << std::endl;

    Bureaucrat boss("Zaphod", 1);
    Bureaucrat high_mid("Arthur", 40);
    Bureaucrat low_mid("Ford", 140);
    Bureaucrat intern("Trillian", 150);
    std::cout << std::endl;

    AForm *shrubbery = new ShrubberyCreationForm("Home");
    AForm *robotomy  = new RobotomyRequestForm("KannaHash");
    AForm *pardon    = new PresidentialPardonForm("Criminal");
    AForm *unsigned_f = new ShrubberyCreationForm("Office");
    std::cout << std::endl;

    std::cout << "--------------------- EXECUTION FAILURE TESTS ---------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "[2.1] Attempting to execute UN-SIGNED Shrubbery (Intern G150):" << std::endl;
    intern.executeForm(*unsigned_f);
    low_mid.signForm(*shrubbery);
    std::cout << std::endl;

    std::cout << "[2.2] Attempting to execute Shrubbery (low_mid G140):" << std::endl;
    std::cout << std::endl;

    low_mid.executeForm(*shrubbery); 
    high_mid.signForm(*pardon);
    high_mid.executeForm(*pardon);

    std::cout << "--------------------- EXECUTION SUCCESS TESTS ---------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "[3.1] Shrubbery (G145/G137) Execution by Boss (G1):" << std::endl;
    std::cout << std::endl;

    boss.signForm(*shrubbery);
    boss.executeForm(*shrubbery);

    std::cout << "[3.2] Presidential Pardon (G25/G5) Execution by Boss (G1):" << std::endl;
    std::cout << std::endl;

    boss.signForm(*pardon);
    boss.executeForm(*pardon);

    std::cout << "\n[3.3] Robotomy (G72/G45) Execution 6 times by Arthur (G40):" << std::endl;
    std::cout << std::endl;

    high_mid.signForm(*robotomy);

    for (int i = 0; i < 6; ++i)
    {
        high_mid.executeForm(*robotomy);
    }

    std::cout << "--------------------- CLEANUP ---------------------" << std::endl;
    delete shrubbery;
    delete robotomy;
    delete pardon;
    delete unsigned_f;

    return(0);
}
