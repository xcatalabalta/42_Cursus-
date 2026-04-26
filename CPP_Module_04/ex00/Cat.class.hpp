/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:58:33 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/25 12:31:06 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

#include "Animal.class.hpp"

class Cat: public Animal
{
private:
    
public: 
    Cat(void);
    Cat(const Cat &other);
    ~Cat();

    // Overloaded Operators
    using   Animal::operator=;//no need to redefine
    
    //Getter and setters

    // Member functions
    virtual void    makeSound(void) const;
};

#endif