/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:25:11 by fcatala-          #+#    #+#             */
/*   Updated: 2024/10/31 17:49:44 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_HPP
#define HUMANB_CLASS_HPP

#include "Weapon.class.hpp"
#include <string>

class HumanB
{
private:
    std::string _name;
    Weapon* _weapon;

public:
    HumanB(std::string const name);
    ~HumanB();

    void attack() const;
    void setWeapon(Weapon& weapon);
};

#endif