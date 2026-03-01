/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 22:08:49 by kanahash          #+#    #+#             */
/*   Updated: 2025/12/10 22:15:23 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define DB_FILE_NAME "data.csv"

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
    private:
		static const int MIN_YEAR = 2009;
		static const int MAX_VALUE = 1000;
		static const size_t DATE_LEN = 10;
        std::map<std::string, float> exchangeRates;
        void loadDatabase(const std::string& dbFileName);
        bool isValidDate(const std::string& date) const;
        float getExchangeRate(const std::string& date) const;
        void processLine(const std::string& line) const;

    public:
        BitcoinExchange(const std::string& dbFileName);
        BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange &other);
    
        void execute(const std::string& inputFileName);
};

#endif
