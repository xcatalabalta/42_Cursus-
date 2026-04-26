/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:19:30 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/26 10:53:16 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.class.hpp"

// Constructors and destructor
WrongAnimal::WrongAnimal(void): m_type("Undefined Wrong animal")
{
    std::cout << "\033[3mWrong Animal default constructor called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "\033[3mWrongAnimal copy constructor called\033[0m" << std::endl;
    *this = other;
}

WrongAnimal::WrongAnimal(std::string type): m_type(type)
{
    std::cout   << "\033[3mWrongAnimal named constructor called for the type "
                << type << "\033[0m" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "\033[31mDestructor\033[0m of WrongAnimal " << this->getType()<< std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "\033[3mWrongAnimal assignation called\033[0m" << std::endl;
    if (this != &other)
    {
        this->m_type = other.m_type;
    }
    return(*this);
}

// Getters and setters
std::string WrongAnimal::getType(void) const
{
    return (this->m_type);
}

void        WrongAnimal::setType(const std::string newtype)
{
    this->m_type = newtype;
}

// Member functions
void    WrongAnimal::makeSound(void) const
{
    std::cout   <<"\033[32m* Wrong and Random noise *\033[0m" << std::endl;
}