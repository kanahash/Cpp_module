/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 22:03:01 by kanahash          #+#    #+#             */
/*   Updated: 2025/12/10 22:49:06 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


static bool isLeap(int year)
{
    return((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

void BitcoinExchange::loadDatabase(const std::string& dbFileName)
{
    std::ifstream file(dbFileName.c_str());

    if(!file.is_open())
    {
		throw std::runtime_error("could not open database file: " + dbFileName);
    }

    std::string line;
    std::getline(file,line);

    while(std::getline(file, line))
    {
        if(line.empty()) continue;

        size_t commaPos = line.find(',');
        if(commaPos == std::string::npos)
        {
            std::cerr << "Warning: skipping malformed DB line: " << line << std::endl;
            continue;
        }
        std::string dateStr = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1);

        try
        {
            float rate = std::atof(rateStr.c_str());
            if(rate < 0)
            {
                std::cerr << "Warning: skipping negative rate in DB line: " << line << std::endl;
                continue;
            }
            exchangeRates[dateStr] = rate;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Warning: skipping non-numeric rate in DB line: " << line << std::endl;
        }
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    int year, month, day;

    if(date.length() != DATE_LEN || date[4] != '-' || date[7] != '-')
	{
        return(false);
	}
	
	if(std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
	{
		return(false);
	}

    if(year < MIN_YEAR || year > 9999 || month > 12 || day < 1 || day > 31)
    {
		    return(false);
	}
	
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    if(month == 2)
    {
        if(isLeap(year))
        {
            if(day > 29)
                return(false);
        }
        else
        {
            if(day > 28)
                return(false);
        }
    }
    else if(day > daysInMonth[month])
    {
        return(false);
    }
    return(true);
}

float BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = exchangeRates.upper_bound(date);

    if(it == exchangeRates.begin())
        return(0.0f);
    
    it--;

    return(it->second);
}

void BitcoinExchange::processLine(const std::string& line) const
{
    float value;
    size_t commaPos = line.find(",");

    if(commaPos == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string dateStr = line.substr(0, commaPos);
    std::string valueStr = line.substr(commaPos + 1);
	std::stringstream ss(valueStr);

    if(!isValidDate(dateStr))
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

	if(!(ss >> value) || !(ss.eof()))
	{
		std::cerr << "Error: not a valid number." << std::endl;
		return;
	}
    
    if(value < 0.0f)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }

    if(value > 1000000.0f)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return;
    }

    float rate = getExchangeRate(dateStr);

    if(rate == 0.0f && !exchangeRates.empty())
    {
        if(dateStr < exchangeRates.begin()->first)
        {
            std::cerr << "Error: no exchange rate available for date or earlier: " << dateStr << std::endl;
            return;
        }
    }

    float result = value * rate;
    
    std::cout << dateStr << " => " <<value << " = " << result << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string& dbFileName)
{
    loadDatabase(dbFileName);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : exchangeRates(other.exchangeRates)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if(this != &other)
        this->exchangeRates = other.exchangeRates;
    return(*this);
}

void BitcoinExchange::execute(const std::string& inputFileName)
{
    std::string line;

    std::ifstream file(inputFileName.c_str());
    if(!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    if(!std::getline(file, line))
        return;

    while(std::getline(file, line))
    {
        processLine(line);
    }
}
