/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:11:31 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 14:55:24 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include<string>
#include<iostream>

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(const AAnimal &copy);
		AAnimal &operator=(const AAnimal &src);

		std::string getType() const;
		virtual void makeSound() const = 0;
		
};

#endif
