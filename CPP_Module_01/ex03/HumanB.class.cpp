/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:27:35 by fcatala-          #+#    #+#             */
/*   Updated: 2024/10/31 19:18:29 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.class.hpp"

HumanB::HumanB(std::string const name) : _name(name), _weapon(NULL)
{}
HumanB::~HumanB()
{}

void HumanB::attack() const
{
    if (!_weapon)
    {
        std::cout << this->_name << " attakcs with their " << std::endl;
        return ;
    }
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
   this->_weapon = &weapon;
   return ;    
}
