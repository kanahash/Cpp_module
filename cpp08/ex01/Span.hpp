/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:16:48 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/13 00:53:15 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <cmath>
#include <limits>
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

class SpanException : public std::exception {};

class SpanFullException : public SpanException
{
	public:
		virtual const char* what() const throw()
		{
			return("Span: Cannot add number. The Span is already full.");
		}
};

class NotEnoughElementsException : public SpanException
{
	public:
		virtual const char* what() const throw()
		{
			return("Span: Not enough elements to calculate a span (need at least 2).");
		}
};

class Span
{
	private:
		unsigned int N;
		std::vector<int> numbers;

		Span();
	
	public:
		Span(unsigned int n);
		~Span();
		Span(const Span &other);
		Span& operator=(const Span& other);

		void addNumber(int number);

		template<typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			unsigned int count = 0;
			for(Iterator it = begin; it != end; it++)
			{
				count++;
			}

			if(numbers.size() + count > N)
			{
				throw SpanFullException();
			}
			
			numbers.insert(numbers.end(), begin, end);
		}

		long shortestSpan() const;
		long longestSpan() const;

		unsigned int getSize() const {return(numbers.size());}
};

#endif
