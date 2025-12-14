#include "iter.hpp"
#include <iostream>
#include <string>
#include <cstddef>

template <typename T>
void printElement(const T& val)
{
    std::cout << "[" << val << "] ";
}

void increment_int(int& val)
{
    std::cout << val << " -> ";
    val++;
    std::cout << val << " | ";
}

void append_exclamation_string(std::string& s)
{
    std::cout << s << " -> ";
    s += "!";
    std::cout << s << " | ";
}

void printInt(const int& n)
{
    std::cout << n << n << " (int) ";
}

int main(void)
{
    std::cout << "--------------------- EX01: Iter Test ---------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "--------------------- Test1. int (Non-const) Test ---------------------" << std::endl;
    std::cout << std::endl;

    int int_array[] = {1, 2, 3, 4, 5};
    size_t int_len = sizeof(int_array) / sizeof(int_array[0]);
    
    std::cout << "1-1. Before: ";
    iter(int_array, int_len, printElement<int>);
    std::cout << std::endl;

    std::cout << "1-2. Applying increment_int (Modifying): " << std::endl;
    iter(int_array, int_len, increment_int);
    std::cout << std::endl;

    std::cout << "1-3. After: ";
    iter(int_array, int_len, printElement<int>);
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "--------------------- Test2. string (Non-const + Function) Test ---------------------" << std::endl;
    std::cout << std::endl;

    std::string str_array[] = {"Hello", "World", "42"};
    size_t str_len = sizeof(str_array) / sizeof(str_array[0]);

    std::cout << "2-1. Before: ";
    iter(str_array, str_len, printElement<std::string>);
    std::cout << std::endl;

    std::cout << "2-2. Applying modifying function: " << std::endl;
    iter(str_array, str_len, append_exclamation_string);
    std::cout << std::endl;

    std::cout << "2-3. After: ";
    iter(str_array, str_len, printElement<std::string>);
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "--------------------- Test3. char (Const) Test ---------------------" << std::endl;
    std::cout << std::endl;

    const char char_array[] = {'a', 'b', 'c', 'd'};
    size_t char_len = sizeof(char_array) / sizeof(char_array[0]);

    std::cout << "3-1. Applying printElement<char> (non-modifying): " << std::endl;
    iter(char_array, char_len, printElement<char>);
    std::cout << std::endl;

    std::cout << "3-2. Applying const char print (using function template): " << std::endl;
    iter(char_array, char_len, printElement<char>); 
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "--------------------- Test4. Function Pointer Test (using printInt) ---------------------" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Applying function pointer to modified int_array: " << std::endl;
    iter(int_array, int_len, &printInt);
    std::cout << std::endl;

    std::cout << "--------------------- finish!!!!! ---------------------" << std::endl;

    return 0;
}
