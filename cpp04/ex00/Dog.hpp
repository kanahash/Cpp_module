/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:34:58 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/05 22:36:25 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &src);

	virtual void makeSound() const;
};

#endif
