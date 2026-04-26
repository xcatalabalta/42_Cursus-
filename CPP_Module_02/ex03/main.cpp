/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:13:43 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/02 07:50:47 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float ft_area(Point a, Point b, Point c);

bool bsp(Point const a, Point const b, Point const c, Point const point);

void checkTriangle(Point const p1, Point const p2, Point const p3, Point const p4)
{
	if (!ft_area(p1, p2, p3))
	{
		std::cout 	<< "\033[1;31mError: we cannot form a triangle with "
					<< p1 << p2 << p3 << "\n\033[0m",0;
	}
	else
	{
		std::cout << "Vertex are " << p1 << p2 << p3 << std::endl;
		std::cout << "Point to check: " << p4 << std::endl;
		
		if (bsp(p1, p2, p3, p4))
		{
			std::cout << p4 << " is inside.\n";
		}
		else
		{
			std::cout << p4 << " is outside.\n";	
		}
	}
}

int main( void )
{
	/*
	{	
		//Test of constructors and assignation
		Point	a(3, 4);
		Point	b(-8.06f, -192);
		Point	c;

		std::cout 	<< "\033[1;35m\n\nSOME TESTS\n\n\033[0m";
		std::cout 	<< "Before a = b\n";
		std::cout 	<< "a.x = " << a.getX() << std::endl;
		std::cout 	<< "a.y = " << a.getY() << std::endl;
		std::cout 	<< "b.x = " << b.getX() << std::endl;
		std::cout 	<< "b.y = " << b.getY() << std::endl;
		std::cout 	<< "c.x = " << c.getX() << std::endl;
		std::cout 	<< "c.y = " << c.getY() << std::endl;
		std::cout 	<< "With overload of stream: a:"
					<< a << std::endl;
		std::cout 	<< "b " << b << std::endl;
		c = a;
		a = b;
		std::cout 	<< "After c = a and a = b (using overload stream\n";
		std::cout 	<< "a :" << a << "\n"
					<< "b :" << b << "\n"
					<< "c :" << c << std::endl;
		c = a;
		std::cout 	<< "After c = a (with and without overload stream)\n";
		std::cout 	<< "a.x = " << a.getX() << std::endl;
		std::cout 	<< "a.y = " << a.getY() << std::endl;
		std::cout 	<< "b.x = " << b.getX() << std::endl;
		std::cout 	<< "b.y = " << b.getY() << std::endl;
		std::cout 	<< "(overload stream) c = " 
					<< c << std::endl;
		Point d (a);
		std::cout 	<< "Now Point d (a)\n";
		std::cout 	<< "d : " << d << std::endl;

		Point e (-325, -18.05f);
		std::cout	<< "new point e: " << e << "\n";
		if (a == e)
		{
			std::cout << " a & e are the same\n";
		}
		if (a != e)
		{
			std::cout << " a & e are different\n";
		}
		a = b = c = d = e;
		std::cout 	<< "After a = b = c = d = e \n";
		std::cout 	<< "a :" << a << "\n"
					<< "b :" << b << "\n"
					<< "c :" << c << "\n"
					<< "d :" << d << "\n"
					<< "e :" << e
					<< std::endl;
	}
	*/
	{
		//Operators work differently depending on the 
		//element at right hand or left hand: 
		//they need some conversions or friend operators
		Point p1(10,-30);
		Point p2(p1.getX(),p1.getY() + 12 - 24 / 2);
		Point p3(59.759f, -15 + p1.getY().toFloat());
		Fixed a = p1.getX() * 1;
		Fixed b = 2 * p1.getY().toFloat();
		Fixed c = -1.09f - a + b + 6;
		Fixed d = 39;
		Fixed e = -23.567f * p3.getY();
		Point p4(a, b * 2);
		Point p5;
		Point p6(a + 10 , c);
		Point p7(p6);
		Point p8(e, -c);
			
		checkTriangle(p1, p2, p3, p4);
		checkTriangle(p1, p3, p5, p4);
		checkTriangle(p1, p3, p4, p6);
		checkTriangle(p3, p4, p1, p7);
		p7 = p4;
		checkTriangle(p1, p3, p7, p2);
		checkTriangle(p5, p6, p7, p8);

	}
	return (std::cout << "\033[1;32m\nTHAT'S ALL FALKS\n\033[0m",0);
}
