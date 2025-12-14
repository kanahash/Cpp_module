/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 21:03:39 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/12 21:16:17 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T& min(const T &a, const T &b)
{
	if(a < b)
		return(a);
	else
		return(b);
}

template <typename T>
const T& max(const T &a, const T &b)
{
	if(a <= b)
		return(b);
	else
		return(a);
}

#endif
