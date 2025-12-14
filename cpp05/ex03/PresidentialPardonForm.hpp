/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:09:33 by kanahash          #+#    #+#             */
/*   Updated: 2025/09/30 22:09:34 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#define PRD_SIGN_GRADE 25
#define PRD_EXEC_GRADE 5

class PresidentialPardonForm : public AForm
{
    private:
        const std::string target;

    public:
        PresidentialPardonForm(const std::string& target);
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);

        void executeAction() const;
};

#endif
