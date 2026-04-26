/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 07:38:37 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/21 18:31:40 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CLASS_HPP
# define SCAVTRAP_CLASS_HPP

# define S_HIT  666 //100
# define S_ENER 6 //100
# define S_ATT  99 //30

#include "ClapTrap.class.hpp"
class ScavTrap: virtual public ClapTrap
{
private:
    //bool    m_guard;
public:
//Constructor and destructor
    ScavTrap(void);
    ScavTrap(const ScavTrap &src);
    ScavTrap(const std::string& name);
    virtual ~ScavTrap();

// Overloaded Operators
    ScavTrap &operator=(const ScavTrap &other);

//Public Functions
    virtual void    attack(const std::string& target);
    void    guardGate(void);
    unsigned int getEnergy(void) const;

//Extra functions (not required)
    virtual void    identify(void) const;
};
#endif