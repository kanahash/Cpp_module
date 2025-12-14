/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 00:30:10 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/13 00:49:46 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0)
{
}

Span::~Span()
{
}

Span::Span(unsigned int n) : N(n)
{
	numbers.reserve(N);
}

Span::Span(const Span& other) : N(other.N), numbers(other.numbers)
{
}

Span& Span::operator=(const Span& other)
{
	if(this != &other)
	{
		N = other.N;
		numbers = other.numbers;
	}
	return(*this);
}

void Span::addNumber(int number)
{
	if(numbers.size() >= N)
	{
		throw SpanFullException();
	}
	numbers.push_back(number);
}

long Span::shortestSpan() const
{
	if(numbers.size() <= 1)
	{
		throw NotEnoughElementsException();
	}

	long min_span = std::numeric_limits<long>::max();

	std::vector<int> sorted_numbers = numbers;
	std::sort(sorted_numbers.begin(), sorted_numbers.end());

	for(size_t i = 0; i < sorted_numbers.size() - 1; i++)
	{
		long span = static_cast<long>(sorted_numbers[i + 1]) - static_cast<long>(sorted_numbers[i]);

		if(span < min_span)
			min_span = span;
	}
	return(min_span);
}

long Span::longestSpan() const
{
	if(numbers.size() <= 1)
	{
		throw NotEnoughElementsException();
	}

	long min_val = static_cast<long>(*std::min_element(numbers.begin(), numbers.end()));
	long max_val = static_cast<long>(*std::max_element(numbers.begin(), numbers.end()));

	return(max_val - min_val);
}
