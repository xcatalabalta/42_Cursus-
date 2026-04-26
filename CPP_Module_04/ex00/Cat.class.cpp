/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:59:04 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/03 14:59:30 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"

Cat::Cat(void): Animal("Cat")
{
    std::cout << "\033[3mCAT default constructor called\033[0m" << std::endl;
}

Cat::Cat(const Cat &other): Animal(other)
{
    std::cout << "\033[3mCAT copy constructor called\033[0m" << std::endl;
    //*this = other;
    m_type = other.m_type;
}

Cat::~Cat()
{
    std::cout   << "Default CAT \033[3;31mdestructor\033[0m: Animal type " 
                << this->getType()<< std::endl;
}

//Getter and setters 

// Public functions
void    Cat::makeSound(void) const
{
        std::cout << "* Meow! *" << std::endl;
}