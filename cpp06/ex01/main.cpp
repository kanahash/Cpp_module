/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 23:58:49 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/08 23:58:50 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

Data* test_create_data(int value, const std::string& name) {
    Data* data = new Data(value, name);
    std::cout << "  [Data Created] -> Address: " << data
              << ", Value: " << data->value
              << ", Name: " << data->name << std::endl;
    return data;
}

uintptr_t test_serialize(Data* ptr) {
    uintptr_t serialized = Serializer::serialize(ptr);
    std::cout << "  [Serialized]   -> uintptr_t: 0x"
              << std::hex << std::uppercase << serialized
              << std::dec << std::nouppercase << std::endl;
    return serialized;
}

Data* test_deserialize_and_print(uintptr_t serialized) {
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "  [Deserialized] -> Address: " << deserialized;

    if (deserialized != NULL) {
        std::cout << ", Value: " << deserialized->value
                  << ", Name: " << deserialized->name << std::endl;
    } else {
        std::cout << " (NULL)" << std::endl;
    }
    return deserialized;
}

void test_verification(Data* original, Data* deserialized) {
    std::cout << "  [Verification]" << std::endl;
    std::cout << "    Original Address == Deserialized Address: "
              << (original == deserialized ? "true" : "false") << std::endl;

    if (original != NULL && deserialized != NULL) {
        std::cout << "    Original Value == Deserialized Value: "
                  << (original->value == deserialized->value ? "true" : "false") << std::endl;
        std::cout << "    Original Name  == Deserialized Name: "
                  << (original->name == deserialized->name ? "true" : "false") << std::endl;
    } else if (original == NULL && deserialized == NULL) {
        std::cout << "    Both are NULL: true" << std::endl;
    }
}

void run_test_normal_object() {
    std::cout << "--------------------- Test 1: Normal Data Object ---------------------" << std::endl;

    Data* original = test_create_data(42, "test_data");
    uintptr_t serialized = test_serialize(original);

    Data* deserialized = test_deserialize_and_print(serialized);
    test_verification(original, deserialized);

    delete original;
    std::cout << std::endl;
}

void run_test_null_pointer() {
    std::cout << "--------------------- Test 2: NULL Pointer ---------------------" << std::endl;

    Data* nullPtr = NULL;
    std::cout << "  [Data Created] -> Address: " << nullPtr << " (NULL)" << std::endl;
    uintptr_t serializedNull = test_serialize(nullPtr);

    Data* deserializedNull = test_deserialize_and_print(serializedNull);
    test_verification(nullPtr, deserializedNull);

    std::cout << std::endl;
}

void run_test_multiple_objects() {
    std::cout << "--------------------- Test 3: Multiple Objects ---------------------" << std::endl;

    Data* obj1 = test_create_data(100, "first_object");
    Data* obj2 = test_create_data(200, "second_object");

    uintptr_t serialized1 = test_serialize(obj1);
    uintptr_t serialized2 = test_serialize(obj2);

    std::cout << "  [Intermediate Check] obj1 address != obj2 address: " << (obj1 != obj2 ? "true" : "false") << std::endl;

    Data* deserialized1 = Serializer::deserialize(serialized1);
    Data* deserialized2 = Serializer::deserialize(serialized2);

    std::cout << "  [Deserialized 1] -> Address: " << deserialized1 << std::endl;
    std::cout << "  [Deserialized 2] -> Address: " << deserialized2 << std::endl;

    std::cout << "  [Verification]" << std::endl;
    std::cout << "    obj1 == deserialized1: " << (obj1 == deserialized1 ? "true" : "false") << std::endl;
    std::cout << "    obj2 == deserialized2: " << (obj2 == deserialized2 ? "true" : "false") << std::endl;
    std::cout << "    deserialized1 != deserialized2: " << (deserialized1 != deserialized2 ? "true" : "false") << std::endl;

    delete obj1;
    delete obj2;

    std::cout << std::endl;
}


int main() {
    std::cout << "--------------------- EX01: Serializer Test ---------------------" << std::endl;
    std::cout << std::endl;

    run_test_normal_object();
    run_test_null_pointer();
    run_test_multiple_objects();

    std::cout << "--------------------- All tests completed! ---------------------" << std::endl;
    return 0;
}
