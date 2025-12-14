/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:10:20 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/13 21:22:31 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack& operator=(const MutantStack& other);

		iterator begin();
		iterator end();

		const_iterator begin() const;
		const_iterator end() const;
};

#include "MutantStack.tpp"

#endif
