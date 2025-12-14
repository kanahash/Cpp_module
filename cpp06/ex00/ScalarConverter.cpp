/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 23:57:43 by kanahash          #+#    #+#             */
/*   Updated: 2025/10/08 23:57:44 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    if (isChar(literal)) {
        convertFromChar(literal[0]);
    } else if (isSpecialFloat(literal)) {
        convertFromFloat(static_cast<float>(std::strtod(literal.c_str(), NULL)));
    } else if (isSpecialDouble(literal)) {
        convertFromDouble(std::strtod(literal.c_str(), NULL));
    } else if (isFloat(literal)) {
        convertFromFloat(static_cast<float>(std::strtod(literal.c_str(), NULL)));
    } else if (isDouble(literal)) {
        convertFromDouble(std::strtod(literal.c_str(), NULL));
    } else if (isInt(literal)) {
        convertFromInt(static_cast<int>(std::strtol(literal.c_str(), NULL, 10)));
    } else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

bool ScalarConverter::isChar(const std::string& literal) {
    return literal.length() == 1 && !std::isdigit(literal[0]) && literal[0] != '.' && literal[0] != '-' && literal[0] != '+';
}

bool ScalarConverter::isInt(const std::string& literal) {
    if (literal.empty()) return false;
    
    // Check if it contains only digits and optional sign
    size_t start = 0;
    if (literal[0] == '-' || literal[0] == '+') {
        start = 1;
    }
    
    if (start >= literal.length()) return false;
    
    for (size_t i = start; i < literal.length(); i++) {
        if (!std::isdigit(literal[i])) {
            return false;
        }
    }
    
    // Check for overflow
    long val = std::strtol(literal.c_str(), NULL, 10);
    return val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max();
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal.empty()) return false;
    
    if (isSpecialFloat(literal)) return true;
    
    if (literal[literal.length() - 1] != 'f') return false;
    
    std::string withoutF = literal.substr(0, literal.length() - 1);
    if (withoutF.empty()) return false;
    
    // Check if it's a valid floating point number (including scientific notation)
    char* endPtr;
    std::strtod(withoutF.c_str(), &endPtr);
    return *endPtr == '\0';
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal.empty()) return false;
    
    if (isSpecialDouble(literal)) return true;
    
    // Check if it's a valid floating point number (including scientific notation)
    char* endPtr;
    std::strtod(literal.c_str(), &endPtr);
    if (*endPtr != '\0') return false;
    
    // If it's a pure integer, check if it's within int range
    if (literal.find('.') == std::string::npos && literal.find('e') == std::string::npos && literal.find('E') == std::string::npos) {
        long val = std::strtol(literal.c_str(), NULL, 10);
        return val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max();
    }
    
    return true;
}

bool ScalarConverter::isSpecialFloat(const std::string& literal) {
    return literal == "-inff" || literal == "+inff" || literal == "nanf";
}

bool ScalarConverter::isSpecialDouble(const std::string& literal) {
    return literal == "-inf" || literal == "+inf" || literal == "inf" || literal == "nan";
}

void ScalarConverter::convertFromChar(char c) {
    printChar(c);
    printInt(static_cast<int>(c));
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void ScalarConverter::convertFromInt(int i) {
    // Check if the value is within char range
    if (i < 0 || i > 127) {
        std::cout << "char: impossible" << std::endl;
    } else {
        printChar(static_cast<char>(i));
    }
    printInt(i);
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}

void ScalarConverter::convertFromFloat(float f) {
    // Check if the value is within char range
    if (f < 0 || f > 127) {
        std::cout << "char: impossible" << std::endl;
    } else {
        printChar(static_cast<char>(f));
    }
    // Check if the value is within int range
    if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        printInt(static_cast<int>(f));
    }
    printFloat(f);
    printDouble(static_cast<double>(f));
}

void ScalarConverter::convertFromDouble(double d) {
    // Check if the value is within char range
    if (d < 0 || d > 127) {
        std::cout << "char: impossible" << std::endl;
    } else {
        printChar(static_cast<char>(d));
    }
    // Check if the value is within int range
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        printInt(static_cast<int>(d));
    }
    printFloat(static_cast<float>(d));
    printDouble(d);
}

void ScalarConverter::printChar(char c) {
    if (std::isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}

void ScalarConverter::printInt(int i) {
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
    std::cout << "float: " << f;
    if (f == static_cast<int>(f)) {
        std::cout << ".0f" << std::endl;
    } else {
        std::cout << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double d) {
    std::cout << "double: " << d;
    if (d == static_cast<int>(d)) {
        std::cout << ".0" << std::endl;
    } else {
        std::cout << std::endl;
    }
}
