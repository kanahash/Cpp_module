/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:09:35 by kanahash          #+#    #+#             */
/*   Updated: 2025/09/30 22:09:37 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):AForm("Robotomy Request Form", ROB_SIGN_GRADE, ROB_EXEC_GRADE), target(target)
{
    std::cout << "RobotomyRequestForm for target " << target << " constructed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm fot target " << target << " destructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):AForm(other), target(other.target)
{
    std::cout << "RobotomyRequestForm copy constructed." << std::endl;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "* VZZZZZZZZ... KRRRRRRRRR... *" << std::endl;

    if(std::rand() % 2)
    {
        std::cout << this->target << "has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy for " << this->target << " failed." << std::endl;
    }
}
