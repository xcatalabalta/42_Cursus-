/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:13:07 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/18 11:54:56 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string m_type;
public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal(const std::string type);
    virtual ~WrongAnimal();

    // Overloaded Operators
	WrongAnimal&          operator=(const WrongAnimal& other);

    // Getters and setters
    std::string     getType(void) const;
    void            setType(const std::string newtype);
    
    // Member functions
    virtual void    makeSound(void) const;
    
};

#endif