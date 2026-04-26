/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:52:21 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/09 10:26:40 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/whatever.class.hpp"
#include <stdint.h>
#include <sstream> 
#include <string>

//use of an unnamed namespace instead of static functions
//Unclear if possible according to rules 
//namespace
//{
	typedef struct s_Data 
	{
		std::string name;
		char 		grade;
		double 		mark;
		int 		age;

	}	Data;

	// Example of conditional display. 
	void compare(Data &pers, Data &other, bool showMax)
	{
		std::cout 	<< "\nOrigin:\t\tOriginal\tRetrieved\n"
					<< "Name:\t\t" << pers.name << "\t\t" << other.name <<"\n"
					<< "Grade:\t\t" << pers.grade << "\t\t" << other.grade << "\n"
					<< "Mark:\t\t" << pers.mark << "\t\t" << other.mark << "\n"
					<< "Age:\t\t" << pers.age << "\t\t" << other.age << "\n"
					<< "Address:\t" << &pers << "\t" << &other << "\n";
		if (showMax)
		{
			std::cout 	<< "Max addr:\t\033[1;32m" << max(&pers, &other) << "\033[0m"
						<< std::endl;
		}
	}

	void display(Data &pers)
	{
		std::cout 	<< "\nName:\t\t" << pers.name << "\n"
					<< "Grade:\t\t" << pers.grade << "\n"
					<< "Mark:\t\t" << pers.mark << "\n"
					<< "Age:\t\t" << pers.age << "\n"
					<< "Address:\t" << &pers << "\n"
					<< std::endl;
	}

	// Same as above, but displaying address of each field. Mind when variables are char
	void displayFull(Data &pers)
	{
		std::cout 	<< "\nName:\t\t" << pers.name << "\t" << &pers.name << "\n"
					<< "Grade:\t\t" << pers.grade << "\t"<< static_cast<const void*>(&pers.grade)<< "\n"
					<< "Mark:\t\t" << pers.mark << "\t" << &pers.mark << "\n"
					<< "Age:\t\t" << pers.age << "\t" << &pers.age << "\n"
					<< "Address:\t" << &pers << "\n"
					<< std::endl;
	}

	//std::getline(std::cin, line);//#include <sstream> #include <string>
	//std::getchar();//#include <cstdio>
	void 	goNext(std::string msg)
	{
		std::string line;
		std::cout   << "\033[32m\nTake your time to revise the accuracy "
					<< "of the above implementation.\n"
					<< "Enter any key to continue with the next section:"
					<< "\033[1;4m" << msg << "\033[0m"
					<< std::endl;
		std::getline(std::cin, line);
		line.clear();	
	}
//}

int main (void)
{
	{
		int a = 2;
		int b = 3;
		std::cout << "Before swap" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "After swap:" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "Before swap:" << std::endl;
		std::cout << "c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "After swap" << std::endl;
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		goNext("\nSwapping structures and recylcing some concepts about reinterpret_cast<uintptr_t>");
	}
	{
		Data kako = {"Manel", 'C', 9.9, 62};
		Data kuko = {"Xavier", 'A', 99.9, 26};
		uintptr_t address = reinterpret_cast<uintptr_t>(::max(&kuko, &kako));
		Data* dataFromMin = static_cast<Data*>(::min(&kuko, &kako));
		Data* dataFromMax = reinterpret_cast<Data*>(address);
		std::cout << "\nBefore swap:" << std::endl;
		for (int i = 0; i < 2; i++)
		{
			compare(kuko, kako, true);
			std::cout << "\nDisplaying highest address (Yes, it is a silly criteria, but ...)" << std::endl;
			display(*dataFromMax);
			if (i == 1)
				break;
			std::cout << "After swap:" << std::endl;
			::swap (kuko, kako);
		}
		std::cout << "\nDisplaying lowest address" << std::endl;
		display(*dataFromMin);
		goNext("\nSwapping values inside structures and recylcing some concepts about reinterpret_cast<uintptr_t>");
	}
	{
		std::cout << "\nLet's swap members of a struct array" << std::endl;
		Data team[5] = {
			{"Manel", 'B', 60, 26},
			{"Joan", 'A', 89.9, 32},
			{"Thief", 'C', 9.9, 72},
			{"Xavier", 'A', 99.9, 35},
			{"Marta", 'D', 6.9, 18}
		};
		uintptr_t secret[5];
		std::cout 	<< "Here is our original team: " << std::endl;
		for (int i = 0; i < 5; ++i)
		{
			secret[i] = reinterpret_cast<uintptr_t>(&team[i]);
			compare(team[i], *reinterpret_cast<Data*>(secret[i]), false);
		}
		std::cout 	<< "\nThe thief is going to swap (steal) the best characteristics to him (yes, is a he): " << std::endl;
		for (int i = 0; i < 5; ++i)
		{
			if (team[i].name == team[2].name)
			{
				continue;
			}
			if (team[2].grade != ::max(team[2].grade, team[i].grade))
			{
				::swap(team[2].grade, team[i].grade);
			}
			if (team[2].mark != ::max(team[2].mark, team[i].mark))
			{
				::swap(team[2].mark, team[i].mark);
			}
			if (team[2].age != ::min(team[2].age, team[i].age))
			{
				::swap(team[2].age, team[i].age);
			}
		}
		std::cout 	<< "Here is our team after the theft: " << std::endl;
		for (int i = 0; i < 5; ++i)
		{
			displayFull(team[i]);
		}
		std::cout 	<< "Later, the thief promoted himself at the top of the struct." 
					<< std::endl;
		::swap(team[0], team[2]);
		for (int i = 0; i < 5; ++i)
		{
			display(*reinterpret_cast<Data*>(secret[i]));
		}
	}
	return (0);
}
/*
	{
		std::cout << "Different implementation, it requires to specify the types\n";
		int a = 2;
		int b = 3;
		std::cout << "Before swap" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		Functions<int>::swap( a, b );
		std::cout << "After swap" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << Functions<int>::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << Functions<int>::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "Before swap" << std::endl;
		std::cout << "c = " << c << ", d = " << d << std::endl;
		Functions<std::string>::swap(c, d);
		std::cout << "After swap" << std::endl;
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << Functions<std::string>::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << Functions<std::string>::max( c, d ) << std::endl;
	}
*/