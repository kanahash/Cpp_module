/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:28:00 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/12 23:08:12 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T *array;
		unsigned int _size;
	
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(Array const &copy);

	Array &operator=(Array const &copy);
	T &operator[](unsigned int i);
	T const &operator[](unsigned int i)const;

	unsigned int size() const;

	class OutofBoundsException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#include "Array.tpp"

#endif
