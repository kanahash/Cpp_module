/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:52:29 by kanahash          #+#    #+#             */
/*   Updated: 2026/01/14 20:52:30 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <climits>

class RPN
{
    private:
        std::stack<int> stack;

    public:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);

        void calculate(const std::string &expression);
};

#endif
