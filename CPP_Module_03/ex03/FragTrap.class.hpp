/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 07:38:37 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/20 17:11:38 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

# define F_HIT  100
# define F_ENER 100
# define F_ATT  30

# include "ClapTrap.class.hpp"
//# include "ScavTrap.class.hpp"

class FragTrap: virtual public ClapTrap
{
private:
    
public:
//Constructor and destructor
    FragTrap(void);
    FragTrap(const FragTrap &other);
    FragTrap(const std::string& name);
    virtual ~FragTrap();

// Overloaded Operators
    FragTrap &operator=(const FragTrap &other);

//Public Functions
    void    highFivesGuy(void) const;

};
#endif