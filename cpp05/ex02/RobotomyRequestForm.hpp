/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:09:39 by kanahash          #+#    #+#             */
/*   Updated: 2025/09/30 22:09:40 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#define ROB_SIGN_GRADE 72
#define ROB_EXEC_GRADE 45

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    private:
        const std::string target;
    
    public:
        RobotomyRequestForm(const std::string& target);

        virtual ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& other);

        void executeAction() const;
};

#endif
