/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 23:57:57 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/08 23:57:58 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : value(0), name("default") {}

Data::Data(int val, const std::string& n) : value(val), name(n) {}

Data::Data(const Data& other) : value(other.value), name(other.name) {}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        value = other.value;
        name = other.name;
    }
    return *this;
}

Data::~Data() {}
