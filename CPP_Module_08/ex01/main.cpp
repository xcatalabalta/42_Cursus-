/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:14:18 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/21 11:20:56 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/Span.class.hpp"

#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdio>

template< typename T >
std::string display(T &it, const T& end)
{
	std::ostringstream oss;
	oss << std::right << std::setw(6);
	if (it != end)
	{		
		oss << *it;
		++it;
	}
	else
	{
		oss << " ";
	}
		oss << " ";
	return (oss.str());
}

void 	ft_goNext(std::string msg)
{
    std::string line;
	std::cout   << "\033[32m\nTake your time to check the accuracy "
                << "of the above implementation.\n"
                << "Enter any key to continue with the next section: "
				<< "\033[1;4m" << msg << "\033[0m"
                << std::endl;
	std::getline(std::cin, line);//#include <sstream> #include <string>
	line.clear();
	//std::getchar();//#include <cstdio>
}

int main (void)
{
	{
		std::cout << "\nGiven main\n" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		ft_goNext("\nMy main");
	}	
	{
		Span vec(10);
		Span copy;
		std::srand(time(0));
		int rand = 0;
		std::cout 	<< "Trying to put " << vec.capacity() + 3 
					<< " numbers into an object whose capacity is "<< vec.capacity()
					<< std::endl;
		for (unsigned int i = 0; i < vec.capacity() + 3; i++)
		{
			rand = std::rand() % 201 - 100;///random between +100 and 100
			try
			{
				vec.addNumber(rand);
			}
			catch (const std::bad_alloc& e)
			{
				std::cout << "Memory allocation error: "<< e.what() << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
			catch (...)
			{
				std::cout << "\033[31mNew problem found\033[0m" << std::endl;
			}
		}
		ft_goNext("\nDisplay of the present vector");
		vec.displayValues();
		ft_goNext("\nAddition of one element into a freshly constructed vector (capacity 0)");
		try
		{
			copy.addNumber(42);
		}
		catch (const std::bad_alloc& e)
		{
				std::cout << "Memory allocation error: "<< e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;;
		}
		catch (...)
		{
				std::cout << "\033[31mNew problem found\033[0m" << std::endl;
		}
		ft_goNext("\nShortest span and longest span of an empty object");
		try
		{
			copy.displayValues();
			copy.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		ft_goNext("\nShortest span and longest span of the previously created object");
		try
		{
			std::cout << "Shortest span = " << vec.shortestSpan() << std::endl;
			std::cout << "Longest span = " << vec.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << "\nDisplay of the sorted values, the repetead ones are highlighted in green color\n";
		vec.displaySorted();
		copy = vec;
		ft_goNext("\nDisplay a copied vector on a previously empty one.(unsorted)");
		copy.displayValues();
		Span recopy(25);
		for (unsigned int i = 0; i < recopy.capacity(); i++)
		{
			try
			{
				recopy.addNumber(-69);
			}
			catch (const std::bad_alloc& e)
			{
				std::cout << "Memory allocation error: "<< e.what() << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
			catch (...)
			{
				std::cout << "\033[31mNew problem found\033[0m" << std::endl;
			}
		}
		ft_goNext("\nDisplay a copied vector from a larger one.");
		copy = recopy;
		copy.displayValues();
		ft_goNext("\nDisplay a copied vector from a shorter one.");
		Span  shorty(4, 1968);
		std::cout 	<< "\nHere is a short vector located at " 
					<< &shorty << std::endl;	
		shorty.displayValues();
		std::cout	<< "\nWhile the destiny is located at " 
					<< &recopy << std::endl;
		recopy.displayValues();
		recopy = shorty;
		std::cout 	<< "\nAfter the copy, the destiny is located at " 
					<< &recopy
					<< "\nand its values are"
					<< std::endl;
		recopy.displayValues();
		ft_goNext("Customized constructor and filling with multiple values");
	}
	{
		std::cout 	<< "\nThe intended construction is larger than the allowed limits\n"
					<< std::endl;
		try
		{
			Span prova(MAX_VEC + 1, 22);
			prova.displayValues();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		catch (...)
		{
			std::cout << "\033[31mNew problem found\033[0m" << std::endl;
		}
		ft_goNext("The intended construction is within the allowed limits (same number few times)");
		Span prova(5, 42);
		prova.displayValues();
		ft_goNext("\nSuccessfully construction and fill from int vectors\n");
	}
	{
		std::vector<int> data;
		std::vector<int> dataBis;
		std::srand(time(0));
		int   	rand = 0;
		int		randBis = 0;
		int 	len = 20;
		int 	minValue = -404;
		int 	maxValue = 8350;
		int 	i = 0;
		Span test(len * 8);
		std::cout 	<< "Creation of two vectors of " << len << " random numbers each. "
					<< std::endl;
		for (; i < len; ++i)
		{
			rand = std::rand() % (maxValue - minValue + 1) + minValue;///random between minValue and maxValue
			randBis = std::rand() % (maxValue / 3 - minValue / 3 + 1) + minValue / 3;
			data.push_back(rand);
			dataBis.push_back(randBis);
			std::cout 	<< "Vector 1 pos " << std::right << std::setw(3) << i << " = " 
						<< std::right << std::setw(5) << rand 
						<< "\tVector 2 pos " << std::right << std::setw(3) << i << " = " 
						<< std::right << std::setw(5) << randBis
						<< std::endl;
		}
		ft_goNext("");
		try 
		{
			Span  vecA(data);
			std::cout 	<< "\nContent of the constructed span with vector 1:" << std::endl;
			vecA.displayValues();
			std::cout 	<< "Shortest span = " << vecA.shortestSpan()
						<< "\nLongest span =  " << vecA.longestSpan()
						<< std::endl;
		}
		catch (const std::bad_alloc& e)
		{
			std::cout << "Memory allocation error: "<< e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "\033[31mNew problem found\033[0m" << std::endl;
		}
		try 
		{
			std::cout 	<< "Content of the constructed span with vector 1 and 2" << std::endl;
			test.addVector(data);
			test.addVector(dataBis);
			test.displayValues();
			std::cout 	<< "Shortest span = " << test.shortestSpan()
						<< "\nLongest span =  " << test.longestSpan()
						<< std::endl;
		}
		catch (const std::bad_alloc& e)
		{
			std::cout << "Memory allocation error: "<< e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "\033[31mNew problem found\033[0m" << std::endl;
		}
		try 
		{
			std::cout 	<< "Content of the constructed span with from 5 to 9th elements of vector 1, and "
						<< "from second to " << dataBis.size() - 4 << " element of 2nd:" << std::endl;
			test.clear();
			std::cout 	<< "Previous to the operation: "<< std::endl;
			std::cout << "Size = " << test.size() << " Capacity = " << test.capacity() << std::endl;
			test.displayValues();
			test.addVector(data.begin() + 5 , data.begin() + 9);
			test.addVector(dataBis.begin() + 1 , dataBis.end() - 4);
			std::cout 	<< "After the operation: "<< std::endl;
			test.displayValues();
			std::cout 	<< "\nSize of the vector: " << test.size()
						<< "\nCapacity of the vector: " << test.capacity()
						<< "\nMinimum value = " << test.min()
						<< "\nMaximum value = " << test.max()
						<< "\nShortest span = " << test.shortestSpan()
						<< "\nLongest span =  " << test.longestSpan()
						<< "\n\nDisplay of the sorted values, the repetead ones are highlighted in green color:"
						<< std::endl;
			test.displaySorted();
		}
		catch (const std::bad_alloc& e)
		{
			std::cout << "Memory allocation error: "<< e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "\033[31mNew problem found\033[0m" << std::endl;
		}
		ft_goNext("\nUnsuccessful construction and fill from int vectors\n");
	}
	{
		std::vector<int> data;
		std::srand(time(0));
		int   	rand = 0;
		int 	len = MAX_VEC + 1;
		int 	minValue = -15 * MAX_VEC;
		int 	maxValue = 15 * MAX_VEC;
		int 	i = 0;
		Span test(len / 2);
		std::cout 	<< "Creation of a vector of " << len << " random numbers. "
					<< "\nMinimum value: "<< std::right << std::setw(6) << minValue 
					<< "\nMaximum value: "<< std::right << std::setw(6) << maxValue
					<< std::endl;
		for (; i < len; ++i)
		{
			rand = std::rand() % (maxValue - minValue + 1) + minValue;///random between minValue and maxValue
			data.push_back(rand);
			//std::cout 	<< "Vector value pos " << std::right << std::setw(3) << i << " = " 
			//			<< std::right << std::setw(3) << rand << std::endl;
		}
		//data.insert(data.begin(), -365);//
		try 
		{
			std::cout 	<< "Trial to construct a Span object outside of the boundaries:" 
						<< "\nMax capacity: " << MAX_VEC 
						<< "\tIntended number of elements: " << data.size()
						<< std::endl;
			Span  vecA(data);
			vecA.displayValues();
			std::cout 	<< "\nSize of the vector: " << vecA.size()
						<< "\nCapacity of the vector: " << vecA.capacity()
						<< "\nMinimum value = " << test.min()
						<< "\nMaximum value = " << test.max()
						<< "\nShortest span = " << vecA.shortestSpan()
						<< "\nLongest span =  " << vecA.longestSpan()
						<< std::endl;
		}
		catch (const std::bad_alloc& e)
		{
			std::cout << "Memory allocation error: "<< e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "\033[31mNew problem found\033[0m" << std::endl;
		}
		try 
		{
			std::cout 	<< "\nTrial to fill a Span object with a vector outside of the boundaries:" << std::endl;
			std::cout 	<< "Capacity of the object " << test.capacity()
						<< "\nElements in the <int> vector: " << data.size() << " of possible " << data.capacity()
						<< std::endl;
			test.addVector(data);
			test.displayValues();
			std::cout 	<< "\nMinimum value = " << test.min()
						<< "\nMaximum value = " << test.max() 
						<< "\nShortest span = " << test.shortestSpan()
						<< "\nLongest span =  " << test.longestSpan()
						<< std::endl;			
		}
		catch (const std::bad_alloc& e)
		{
			std::cout << "Memory allocation error: "<< e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "\033[31mNew problem found\033[0m" << std::endl;
		}
		ft_goNext("\nDisplay the values of the above created object:\n");
		test.displayValues();
		std::cout 	<< "\nSize of the vector: " << test.size()
					<< "\nCapacity of the vector: " << test.capacity()
					<< "\nMinimum value = " << test.min()
					<< "\nMaximum value = " << test.max()
					<< "\nShortest span = " << test.shortestSpan()
					<< "\nLongest span =  " << test.longestSpan()
					<< "\nDisplay of the sorted values, the repetead ones are highlighted in green color:\n"
					<< std::endl;
		test.displaySorted();
		ft_goNext("\nAppend\n");
	}
	{
		Span origin(42);
		Span dest_1(64);
		Span dest_2(23);
		int 	len = 42;
		int 	i = 0;
		int   	rand = 0;
		int 	minValue = -10 * MAX_VEC;
		int 	maxValue = 150 * MAX_VEC;

		for (; i < len; ++i)
		{
			rand = std::rand() % (maxValue - minValue + 1) + minValue;
			try
			{
				origin.addNumber(rand);
				dest_1.addNumber(rand * rand);
				if (i % 4 == 1)
				{
					dest_2.addNumber(rand *3);
				}
			}
			catch (const std::bad_alloc& e)
			{
				std::cout << "Memory allocation error: "<< e.what() << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
			catch (...)
			{
				std::cout << "\033[31mNew problem found\033[0m" << std::endl;
			}
			
		}
		std::cout 	<< "\nDisplaying values of origin\n" << std::endl;
		origin.displayValues();
		std::cout 	<< "\nDisplaying values of dest_1\n" << std::endl;
		dest_1.displayValues();
		std::cout 	<< "\nDisplaying values of dest_2\n" << std::endl;
		dest_2.displayValues();
		try
		{
			std::cout 	<< "\nAppend dest_1 to dest_2 (filled until reaching the limit.)\n";
			dest_2.appendSpan(dest_1);
		}
		catch (const std::bad_alloc& e)
		{
			std::cout << "Memory allocation error: "<< e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "\033[31mNew problem found\033[0m" << std::endl;
		}
		std::cout 	<< "\nDisplaying values of dest_2 after append\n" << std::endl;
		dest_2.displayValues();
		std::cout 	<< "\nSize of the vector: " << dest_2.size()
					<< "\nCapacity of the vector: " << dest_2.capacity()
					<< "\nMinimum value = " << dest_2.min()
					<< "\nMaximum value = " << dest_2.max()
					<< "\nShortest span = " << dest_2.shortestSpan()
					<< "\nLongest span =  " << dest_2.longestSpan()
					<< "\nDisplay of the sorted values, the repetead ones are highlighted in green color:\n"
					<< std::endl;
		dest_2.displaySorted();
	}
	return (0);
}
