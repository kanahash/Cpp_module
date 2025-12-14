/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 23:31:30 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/12 23:43:13 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

#include <iostream>
#include <vector>
#include <list>

template<typename T>
typename T::iterator easyfind(T&container, int value);

#include "easyfind.tpp"

#endif