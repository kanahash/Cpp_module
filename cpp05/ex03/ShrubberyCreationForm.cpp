/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:09:42 by kanahash          #+#    #+#             */
/*   Updated: 2025/09/30 22:09:43 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

static const char* const ASCII_TREE = 
    "      /\\      \n"
    "     /\\*\\     \n"
    "    /\\O\\*\\    \n"
    "   /\\/\\/\\/\\   \n"
    "  /\\*\\****\\O\\  \n"
    " /\\O\\*\\O\\*\\*\\ \n"
    "/\\*\\O\\*\\*\\/\\/\\\n"
    "      ||      \n";

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):AForm("Shrubbery Creation Form", SHR_SIGN_GRADE, SHR_EXEC_GRADE), target(target)
{
    std::cout << "ShrubberyCreationForm for target " << target << " constructed." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm for target " << target << " destructed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):AForm(other), target(other.target)
{
    std::cout << "ShrubberyCreationForm copy constructed." << std::endl;
}

void ShrubberyCreationForm::executeAction() const
{
    std::string filename = this->target + "_shrubbery";
    std::ofstream ofs(filename.c_str());

    if(!ofs.is_open())
    {
        throw std::runtime_error("Could not open/create file " + filename);
    }
     ofs << ASCII_TREE;

    ofs.close();
    std::cout << "Successfully created shrubbery file: " << filename << std::endl;
}
