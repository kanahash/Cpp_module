/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:19:23 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/05 23:24:41 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "--- Polymorphism Test ---" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "j's type: " << j->getType() << std::endl;
	std::cout << "i's type: " << i->getType() << std::endl;

	std::cout << "--- Calling makeSound() ---" << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;

	std::cout << "--- Non-Polymorphism Test ---" << std::endl;
	
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongI = new WrongCat();
	
	std::cout << "wrongI's type: " << wrongI->getType() << std::endl;
	
	std::cout << "--- Calling makeSound() ---" << std::endl;
	
	wrongI->makeSound();
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongI;

	return(0);
}
