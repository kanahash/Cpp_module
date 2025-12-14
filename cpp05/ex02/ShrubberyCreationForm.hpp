/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:09:45 by kanahash          #+#    #+#             */
/*   Updated: 2025/09/30 22:09:49 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <stdexcept>

#define SHR_SIGN_GRADE 145
#define SHR_EXEC_GRADE 137

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string target;

    public:
        ShrubberyCreationForm(const std::string& target);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        
        void executeAction() const;
};

#endif
