/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 00:02:32 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/09 00:02:32 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

std::string intToString(int n) {
    std::stringstream ss;
    ss << n;
    return ss.str();
}

void test_identify_pointer(Base* obj, const std::string& test_name) {
    std::cout << "  " << test_name << ": ";
    identify(obj);
}

void test_identify_reference(Base& obj, const std::string& test_name) {
    std::cout << "  " << test_name << ": ";
    identify(obj);
}

void run_test_random_pointer() {
    std::cout << "--------------------- Test 1: Random Generation (Pointer) ---------------------" << std::endl;

    for (int i = 0; i < 10; i++) {
        Base* obj = generate();
        std::string test_name = "Generated object " + intToString(i + 1);
        test_identify_pointer(obj, test_name);
        delete obj;
    }
    std::cout << std::endl;
}

void run_test_random_reference() {
    std::cout << "--------------------- Test 2: Random Generation (Reference) -------------------" << std::endl;

    for (int i = 0; i < 10; i++) {
        Base* obj = generate();
        std::string test_name = "Generated object " + intToString(i + 1);
        
        std::cout << "  " << test_name << ": ";
        identify(*obj);
        
        delete obj;
    }
    std::cout << std::endl;
}

void run_test_specific_pointer() {
    std::cout << "--------------------- Test 3: Specific Type (Pointer) ---------------------" << std::endl;
    Base* objA = new A();
    Base* objB = new B();
    Base* objC = new C();

    test_identify_pointer(objA, "Testing A object");
    test_identify_pointer(objB, "Testing B object");
    test_identify_pointer(objC, "Testing C object");

    delete objA;
    delete objB;
    delete objC;
    std::cout << std::endl;
}

void run_test_specific_reference() {
    std::cout << "--------------------- Test 4: Specific Type (Reference) ---------------------" << std::endl;
    A objA_ref;
    B objB_ref;
    C objC_ref;

    test_identify_reference(objA_ref, "Testing A reference");
    test_identify_reference(objB_ref, "Testing B reference");
    test_identify_reference(objC_ref, "Testing C reference");
    
    std::cout << std::endl;
}

void run_test_null_pointer() {
    std::cout << "--------------------- Test 5: NULL Pointer Testing ---------------------" << std::endl;
    Base* nullPtr = NULL;
    test_identify_pointer(nullPtr, "Testing NULL pointer");
    std::cout << std::endl;
}

int main() {
    std::srand(std::time(0)); 
    
    std::cout << "--------------------- EX02: Type Identification Test ---------------------" << std::endl;
    std::cout << std::endl;

    run_test_random_pointer();
    run_test_random_reference();
    run_test_specific_pointer();
    run_test_specific_reference();
    run_test_null_pointer();

    std::cout << "--------------------- All tests completed! ---------------------" << std::endl;
    return 0;
}
