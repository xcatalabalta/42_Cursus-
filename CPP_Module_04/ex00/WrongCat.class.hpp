/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:58:33 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/25 12:31:06 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

#include "WrongAnimal.class.hpp"

class WrongCat: public WrongAnimal
{
private:
    
public: 
    WrongCat(void);
    WrongCat(const WrongCat &other);
    ~WrongCat();

    // Overloaded Operators
    using WrongAnimal::operator	=;//no need to redefine
    
    //Getter and setters
    
    // Member functions
    virtual void    makeSound(void) const;
};

#endif