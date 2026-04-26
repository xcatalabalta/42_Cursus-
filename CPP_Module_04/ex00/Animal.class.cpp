/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:19:30 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/25 10:45:16 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"

// Constructors and destructor
Animal::Animal(void): m_type("Undefined animal")
{
    std::cout << "\033[3;32mAnimal default constructor called\033[0m" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "\033[3;32mAnimal copy constructor called\033[0m" << std::endl;
    //*this = other;
    m_type = other.m_type;
}

Animal::Animal(std::string type): m_type(type)
{
    std::cout   << "\033[3;32mAnimal named constructor called type "
                << type << "\033[0m" << std::endl;
}

Animal::~Animal()
{
    std::cout   << "\033[3;31mDefault destructor of Animal " << this->getType()
                << "\033[0m" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "\033[3;32mAnimal assignation called\033[0m" << std::endl;
    if (this != &other)
    {
        m_type = other.m_type;
    }
    return(*this);
}

// Getters and setters
std::string Animal::getType(void) const
{
    return (this->m_type);
}

void        Animal::setType(const std::string newtype)
{
    this->m_type = newtype;
}

// Member functions
void    Animal::makeSound(void) const
{
    std::cout   <<"* Random noise *" << std::endl;
}