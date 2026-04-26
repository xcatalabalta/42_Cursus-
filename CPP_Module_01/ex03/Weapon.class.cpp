/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:47:53 by fcatala-          #+#    #+#             */
/*   Updated: 2024/10/31 15:57:21 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.class.hpp"

Weapon::Weapon(std::string const &type) : _type(type){}
Weapon::~Weapon(){}

std::string const & Weapon::getType() const
{
    return (this->_type);
}

void Weapon::setType(std::string const type)
{
    this->_type = type;
}