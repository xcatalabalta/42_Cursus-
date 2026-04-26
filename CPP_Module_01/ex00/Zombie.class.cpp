/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:12:22 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/23 14:27:54 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

Zombie::Zombie(std::string name) : _name(name){}

Zombie::~Zombie()
{
    std::cout   << this->_name <<" is dead." 
                << std::endl;
    return ;
}

void Zombie::announce() const
{
    std::cout   << this->_name << ": Braiiiiiiinnnzzz..." 
                << std::endl;
    return ;
}