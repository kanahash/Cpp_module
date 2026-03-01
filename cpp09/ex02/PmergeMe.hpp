/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:52:50 by kanahash          #+#    #+#             */
/*   Updated: 2026/03/01 20:19:41 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <climits>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::deque<int> deq;

	void sortVector(std::vector<int>& arr);
	void sortDeque(std::deque<int>& arr);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		
		void run(int ac, char **av);
};

#endif
