/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:13:43 by fcatala-          #+#    #+#             */
/*   Updated: 2024/12/18 13:00:42 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{

	{
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );
		
		a = Fixed( 1234.7321f );
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	{
		std::cout 	<< "\033[1;35m\n\nSOME EXTRAS\n\n\033[0m";
		std::cout 	<< "Two variables (a, h) built + 1 ref and 1 pointer to a "
					<< "(ref and pointer do not call any message):\n";
		Fixed a, h;
		Fixed& ref = a;
		Fixed *ptr = &a;

		double k = 2 * acos(0.0);
		std::cout << "\nk value (PI) = " << k << std::endl;		

		h.setRawBits(256);
		std::cout 	<< "Value of " << h.getRawBits() 
					<< " directly entered to h\n"
					<< "Due to bitwise, public value of h is " << h 
					<< " instead of "<< h.getRawBits()
					<< std::endl
					<< "\nPI value entered to h (updated)" << std::endl;
		h = Fixed (static_cast<float>(k));
		std::cout	<< "\nLet's assignate h to a (a = h): " << std::endl;
		a = h;
		std::cout	<<"\nNew variable (w) as a copy of a: \n";
		Fixed const w(a);
		std::cout 	<< "\nLet's check some results \n"
					<< "a is " << a.toFloat() << " as float" << std::endl
				 	<< "h is " << h.toInt() << " as integer" << std::endl
				 	<< "h value is " << h.getRawBits() << std::endl
					<< "h is " << h << std::endl
					<< "w is " << h << std::endl
					<< "ref is " << ref <<" and ptr is " << *ptr << std::endl
					<< "h updated with a negative float value (-96.1237)"
					<< std::endl;
		h = Fixed(-96.1237f);
		std::cout	<< "Let's update a with h (a = h): " << std::endl;
		a = h;
		std::cout 	<< "Let's check some results \n"
					<< "a is " << a.toFloat() << " as float" << std::endl
				 	<< "h is " << h.toInt() << " as integer" << std::endl
				 	<< "h is " << h << std::endl
				 	<< "ref is " << ref <<" and ptr is " << *ptr <<std::endl
					<< "Int ref is " << ref.toInt() << " int ptr is "<< ptr->toInt() 
					<< std::endl;
	}
	return (std::cout << "\033[1;31mTHAT'S ALL FALKS\n\033[0m",0);
}
