/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:08:16 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 14:42:02 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	int i;

	i = 0;
	std::cout << "Brain copy constructor called" << std::endl;
	while(i < 100)
	{
		this->ideas[i] = copy.ideas[i];
		i++;
	}
}

Brain& Brain::operator=(const Brain &src)
{
	int i;

	i = 0;
	std::cout << "Brain copy assignment operator called" << std::endl;
	if(this != &src)
	{
		while(i < 100)
		{
			this->ideas[i] = src.ideas[i];
			i++;
		}
	}
	return(*this);
}
