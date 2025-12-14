/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:30:47 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/20 23:20:17 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int open_file(std::string& Receive_inputfile, std::string& Receive_outputfile, std::ifstream &inputfile, std::ofstream &outputfile)
{
	inputfile.open(Receive_inputfile.c_str(), std::fstream::in);

	if(!inputfile.is_open())
	{
		std::cerr << "Error: Could not open input file." << std::endl;
		return(1);
	}
	outputfile.open(Receive_outputfile.c_str(), std::fstream::out);
	if(!outputfile.is_open())
	{
		std::cerr << "Error: Could not create output file." << std::endl;
		inputfile.close();
		return(1);
	}
	return(0);
}

std::string replace(const std::string& line, const std::string& to_find, const std::string& to_replace)
{
	std::string replaced_line;
	std::string::size_type found;
	size_t end_last_found = 0;

	found = line.find(to_find);
	if(found == std::string::npos)
		return(line);
	while(found != std::string::npos)
	{
		replaced_line.append(line, end_last_found, found - end_last_found);
		replaced_line += to_replace;
		end_last_found = found + to_find.length();
		found = line.find(to_find, end_last_found);
	}
	replaced_line.append(line, end_last_found, line.length() - end_last_found);
	return(replaced_line);
}

void read_and_replace(char **av, std::ifstream &inputfile, std::ofstream &outputfile)
{
	std::string to_find;
	std::string to_replace;
	std::string line;
	std::string replaced_line;

	to_find = *(av + 2);
	to_replace = *(av + 3);

	while(std::getline(inputfile, line))
	{
		replaced_line = replace(line, to_find, to_replace);

		if(!inputfile.eof())
			outputfile << replaced_line << std::endl;
		else
			outputfile << replaced_line;
	}
}

int main(int ac, char **av)
{
	std::string Receive_inputfile;
	std::string Receive_outputfile;
	std::ifstream inputfile;
	std::ofstream outputfile;

	if(ac != 4)
	{
		std::cerr << "Usage: ./Sed_is_for_losers <filename> <s1> <s2>" << std::endl;
		return(1);
	}
	Receive_inputfile = av[1];
	Receive_outputfile = Receive_inputfile + ".replace";
	if(open_file(Receive_inputfile, Receive_outputfile, inputfile, outputfile))
		return(1);
	read_and_replace(av, inputfile, outputfile);
	inputfile.close();
	outputfile.close();
	return(0);
}
