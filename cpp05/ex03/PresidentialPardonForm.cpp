/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:09:30 by kanahash          #+#    #+#             */
/*   Updated: 2025/09/30 22:09:31 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):AForm("Presidential Pardon Form", PRD_SIGN_GRADE, PRD_EXEC_GRADE), target(target)
{
    std::cout << "PresidentialPardonForm for target " << target << " constructed." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm for target " << target << " destructed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):AForm(other), target(other.target)
{
    std::cout << "PresidentialPardonForm copy constructed." << std::endl;
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
