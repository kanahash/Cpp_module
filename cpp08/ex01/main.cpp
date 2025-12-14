/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 01:00:47 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/13 01:00:49 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib> 
#include <ctime>   

void subjectTest()
{
    std::cout << "--------------------- (Test) Subject Example ---------------------" << std::endl;
    std::cout << std::endl;
    
    std::cout << "--- Testing Span(5) ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Success: Shortest Span is " << sp.shortestSpan() << " (Expected: 2)." << std::endl;
        std::cout << "Success: Longest Span is " << sp.longestSpan() << " (Expected: 14)." << std::endl;
    }
    catch (const SpanException& e) {
        std::cerr << "Failure (Unexpected): " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void rangeAndErrorTest()
{
    std::cout << "--------------------- (Test) Range and Error Handling ---------------------" << std::endl;
    std::cout << std::endl;

    Span sp_test1(10);
    
    std::cout << "--- Test 1: Not Enough Elements (1 element) ---" << std::endl;
    try {
        sp_test1.addNumber(42);
        sp_test1.shortestSpan();
        std::cout << "Failure: Exception was not thrown." << std::endl;
    }
    catch (const NotEnoughElementsException& e) {
        std::cerr << "Success (Expected): " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    Span sp(10);
    
    std::cout << "--- Test 2: addRange functionality ---" << std::endl;
    std::vector<int> data_to_add;
    for (int i = 0; i < 5; ++i) {
        data_to_add.push_back(i * 10 + 2);
    }
    
    try {
        sp.addRange(data_to_add.begin(), data_to_add.end());
        std::cout << "Success: Added 5 elements. Current Size: " << sp.getSize() << std::endl;
        std::cout << "Success: Shortest Span is " << sp.shortestSpan() << " (Expected: 10)." << std::endl;
    }
    catch (const SpanException& e) {
        std::cerr << "Failure (Unexpected): " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 3: SpanFullException with addRange ---" << std::endl;
    std::vector<int> overflow_data(5, 1);
    try {
        sp.addNumber(50);
        sp.addNumber(60);
        sp.addNumber(70);
        sp.addNumber(80);
        sp.addNumber(90);
        
        sp.addRange(overflow_data.begin(), overflow_data.end()); 
        std::cout << "Failure: Exception was not thrown." << std::endl;
    }
    catch (const SpanFullException& e) {
        std::cerr << "Success (Expected): " << e.what() << std::endl;
    }
    catch (const SpanException& e) {
        std::cerr << "Failure (Wrong Exception): " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void largeScaleTest()
{
    std::cout << "--------------------- (Test) Large Scale (12000) ---------------------" << std::endl;
    std::cout << std::endl;

    const unsigned int LARGE_SIZE = 12000;
    
    try {
        Span large_sp(LARGE_SIZE);
        std::srand(std::time(0)); 

        std::vector<int> random_numbers;
        for (unsigned int i = 0; i < LARGE_SIZE; ++i) {
            random_numbers.push_back(std::rand()); 
        }
        
        random_numbers[0] = 500000;
        random_numbers[1] = 500001;

        std::cout << "--- Adding " << LARGE_SIZE << " numbers using addRange ---" << std::endl;
        large_sp.addRange(random_numbers.begin(), random_numbers.end());
        
        std::cout << "Success: Number of elements: " << large_sp.getSize() << std::endl;

        long shortest = large_sp.shortestSpan();
        long longest = large_sp.longestSpan();

        if (shortest == 1) {
            std::cout << "Success: Shortest Span is " << shortest << "." << std::endl; 
        } else {
            std::cout << "Failure: Shortest Span is " << shortest << " (Expected 1)." << std::endl; 
        }
        
        std::cout << "Longest Span is " << longest << "." << std::endl; 
    }
    catch (const SpanException& e) {
        std::cerr << "Failure (Unexpected): " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    subjectTest();
    rangeAndErrorTest();
    largeScaleTest();
    
    std::cout << "--------------------- finish!!!!! ---------------------" << std::endl;
    return 0;
}
