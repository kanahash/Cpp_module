/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:19:23 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 15:02:49 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define ANIMALS_COUNT 4

int main(void)
{
	std::cout << "--- Creating an array of Dogs and Cats ---" << std::endl;
	AAnimal* animals[ANIMALS_COUNT];

	for (int i = 0; i < ANIMALS_COUNT / 2; i++)
		animals[i] = new Dog;
	for (int i = ANIMALS_COUNT / 2; i < ANIMALS_COUNT; i++)
		animals[i] = new Cat();
	std::cout << std::endl;

	std::cout << "--- Deleting the array of Animals ---" << std::endl;
	for (int i = 0; i < ANIMALS_COUNT; i++)
		delete animals[i];
	std::cout << std::endl;
	
	std::cout << "--- Deep Copy Test ---" << std::endl;
	Dog originalDog;

	Dog copiedDog = originalDog;

	std::cout << "Original Dog type: " << originalDog.getType() << std::endl;
	std::cout << "Copied Dog type: " << copiedDog.getType() << std::endl;

	std::cout << "Original Dog's brain address: " << originalDog.getBrain() << std::endl;
	std::cout << "Copied Dog's brain address: " << copiedDog.getBrain() << std::endl;

	if(originalDog.getBrain() != copiedDog.getBrain())
		std::cout << "--> Deep copy successful! Brain addresses are different." << std::endl;
	else
		std::cout << "--> Shallow copy detected! Brain address are the same." << std::endl;

	std::cout << "--- End of Deep Copy Test ---" << std::endl;
	std::cout << std::endl;

	return(0);
}
