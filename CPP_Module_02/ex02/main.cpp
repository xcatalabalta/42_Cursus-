/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:13:43 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/13 15:45:55 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{

	{
		//Original program given by the subject
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		std::cout 	<< "\033[1;35m\n\nSOME EXTRA TESTS\n\n\033[0m";
		Fixed a(859);
		Fixed b(10);
		Fixed c;
		int	iter = 0;

		std::cout 	<< "Between " << a << " and " << b 
					<< " The max is " << c.max(a, b)
					<< "\nThe min is " << c.min(a, b)
					<< std::endl;
		std::cout	<< "Let's use a c-- loop (end before target value)\n";
		c = a * b / 15;
		std::cout << "Pre loop: c is " << c << " and b is " << b <<std::endl;
		for (int i = 0; i < 10000000000; i++)
		{
			if ((c--).toInt() <= b.toInt())
			{
				std::cout << "c is = " << c << "\nb is = " << b <<std::endl;
				std::cout << "i is " << i << std::endl;
				break ;
			}

		}
		c = b * a;
		std::cout	<< "Let's use a --c loop (end at target value)\n";
		std::cout << "Pre loop: c is " << c << " and b is " << b <<std::endl;
		while(1)
		{
			++iter;
			if (--c <= b)
			{
				std::cout << "c is = " << c << "\nb is = " << b <<std::endl;
				std::cout << "After " << iter << " iterations\n";
				break ;
			}
		}
		c = b * a * (-1.35f);
		std::cout	<< "Let's use a ++c loop (end at target value)\n";
		std::cout << "Pre loop: c is " << c << " and b is " << b <<std::endl;
		iter = 0;
		while (1)
		{
			++iter;
			if (++c >= b)
			{
				std::cout << "c is = " << c << "\nb is = " << b <<std::endl;
				std::cout << "After " << iter << " iterations\n";
				break ;
			}
		}
		a = 347.63f;
		std::cout << "Now a is = " << a << " as int is = " << a.toInt() <<std::endl;
		a = a * (-1);
		std::cout << "a * -1 is = " << a << " as int is = " << a.toInt() <<std::endl;
		std::cout << c << " divided by " << a << " is " << c / a <<std::endl;
		std::cout << c/a << " multiplied by " << a << " is " << a * c / a << std::endl;
	}
	return (std::cout << "\033[1;31mTHAT'S ALL FALKS\n\033[0m",0);
}
