/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:06:19 by fcatala-          #+#    #+#             */
/*   Updated: 2024/10/31 17:22:54 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
#define HUMANA_CLASS_HPP

#include "Weapon.class.hpp"
#include <string>

class HumanA
{
private:
    std::string _name;
    Weapon &_weapon;

public:
    HumanA(std::string const name, Weapon &weapon);
    ~HumanA();

    void attack() const;
};

#endif
