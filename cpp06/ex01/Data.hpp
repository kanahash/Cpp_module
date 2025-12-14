/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 23:58:02 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/08 23:58:38 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>
#include <iomanip>

struct Data {
    int value;
    std::string name;
    
    Data();
    Data(int val, const std::string& n);
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();
};

#endif
