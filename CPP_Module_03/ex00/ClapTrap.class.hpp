/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:03:52 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/21 17:19:10 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
    std::string     _name;
    unsigned int    _hit_pts;
    unsigned int    _energy_pts;
    unsigned int    _attack_dmg;

public:
    //Constructors and destructor
    ClapTrap(void);
    ClapTrap(const ClapTrap &other);
    ClapTrap(std::string name);
    ~ClapTrap();

    // Overloaded Operators
	ClapTrap &operator=(const ClapTrap &other);

    //Public functions
    void            attack(const std::string& target);
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);
    //Extra function (not required but useful)
    void            identify(void) const;
};

#endif