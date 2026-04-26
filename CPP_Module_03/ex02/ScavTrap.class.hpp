/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 07:38:37 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/21 17:50:28 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CLASS_HPP
# define SCAVTRAP_CLASS_HPP

#include "ClapTrap.class.hpp"
class ScavTrap: public ClapTrap
{
private:
    //bool    m_guard;
public:
//Constructor and destructor
    ScavTrap(void);
    ScavTrap(const ScavTrap &src);
    ScavTrap(const std::string name);
    ~ScavTrap();

// Overloaded Operators
    ScavTrap &operator=(const ScavTrap &other);

//Public Functions
    void    attack(const std::string& target);
    void    guardGate(void);

//Extra function (not required)
    void    identify(void) const;
};
#endif