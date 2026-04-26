/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:58:33 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/03 16:33:46 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

#include "AAnimal.class.hpp"
#include "Brain.class.hpp"

class Dog: public AAnimal
{
private:
    Brain  *m_brain;
    
public: 
    Dog(void);
    Dog(const Dog &other);  
    ~Dog();

    // Overloaded Operators
    Dog& operator=(const Dog &other);
    
    //Getter and setters
    //Brain& getBrain(void);
    std::string getIdea(int num) const;
    void setIdea(std::string idea, int num);

    // Member functions
    virtual void    makeSound(void) const;
};

#endif