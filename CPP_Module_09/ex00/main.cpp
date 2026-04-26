/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:55:32 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/28 06:30:41 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/BitcoinExchange.class.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: no file or more than one file provided." << std::endl;
		return (1);
	}
	checkFile(argv[1], 2);
	BitcoinExchange  buid;
	buid.getValue(argv[1]);
	/*
	const char 	*path = "assets/w_values_data.csv";
	BitcoinExchange test(path);
	test.getValue(argv[1]);
	*/
	
	return (0);
}