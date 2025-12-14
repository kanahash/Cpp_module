/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:34:58 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 15:01:42 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain* brain;
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &src);

	virtual void makeSound() const;
	const Brain* getBrain() const;
};

#endif
