/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:19:41 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/05 18:22:23 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.class.hpp"

// Default constructor (Orthodox Canonical Form)
Ice::Ice() : AMateria("ice") 
{
	std::cout 	<< this->getType() << " default constructor called."
				<< std::endl;
}

// Copy constructor (Orthodox Canonical Form)
Ice::Ice(const Ice& other) : AMateria(other) 
{
	std::cout 	<< other.m_type
				<< " copy constructor called." 
				<< std::endl;
	this->m_type = other.m_type;
}

// Destructor (Orthodox Canonical Form)
Ice::~Ice()
{
	std::cout	<< this->m_type << " deconstructor called."
				<< std::endl;
}

// Copy assignment operator (Orthodox Canonical Form)
Ice& Ice::operator=(const Ice& other) 
{
    if (this != &other) 
	{
		this->m_type = other.m_type;
    }
	std::cout 	<< this->m_type 
				<< " assignment operator called."  
				<< std::endl;
    return (*this);
}

// Clone function
Ice* Ice::clone() const 
{
    return new Ice(*this);
}

// Use function
void Ice::use(ICharacter& target) 
{
    std::cout 	<<"* shoots an ice bolt at "
				<< target.getName() << " *" << std::endl;
}
