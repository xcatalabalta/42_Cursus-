/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:19:41 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/15 08:16:23 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.class.hpp"

// Default constructor (Orthodox Canonical Form)
Cure::Cure(void) : AMateria("cure") 
{
	std::cout 	<< this->getType() << " default constructor called"
				<< std::endl;
}

// Copy constructor (Orthodox Canonical Form)
Cure::Cure(const Cure& other) : AMateria(other) 
{
	std::cout 	<< other.m_type
				<< " copy constructor called" 
				<< std::endl;
	this->m_type = other.m_type;
}

// Destructor (Orthodox Canonical Form)
Cure::~Cure()
{
	std::cout	<< this->m_type << " deconstructor called"
				<< std::endl;
}

// Copy assignment operator (Orthodox Canonical Form)
Cure& Cure::operator=(const Cure& other) 
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
Cure* Cure::clone() const 
{
    return new Cure(*this);
}

// Use function
void Cure::use(ICharacter& target) 
{
    std::cout << "* heals "<< target.getName() <<"'s wounds *" << std::endl;
}
