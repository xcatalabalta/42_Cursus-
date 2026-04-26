/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:54:18 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/01 12:19:39 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/RPN.class.hpp"

int main (int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr 	<< "\033[41mError: Invalid number of arguments.\033[0m"
					<< std::endl;
		return (1);
	}
	RPN  	result;
	double 	output;
	try
	{
		output = result.calculatorRPN(argv[1]);
		std::cout << output << std::endl;
	}
	catch(const char *msg)
	{
		std::cerr << "\033[0m" << msg << std::endl;
		return (1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[0m" << e.what() << std::endl;
		return (1);
	}
	catch(...)
	{
		std::cerr << "\033[0m" << "\nWild thing happened" << std::endl;
		return (1);
	}
	
	return (0);
}