/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:19:30 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/03 17:15:07 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.class.hpp"

// Constructors and destructor
AAnimal::AAnimal(void): m_type("Undefined animal")
{
    std::cout << "\033[3;32mAnimal default constructor called\033[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
    std::cout << "\033[3;32mAnimal copy constructor called\033[0m" << std::endl;
    //*this = other;
    m_type = other.m_type;
}

AAnimal::AAnimal(std::string type): m_type(type)
{
    std::cout   << "\033[3;32mAnimal named constructor called type "
                << type << "\033[0m" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout   << "\033[3;31mDefault destructor of Animal " << this->getType()
                << "\033[0m" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    std::cout << "\033[3;32mAnimal assignation called\033[0m" << std::endl;
    if (this != &other)
    {
        m_type = other.m_type;
    }
    return(*this);
}

// Getters and setters
std::string AAnimal::getType(void) const
{
    return (this->m_type);
}

const std::string *AAnimal::getAddress(void) const
{
    const std::string	&stringREF = this->m_type;//This can be possible because m_type is a string
    return(&stringREF);
}

void        AAnimal::setType(const std::string newtype)
{
    this->m_type = newtype;
}

// Purely Abstract functions
/*
void    AAnimal::makeSound(void) const
{
    std::cout   <<"* Random noise *" << std::endl;
}
*/