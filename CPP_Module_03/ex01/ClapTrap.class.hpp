/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:03:52 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/21 17:37:21 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string     _name;
    unsigned int    _hit_pts;
    unsigned int    _energy_pts;
    unsigned int    _attack_dmg;

public:
    //Constructors and destructor
    ClapTrap(void);
    ClapTrap(const ClapTrap &other);
    ClapTrap(std::string name);
    virtual ~ClapTrap();

    // Overloaded Operators
	ClapTrap &operator=(const ClapTrap &other);

    //Public functions
    void            attack(const std::string& target);
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);
    
    //Extra functions (not required but useful or fun)
    void            identify(void) const;
    void            hit(ClapTrap &robot);
    //Getter used to perform attacks
    unsigned int    getAttack(void) const;
};

#endif