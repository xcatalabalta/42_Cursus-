/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:58:33 by fcatala-          #+#    #+#             */
/*   Updated: 2025/02/01 13:53:37 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

#include "Animal.class.hpp"

class Dog: public Animal
{
private:

public: 
    Dog(void);
    Dog(const Dog &other);

    ~Dog();

    // Overloaded Operators
    using   Animal::operator=;//no need to redefine if both classes have the /
    
    // Member functions
    virtual void    makeSound(void) const;
};

#endif