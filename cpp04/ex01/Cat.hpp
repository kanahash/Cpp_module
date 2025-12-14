/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:26:03 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/05 22:34:43 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &src);

	virtual void makeSound() const;
};

#endif
