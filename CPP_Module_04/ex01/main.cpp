/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:15:47 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/03 15:54:27 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include <cstdio>

int main(void)
{
    //Cat *tom = new Cat();
    Dog         *tom = new Dog();
    
    std::cout   << "\nWe are going to check the Deep Copy and the shallow Copy\n"
                << std::endl;
    tom->setIdea("Sleep all day long.\n", 32);
    std::cout   << "Our first animal has an idea:" << std::endl;
    std::cout   << "The idea is " << tom->getIdea(32) 
                << std::endl;
    //Cat *sylvo = new Cat(*tom);
    Dog *sylvo = new Dog(*tom);
    std::cout   << "Our second animal (copied from first) has the same idea:" << std::endl;
    std::cout   << "The idea is " << sylvo->getIdea(32) 
                << std::endl;
    tom->setIdea("\033[3;32mEat as much as I can\n\033[0m", 32);
    std::cout   << "Our second animal (copied from first) still has the same idea:" << std::endl;
    std::cout   << "The idea is " << sylvo->getIdea(32) 
                << std::endl;
    std::cout   << "But our first animal has another idea:" << std::endl;
    std::cout   << "The NEW idea is " << tom->getIdea(32) 
                << std::endl;
    std::cout   << "Our second animal (copied from first) still has the same idea:" << std::endl;
    std::cout   << "The idea is " << sylvo->getIdea(32) 
                << std::endl;
    sylvo->setIdea("Living la vida loka\n", 69);
    std::cout   << "A new idea (located in another part of the brain) for sylvo is " << sylvo->getIdea(69)
                << "but tom thinks " << tom->getIdea(69)
                << "\n<nothing should appear>"
                << "\nIn fact tom lives at\t" << tom->getAddress()
                << "\nand sylvo lives at\t" << sylvo->getAddress()
                << std::endl;
    delete tom;
    std::cout   << "\nTom is gone but sylvo's idea still exists: " 
                << sylvo->getIdea(32) 
                << std::endl;
    delete sylvo;
    std::cout   << "\n\nNow that both have gone, take your time to revise the accuracy "
                << "of the above implementation.\n"
                << "Enter any key to continue with the next section."
                << std::endl;
    getchar();
    Dog     lassy;
    //Cat   lassy;
    Dog     fritz;
    //Cat   fritz;
    lassy.setIdea("Can we finish?", 25);
    fritz = lassy;
    std::cout   << "The 25th idea of lassy is " << lassy.getIdea(25)
                << "\nand the 25th idea of fritz is " << fritz.getIdea(25)
                << std::endl;
    lassy.setIdea("\033[36;3mIt is almost time of my 8th nap\n\033[0m", 25);
    std::cout   << "The idea of lassy is: " << lassy.getIdea(25)
                << "\nand the idea of fritz is " << fritz.getIdea(25)
                << std::endl;
    std::cout   << "What does it happen if we check an idea where there isn't anyone?"
                <<  std::endl;
    lassy.getIdea(69);
    std::cout   << "Of course, nothing appears\n"
                << "What does it happen if we try to set an idea out of the range?"
                <<  std::endl;
    fritz.setIdea("Have some food", 105);
    std::cout   << "What does it happen if we check an idea out of the range?"
                <<  std::endl;
    lassy.getIdea(-999);
    std::cout   << "\nTake your time to revise the accuracy "
                << "of the above implementation.\n"
                << "Enter any key to continue with the next section (The arrays)."
                << std::endl;
    getchar();
    const Animal    *gang[10];
    for (int i = 0; i < 10; i++)
    {
        if (i % 2)
        {
            gang[i] = new Dog();
            std::cout   << "New dog located at " << gang[i]->getAddress()
                        << std::endl;
            std::cout   << "New dog barks!" << std::endl;
            gang[i]->makeSound();
        }
        else
        {
            gang[i] = new Cat();
            std::cout   << "New cat located at " << gang[i]->getAddress()
                        << std::endl;
            std::cout   << "New cat meows!" << std::endl;
            gang[i]->makeSound();
        }
    }
    std::cout << "Deleting cats & dogs" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout   << "\nDeleting " << gang[i]->getType()
                    << " the animal in pos " << i
                    << " from address " << gang[i]->getAddress()
                    << std::endl;
        delete gang[i];      
    }
    return (0);
}