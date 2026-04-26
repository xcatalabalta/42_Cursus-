/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:03:52 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/21 18:13:41 by fcatala-         ###   ########.fr       */
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
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    virtual ~ClapTrap();

    // Overloaded Operators
	ClapTrap &operator=(const ClapTrap &other);

    

    //Public functions
    virtual void attack(const std::string& target);//revisar
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
    
    //Extra functions (not required)
    virtual void    identify(void) const;
    //Getter
    std::string     getName(void) const;
    unsigned int    getAttack(void) const;
};

#endif