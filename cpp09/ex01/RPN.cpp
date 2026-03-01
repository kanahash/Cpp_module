/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:52:20 by kanahash          #+#    #+#             */
/*   Updated: 2026/01/14 20:52:22 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}
RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN &other)
{
    if(this != &other)
    {
        this->stack = other.stack;
    }
    return(*this);
}

void RPN::calculate(const std::string &expression)
{
    std::stringstream ss(expression);
    std::string token;

    while(!stack.empty()) stack.pop();
    
    while(ss >> token)
    {
        if(token.length() == 1 && std::isdigit(token[0]))
        {
            stack.push(token[0] - '0');
        }
        else if(token.length() == 1 && std::string("+-*/").find(token) != std::string::npos)
        {
            if(stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return;
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            if(token == "+")
                stack.push(a + b);
            else if(token == "-")
                stack.push(a - b);
            else if(token == "*")
                stack.push(a * b);
            else if(token == "/")
            {
                if(b == 0)
                {
                    std::cerr << "Error" << std::endl;
                    return;
                }
                stack.push(a / b);
            }
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return;
        }
    }
    if(stack.size() == 1)
    {
        std::cout << stack.top() << std::endl;
    }
    else
    {
        std::cerr << "Error" << std::endl;
    }
}
