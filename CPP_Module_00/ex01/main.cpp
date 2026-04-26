/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:20:25 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/14 16:34:13 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
// #include <cstddef>
// Non included code
/*
// Not necessary
void ft_handleEmpty(std::string input)
{
	if (input.empty())
	{
        std::cout << "\033[A\033[2K";
	}
}
*/
// Approach changed

static void ft_strtoupper(std::string *str)
{
	for (size_t i = 0; i < str->size(); i++)
	{
		(*str)[i] = static_cast<char>(std::toupper((*str)[i]));
	}
	return ;
}

/*
//Doesn't belong to c++98
		for (char &c : input)
		{
			c = std::toupper(c);
		}
*/
/*
static std::string ft_strcpytoupper(std::string str)
{
	std::string output;

	for (int i = 0; str[i]; i++)
	{
		output[i] = std::toupper(str[i]);
	}
	return (output);
}
*/
int	main(void)
{
	std::string	input;
	std::string	aux;
	PhoneBook	book;

	while (1)
	{
		input.clear();
		while (input.empty())
		{
			std::cout <<"Enter a command (ADD/SEARCH/EXIT or ctrl+d to exit): ";
			std::getline(std::cin, input);
			if (!std::cin || !input.compare("EXIT"))
				return (std::cout << std::endl << L_BLANK 
							<< "Good bye. See you soon!!!!" << std::endl, 0);
			if (input.empty())
				std::cout << "\033[A\033[2K";
		}
		if (!input.compare("ADD"))
			book.ft_add();
		else if (!input.compare("SEARCH"))
			book.ft_search();
		else
		{
			aux = input;
			ft_strtoupper(&aux);
			if (!aux.compare("ADD") || !aux.compare("SEARCH") || !aux.compare("EXIT"))
			{
				std::cout << L_BLANK <<"\033[1;31m" << input 
						<< ": must be in capital letters\033[0m\r\033[A\033[2K";
			}
			else
			{
				if (input.length() > 10)
				{
					std::cout << L_BLANK <<"\033[1;31m" << input.substr(0, 9) << "..."
						<< ": Command not valid\033[0m\r\033[A\033[2K";
				}
				else
				{
				std::cout << L_BLANK <<"\033[1;31m" << input 
						<< ": Command not valid\033[0m\r\033[A\033[2K";
				}
			}
		}
	}
	return (0);
}
