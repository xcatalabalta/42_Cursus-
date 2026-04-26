/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:59:04 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/03 15:01:38 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.class.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
    std::cout << "\033[3mWrongCat default constructor called\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other)
{
    std::cout << "\033[3mWrongCat copy constructor called\033[0m" << std::endl;
    *this = other;
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor of Wrong\033[36mCat\033[0mAnimal type " << this->getType()<< std::endl;
}

void    WrongCat::makeSound(void) const
{
        std::cout << "\033[32m* WRONG Meow! *\033[0m" << std::endl;
}