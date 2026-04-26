/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:59:04 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/03 15:08:22 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"

Dog::Dog(void): Animal("Dog")
{
    std::cout << "\033[3mDOG default constructor called\033[0m" << std::endl;
    m_brain = new Brain();
}

Dog::Dog(const Dog &other): Animal(other)
{
    std::cout << "\033[3mDOG copy constructor called\033[0m" << std::endl;
    m_type = other.m_type;
    m_brain = new Brain(*other.m_brain);
}

Dog::~Dog()
{
    std::cout << "Default DOG destructor: Animal type " << m_type << std::endl;
    delete m_brain;
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout << "\033[3mDOG assignation called\033[0m" << std::endl;
    if (this != &other)
    {
        m_type = other.m_type;
        delete m_brain;
        m_brain = new Brain(*other.m_brain);
    }
    return (*this);

}

std::string Dog::getIdea(int num) const
{
    return (m_brain->getIdea(num));
}


void    Dog::setIdea(std::string idea, int num)
{
    m_brain->setIdea(idea, num);
}


void    Dog::makeSound(void) const
{
        std::cout << "* Waf! *" << std::endl;
}