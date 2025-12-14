/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:56:32 by kanahash          #+#    #+#             */
/*   Updated: 2025/12/14 21:56:45 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<string>

int main(int ac, char **av)
{
	if(ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		int i = 1;
		int j;
		while(i < ac)
		{
			j = 0;
			while(av[i][j])
			{
				av[i][j] = std::toupper(av[i][j]);
				j++;
			}
			std::cout <<av[i];
			i++;
		}
		std::cout<<std::endl;
	}
	return(0);
}
