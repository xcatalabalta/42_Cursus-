/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:13:07 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/03 17:15:07 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_CLASS_HPP
# define AANIMAL_CLASS_HPP

#include <iostream>
#include <string>


class AAnimal
{
protected:
    std::string m_type;
    
public:
    AAnimal(void);
    AAnimal(const AAnimal &other);
    AAnimal(const std::string type);
    virtual ~AAnimal();

    // Overloaded Operators
	AAnimal&             operator=(const AAnimal& other);

    // Getters and setters
    std::string         getType(void) const;
    const std::string   *getAddress(void) const;
    void                setType(const std::string newtype);
    
    // Purely Abstract function
    virtual void        makeSound(void) const = 0;
    
};

#endif