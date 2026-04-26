/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:54:00 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/05 18:22:23 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.class.hpp"
#include "ICharacter.class.hpp"


// Default constructor (Orthodox Canonical Form)
AMateria::AMateria() : m_type("undefined") 
{
	std::cout 	<< "Materia default constructor called."
				<< std::endl;
}

// Parameterized constructor
AMateria::AMateria(std::string const & type) : m_type(type) 
{
	std::cout 	<< "Materia parameterized constructor called "
				<< "of type " << type << "."
				<< std::endl;
}

// Copy constructor (Orthodox Canonical Form)
AMateria::AMateria(const AMateria& other)// : type(other.type)
{
	std::cout 	<< "\033[3;32mMateria copy constructor called.\033[0m" 
				<< std::endl;
	this->m_type = other.m_type;
}

// Destructor (Orthodox Canonical Form)
AMateria::~AMateria() 
{
	std::cout   << "\033[3;31mDefault destructor of materia " << this->getType()
                << ".\033[0m" 
				<< std::endl;
}

// Copy assignment operator (Orthodox Canonical Form)
AMateria& AMateria::operator=(const AMateria& other) 
{
    if (this != &other) 
	{
        this->m_type = other.m_type;
    }
	std::cout 	<< "Pure assignment operator called for "  
				<< this->m_type << "."
				<< std::endl;
    return (*this);
}

// Getter
const std::string  & AMateria::getType(void) const 
{
    return (m_type);
}

// Default implementation of use()
void AMateria::use(ICharacter& target) 
{
	std::cout 	<< "* uses " << this->m_type 
				<< " on " << target.getName() << " *" 
				<< std::endl;
}
