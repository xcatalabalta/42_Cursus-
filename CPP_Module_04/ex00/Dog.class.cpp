/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:59:04 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/03 15:00:24 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"

Dog::Dog(void): Animal("Dog")
{
    std::cout << "\033[3mDOG default constructor called\033[0m" << std::endl;
}

Dog::Dog(const Dog &other): Animal(other)
{
    std::cout << "\033[3mDOG copy constructor called\033[0m" << std::endl;
    //*this = other;
    m_type = other.m_type;
}

Dog::~Dog()
{
    std::cout   << "Default DOG \033[3;31mdestructor\033[0m: Animal type " 
                << this->getType() << std::endl;
}

void    Dog::makeSound(void) const
{
        std::cout << "* Waf! *" << std::endl;
}