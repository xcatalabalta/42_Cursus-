/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 08:15:36 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/21 11:22:44 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Span.class.hpp"

Span::Span(): m_N(0)
{
	m_vec.reserve(0);
}

Span::Span(unsigned int N)
{
	if (N > MAX_VEC || N > m_vec.max_size())
	{
		/*
		std::cerr << "Max capacity exceeded\n";//Prevents collapse of the machine
		exit (1);//Exits program at compilation
		*/
		//m_N = 0;
		//m_vec.reserve(0);
		throw std::length_error("\033[31mVector size exceeds maximum capacity\033[0m");
	}
	else
	{
		m_N = N;
		m_vec.reserve(N);
	} 
}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		m_N = other.m_N;
		m_vec = other.m_vec;
	}
	return (*this);
}

Span::~Span(){}

//Additional constructors
Span::Span(unsigned int N, const int value)
{
	if (N >= MAX_VEC || N >= m_vec.max_size())
	{
		/*
		std::cerr << "Max capacity exceeded\n";//Prevents collapse of the machine
		exit (1);//Exits program at compilation
		*/
		throw std::length_error("\033[31mVector size exceeds maximum capacity\033[0m");
	}
	else
	{
		m_N = N;
		m_vec.reserve(N);
		for(unsigned int i = 0; i < N; ++i)
		{
			this->addNumber(value);
		}
	}
}

Span::Span(const std::vector<int> vec)
{
	if (vec.size() > MAX_VEC)
	{
		throw std::length_error("\033[31mVector size exceeds maximum capacity\033[0m");
	}
	m_N = vec.size();
	m_vec.reserve(m_N);
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		this->addNumber(*it);
	}
}


void  Span::addNumber(const int number)
{
	if (m_vec.size() >= m_N)
		throw std::length_error("\033[31mContainer full\033[0m");
	m_vec.push_back(number);
}

/*
// first implementation
unsigned int Span::shortestSpan() const
{
	//clock_t start = clock();
	if (m_N < 2)
	{
		throw Span::NotEnoughElements();
	}
	int minSpan = std::numeric_limits<int>::max();
	std::vector<int> aux = m_vec;
	std::sort(aux.begin(), aux.end());
	for (std::vector<int>::iterator it = aux.begin() + 1; it != aux.end(); ++it)
	{
		int span = *it - *(it -1);
		if (minSpan > span)
		{
			minSpan = span;
			if (minSpan == 0)
			{
				break ;
			}
		}
	}
	//clock_t end = clock();
    //double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    //std::cout << "Execution time: \t" << std::fixed  << time_spent << " seconds" << std::endl;
	return (minSpan); 
}
*/

// Deliveres implementation
unsigned int Span::shortestSpan(void) const
{
	if (m_N < 2)
	{
		throw Span::NotEnoughElements();
	}
	std::vector<int> aux = m_vec;
	std::sort(aux.begin(), aux.end());
	std::adjacent_difference(aux.begin(), aux.end(), aux.begin());
	return (*std::min_element(aux.begin() + 1 , aux.end()));
}

unsigned int Span::longestSpan(void) const
{
	if (m_N < 2)
	{
		throw Span::NotEnoughElements();
	}
	int max = *std::max_element(m_vec.begin(), m_vec.end());
	int min = *std::min_element(m_vec.begin(), m_vec.end());
	int span = max - min;
	return (span);
}

int Span::max(void) const
{
	int max = *std::max_element(m_vec.begin(), m_vec.end());
	return (max);
}

int Span::min(void) const
{
	int min = *std::min_element(m_vec.begin(), m_vec.end());
	return (min);
}

void Span::addVector(std::vector<int>::const_iterator init, std::vector<int>::const_iterator end)
{
	std::vector<int>::const_iterator it = init;
	//std::vector<int>::const_iterator fin = end;
	for(; it != end; ++it)
	{
		this->addNumber(*it);
	}
}

void	Span::addVector(const std::vector<int> &vec)
{
	for(std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		this->addNumber(*it);
	}
}

void Span::appendSpan(const Span & other)
{
	std::vector<int> aux = other.m_vec;
	this->addVector(aux);
}


//Additional functions
void Span::displayValues(void) const
{
	if (m_N == 0)
	{
		std::cout << "Empty container" << std::endl;// An empty container is not an exception
	}
	std::vector<int> aux = m_vec;
	for (std::vector<int>::iterator vec_it = aux.begin(); vec_it < aux.end(); ++vec_it)
	{
		std::cout << std::right << std::setw(11) << *vec_it << std::endl;
	}
}

void Span::displaySorted(void) const
{
	std::vector<int> aux = m_vec;
	std::sort(aux.begin(), aux.end());
	for (std::vector<int>::iterator vec_it = aux.begin(); vec_it < aux.end(); ++vec_it)
	{
		if (vec_it != aux.begin() && (*vec_it == *(vec_it - 1)))
			std::cout << "\033[32m";
		std::cout << std::right << std::setw(11) << *vec_it << "\033[0m" << std::endl;
	}
}


unsigned int Span::capacity(void) const
{
	return (m_N);
}

unsigned int Span::size(void) const
{
	return (m_vec.size());
}

void Span::clear(void)
{
	this->m_vec.clear();
}

// Custom exception
const char *Span::NotEnoughElements::what() const throw()
{
	return ("\033[31mError:\033[0m Not enough elements to perform this action\n");
}