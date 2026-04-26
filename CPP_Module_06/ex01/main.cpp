/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 09:43:16 by fcatala-          #+#    #+#             */
/*   Updated: 2025/05/02 08:51:21 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/Serializer.class.hpp"
#include <cstdio>
#include <sstream>
#include <iomanip>

static void display(Data &pers)
{
	std::cout 	<< "Name:\t" << pers.name << "\n"
				<< "Grade:\t" << pers.grade << "\n"
				<< "Mark:\t" << pers.mark << "\n"
				<< "Age:\t" << pers.age
				<< std::endl;
}

static void compare(Data &pers, Data &other)
{
	std::cout 	<< "\nOrigin:\t\tOriginal\tRetrieved\n"
				<< "Name:\t\t" << pers.name << "\t\t" << other.name <<"\n"
				<< "Grade:\t\t" << pers.grade << "\t\t" << other.grade << "\n"
				<< "Mark:\t\t" << pers.mark << "\t\t" << other.mark << "\n"
				<< "Age:\t\t" << pers.age << "\t\t" << other.age << "\n"
				<< "Address:\t" << &pers << "\t" << &other << "\n"
				<< std::endl;
}

void 	ft_next(std::string msg)
{
	std::cout   << "\033[32m\nTake your time to revise the accuracy "
                << "of the above implementation.\n"
                << "Enter any key to continue with the next section: "
				<< "\033[1;4m" << msg << "\033[0m"
                << std::endl;
	getchar();
}

int main (void)
{
	{
		Data 	student;
		Data 	*ptr;
		uintptr_t 	serial;

		student.name = "Manel";
		student.grade = 'D';
		student.mark = 3.85;
		student.age = 32;
		serial = Serializer::serialize(&student);
		std::cout 	<< "Let's check:\n";
		display(student);
		std::cout 	<< "Code:\t" << serial
					<< std::endl;
		std::cout 	<< "Let's decode" << std::endl;
		ptr = Serializer::deserialize(serial);
		display(*ptr);
		ft_next("\nUse of new pointer which requires delete.");
	}
	{
		Data 	*crack = new Data;
		Data 	*decode;
		uintptr_t 	raw;

		crack->name = "Xavier";
		crack->grade = 'A';
		crack->mark = 100;
		crack->age = 25;
		raw = Serializer::serialize(crack);
		decode = Serializer::deserialize(raw);

		std::cout 	<< "Pointer time!:\n";
		display(*crack);
		std::cout 	<< "Code:\t" << raw
					<< std::endl;

		std::cout 	<< "Let's decode" << std::endl;
		display(*decode);
		delete crack;
		ft_next("\nDe-serialize the pointer directly from the value of its memory address \033[31m(without uintptr_t)");
	}
	{
		Data 	student;
		Data 	*ptr;

		student.name = "Manel";
		student.grade = 'D';
		student.mark = 3.85;
		student.age = 32;
		std::cout 	<< "Let's check:\n";
		display(student);
		//here is where the conversion from address (hexa) to long integer is performed
		void *address = &student;
		std::stringstream ss;
		ss << address;
    	long addressAsLong;
    	ss >> std::hex >> addressAsLong;
		//end of the trick
		std::cout 	<< "Code:\t" << addressAsLong << "\n";
		std::cout 	<< "Let's decode" << std::endl;
		ptr = Serializer::deserialize(addressAsLong);
		display(*ptr);
		ft_next("\nDe-serialize a pointer and display its content \033[31mfrom another one, previously defined as void*");
	}
	{
		Data 		super = {"Xavier", 'A', 99.9, 26};
		uintptr_t 	raw = Serializer::serialize(&super);
		void 		*tryptr = Serializer::deserialize(raw);
		compare(super, *static_cast<Data*>(tryptr));
	}
	return (0);
}

