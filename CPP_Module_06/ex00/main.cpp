/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:03:12 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/30 17:05:41 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ScalarConverter.class.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout 	<< "Invalid number of arguments"
					<< std::endl;
		return (0);
	}
	
	ScalarConverter::convert(argv[1]);
	

	/*
	// test of correct notations and values
	char ca = -128;
	double a = +32.;
	float b = +32.;
	std::cout 	<< a << "\t" << b << "\t" << ca
				<< std::endl;
	float af = +23.f;
	float afb = -.0f;
	std::cout << af << "\t" << afb << "\n";
	*/
	return (0);
}

//Test and others not included
/*
	//Getting the number of characters
	std::string 	input(argv[1]);
	std::cout 		<< input << " has " << input.size()
					<< " characters"
					<< std::endl;
*/
/*
	//Representation of -0 in double and float
	double aa = -0.0;
	float af = -.0f;
	std::cout.precision(12);
	std::cout << "this is " << static_cast<double>(aa) << std::endl;
	std::cout << "this is " << static_cast<double>(af) << std::endl;
	std::cout << "this is " << static_cast<float>(aa) << std::endl;
	std::cout << "this is " << static_cast<float>(af) << std::endl;
*/
/*	
	double c = -.00;
	float d = -.00f;
	std::cout	<< "Direct double c = -.00    \t" << c << "\n"
				<< "Direct float d = -.00f   \t" << d << "\n"
				<< "Casted to float: double c = -.00    \t" << static_cast<float>(c) << "\n"
				<< "Casted to double: float d = -.00f  \t" << static_cast<double>(d) << "\n";
*/
/*
	// Test of different numbers and precision
	float a = 999999900000.5153f;
	double b = 1023456789;

	std::cout.precision(input.size());
	std::ostringstream ossa;
	std::ostringstream ossb;
	ossa << a;
	ossb << b;
	std::string num_a = ossa.str();
	std::string num_b = ossb.str();;

	//std::cout.precision(input.size());
	std::cout 	<< "Direct float a = 999999900000.f =>\t=> " << a << "\t" << num_a << "\n"
				<< "Direct double b = 1023456789 =>\t=> " << b << "\t" << num_b << "\n"
				<< "Casted to double: float a = 999999900000.f =>\t=> " << static_cast<double>(a) << "\n"
				<< "Casted to float: double b = 1023456789 =>\t=> " << static_cast<float>(b) << "\n\n\n";
*/
/*
	#include <cstring>//for memcpy
	#include <stdint.h>// for uint64_t
	//double a = -0.0;
	char a = 'a';
    uint64_t bits;
    memcpy(&bits, &a, sizeof(char));
    
    std::cout << "Binary of -0.0 (double): 0x" << std::hex << bits << std::endl;
    // Expected output: 0x8000000000000000
    
    float b = static_cast<float>(a);
	b = 42.f;
    uint32_t float_bits;
    memcpy(&float_bits, &b, sizeof(float));
    
    std::cout << "Binary of -0.0f (float): 0x" << std::hex << float_bits << std::endl;
	
    // Expected output: 0x80000000
*/