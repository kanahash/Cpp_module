/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:08:16 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/24 01:35:30 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "--- Testing DEBUG level ---" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\n--- Testing INFO level ---" << std::endl;
    harl.complain("INFO");

    std::cout << "\n--- Testing WARNING level ---" << std::endl;
    harl.complain("WARNING");

    std::cout << "\n--- Testing ERROR level ---" << std::endl;
    harl.complain("ERROR");

    std::cout << "\n--- Testing an unknown level ---" << std::endl;
    harl.complain("UNKNOWN");

    return 0;
}
