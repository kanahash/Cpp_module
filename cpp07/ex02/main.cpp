/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 23:10:30 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/12 23:17:49 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
void printArray(const Array<T> &arr, const std::string &name)
{
	std::cout << std::endl;
    std::cout << "--- " << name << " (Size: " << arr.size() << ") ---" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++) {
        try {
            std::cout << name << "[" << i << "] = " << arr[i] << std::endl;
        } catch (const std::exception &e) {
        }
    }
}

void test_array_functionality() {
    std::cout << "========================================" << std::endl;
    std::cout << "         Array Functionality Test       " << std::endl;
    std::cout << "========================================" << std::endl;
	std::cout << std::endl;

    std::cout << "--------------------- Test 1: Default Constructor (size 0) ---------------------" << std::endl;
    Array<int> empty_arr;
    printArray(empty_arr, "empty_arr");

	std::cout << std::endl;

    std::cout << "--------------------- Test 2: Size Constructor & Default Init ---------------------" << std::endl;
    Array<int> arr1(5);
    for (unsigned int i = 0; i < arr1.size(); i++) {
        arr1[i] = i * 10;
    }
    printArray(arr1, "arr1");

	std::cout << std::endl;

    std::cout << "--------------------- Test 3: Copy Constructor (Deep Copy) ---------------------" << std::endl;
    Array<int> arr2 = arr1;
    arr2[0] = 999;
    
    printArray(arr2, "arr2 (Modified)");
    printArray(arr1, "arr1 (Original)");

	std::cout << std::endl;

    std::cout << "--------------------- Test 4: Assignment Operator (Deep Copy) ---------------------" << std::endl;
    Array<int> arr3(2);
    arr3 = arr1;
    arr3[4] = 777;

    printArray(arr3, "arr3 (Modified)");
    printArray(arr1, "arr1 (Original)");
	
	std::cout << std::endl;

    std::cout << "--------------------- Test 5: Different Type (std::string) ---------------------" << std::endl;
    Array<std::string> str_arr(2);
    str_arr[0] = "Hello";
    str_arr[1] = "World";
    printArray(str_arr, "str_arr");

	std::cout << std::endl;
}

void test_exceptions() {
    std::cout << "========================================" << std::endl;
    std::cout << "           Exception Handling Test      " << std::endl;
    std::cout << "========================================" << std::endl;
	std::cout << std::endl;

    Array<char> small_arr(3);
    small_arr[0] = 'a';
    small_arr[1] = 'b';
    small_arr[2] = 'c';
    
    std::cout << "--------------------- Test 6: Out of Bounds Access ---------------------" << std::endl;
    
    try {
        std::cout << "Attempting to write to small_arr[3] (index out of bounds)..." << std::endl;
        small_arr[3] = 'x';
    } catch (const Array<char>::OutofBoundsException &e) {
        std::cerr << "CAUGHT EXCEPTION: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "CAUGHT OTHER EXCEPTION: " << e.what() << std::endl;
    }

    try {
        std::cout << "Attempting to read from small_arr[3] (index out of bounds)..." << std::endl;
        std::cout << "Value: " << small_arr[3] << std::endl;
    } catch (const Array<char>::OutofBoundsException &e) {
        std::cerr << "CAUGHT EXCEPTION: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "CAUGHT OTHER EXCEPTION: " << e.what() << std::endl;
    }
}

int main() {
    int *default_int = new int();
    std::cout << "Hint Check: new int() default value is " << *default_int << std::endl;
    delete default_int;

    test_array_functionality();
    test_exceptions();

	std::cout << std::endl;

    std::cout << "--------------------- finish!!!!! ---------------------" << std::endl;
    return 0;
}
