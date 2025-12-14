/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:25:58 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/25 16:37:46 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
	private:
		int value;
		static const int fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& copy);
		Fixed &operator=(const Fixed &src);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
