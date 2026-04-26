/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:13:07 by fcatala-          #+#    #+#             */
/*   Updated: 2025/02/01 14:54:18 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

#include <iostream>
#include <string>


class Animal
{
protected:
    std::string m_type;
    
public:
    Animal(void);
    Animal(const Animal &other);
    Animal(const std::string type);
    virtual ~Animal();

    // Overloaded Operators
	Animal&             operator=(const Animal& other);

    // Getters and setters
    std::string         getType(void) const;
    const std::string   *getAddress(void) const;
    void                setType(const std::string newtype);
    
    // Member functions
    virtual void        makeSound(void) const;
    
};

#endif