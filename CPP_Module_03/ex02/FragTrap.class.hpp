/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 07:38:37 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/21 17:50:28 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

#include "ClapTrap.class.hpp"
class FragTrap: public ClapTrap
{
private:
    
public:
//Constructor and destructor
    FragTrap(void);
    FragTrap(const FragTrap &src);
    FragTrap(const std::string name);
    ~FragTrap();

// Overloaded Operators not really necessary, but for the sake of Orthodoxy
    FragTrap &operator=(const FragTrap &other);

//Public Functions
    void    highFivesGuy(void) const;

};
#endif