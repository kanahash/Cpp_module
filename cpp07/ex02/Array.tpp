/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:37:25 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/12 23:06:13 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
const char *Array<T>::OutofBoundsException::what() const throw()
{
	return("Array: Index is out of bounds!");
}

template <typename T>
Array<T>::Array() : array(NULL), _size(0)
{
	std::cout << "Array: Default constructed (size 0)." << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : array(NULL), _size(n)
{
	if(n > 0)
		array = new T[n]();
	std::cout << "Array: Constructed with size " << _size << "." << std::endl;
}

template <typename T>
Array<T>::Array(Array const &copy) : array(NULL), _size(copy._size)
{
	if(_size > 0)
	{
		array = new T[_size];

		for(unsigned int i = 0; i < _size; i++)
			array[i] = copy.array[i];
	}
}

template<typename T>
Array<T>::~Array()
{
	if(array)
		delete[] array;
	std::cout << "Array: Destroyed (size " << _size << ")." << std::endl;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &copy)
{
	if(this != &copy)
	{
		if(array)
			delete[] array;
		
		_size = copy._size;
		array = NULL;

		if(_size > 0)
		{
			array = new T[_size];

			for(unsigned int i = 0; i < _size; i++)
				array[i] = copy.array[i];
		}
	}
	return(*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if(i >= _size)
		throw OutofBoundsException();
	return(array[i]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int i)const
{
	if(i >= _size)
		throw OutofBoundsException();
	return(array[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return(_size);
}
