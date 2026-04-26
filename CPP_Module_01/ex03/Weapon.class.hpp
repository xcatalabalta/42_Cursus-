/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:12:17 by fcatala-          #+#    #+#             */
/*   Updated: 2024/10/30 16:34:21 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
#define WEAPON_CLASS_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
    std::string _type;

public:
    Weapon(std::string const &type);
    ~Weapon();
    std::string const & getType() const;
    void                setType(std::string const type);
};

#endif