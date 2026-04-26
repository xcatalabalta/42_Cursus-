/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:59:04 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/03 16:31:39 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"

Cat::Cat(void): AAnimal("Cat")
{
    std::cout << "\033[3mCAT default constructor called\033[0m" << std::endl;
    //m_brain = new Brain();
    this->m_brain = new Brain();
}

Cat::Cat(const Cat &other): AAnimal(other)
{
    std::cout << "\033[3mCAT copy constructor called\033[0m" << std::endl;
    this->m_type = other.m_type;
    this->m_brain = new Brain(*other.m_brain);
    //this->m_brain = other.m_brain;//It creates a shallow copy
    //*this = other;
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << "\033[3mCAT assignation called\033[0m" << std::endl;
    if (this != &other)
    {
        this->m_type = other.m_type;
        delete this->m_brain;
        this->m_brain = new Brain(*other.m_brain);
        //this->m_brain = other.m_brain;
    }
    return (*this);

}

Cat::~Cat()
{
    std::cout << "Default CAT destructor: Animal type " << this->getType()<< std::endl;
    delete this->m_brain;
}

//Getter and setters
Brain& Cat::getBrain(void)
{
    return *this->m_brain;
}

std::string Cat::getIdea(int num) const
{
    return this->m_brain->getIdea(num);
}


void    Cat::setIdea(std::string idea, int num)
{
    this->m_brain->setIdea(idea, num);
}

// Public functions
void    Cat::makeSound(void) const
{
        std::cout << "* Meow! *" << std::endl;
}