/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:58:33 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/25 15:43:32 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

#include "Animal.class.hpp"
#include "Brain.class.hpp"

class Cat: public Animal
{
private:
    Brain  *m_brain;
    
public: 
    Cat(void);
    Cat(const Cat &other);  
    ~Cat();

    // Overloaded Operators
    Cat& operator=(const Cat &other);
    
    //Getter and setters
    Brain& getBrain(void);
    std::string getIdea(int num) const;
    void setIdea(std::string idea, int num);

    // Member functions
    virtual void    makeSound(void) const;
};

#endif