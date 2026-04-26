/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:54:28 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/21 18:18:27 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_CLASS_HPP
# define DIAMONDTRAP_CLASS_HPP

# include "FragTrap.class.hpp"
# include "ScavTrap.class.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
    std::string     _name;
public:
    DiamondTrap(void);
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap &src);

    virtual ~DiamondTrap();
    // Overloaded Operators
	DiamondTrap &operator=(const DiamondTrap &other);

    virtual void attack(const std::string& target);//using?
    virtual void    identify(void) const;
    void    whoAmI(void) const;
};

#endif