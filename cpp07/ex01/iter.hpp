/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 21:20:20 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/12 21:31:42 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename F>
void iter(T* array, size_t len, F function) 
{
	for(size_t i = 0; i < len; i++)
		function(array[i]);
}

template <typename T, typename F>
void iter(const T* array, size_t len, F function) 
{
	for(size_t i = 0; i < len; i++)
		function(array[i]);
}

#endif
