/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:12:22 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/23 16:36:27 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
    return ;
}

Zombie::Zombie()
{
    return ;
}
Zombie::~Zombie()
{
    std::cout << this->_name <<" is dead." << std::endl;
    return ;
}

void Zombie::announce( void ) const
{
    std::cout << this->_name << ": Braiiiiiiinnnzzz..." << std::endl;
    return ;
}

void Zombie::setName(std::string const name)
{
    this->_name = name;
    return ;
}

std::string const* Zombie::getName() const
{
    return &(this->_name);
}