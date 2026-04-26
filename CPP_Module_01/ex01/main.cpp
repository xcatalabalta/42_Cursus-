/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:30:29 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/25 15:48:03 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"
#include <string>

int main (void)
{
    int             num = 5;
    std::string     str = "Manolo";

    Zombie  bicho1 = Zombie(str);
    bicho1.announce();    
    std::cout   << str <<": Meet my first son." <<std::endl;
    str += "'s";
    Zombie *group = zombieHorde(num, str);
    Zombie *current = group;
    std::cout   << "Testing the allocation and pointer to 1st of the group:" << std::endl;
    std::cout   << "\033[1;31mI am the first of " << str
                << std::endl << "I live at " << group << std::endl
                << "I insist, I live at " << current << "\033[0m"
                << std::endl;
    std::cout   << *bicho1.getName() <<": Meet my " << num << " sons"
                << std::endl;
    std::cout   << "Iteration with index: " << std::endl;
    for(int iter = 0; iter < num; iter++)
    {
        std::cout   << "Zombie " << iter + 1 << " ";
        group[iter].announce();
        std::cout   << "Zombie "<< iter + 1 << " lives at "<< &group[iter] 
                    << std::endl;
    }
    std::cout   << "\033[1;32mLet's move the pointerrss!\033[0m" << std::endl;
//Iteration with pointers
    for(; current < group + num; current++)
    {
        std::cout   << "Zombie " << (current - group) + 1 << " ";
        current->announce();
        std::cout   << "Zombie " << (current - group) + 1 << " lives at "
                    << current << std::endl;
    }
    delete [] group;
//Creation of an unnamed zombie and assigning afterwards a name    
    Zombie anonym;
    anonym.setName("PapiTox");
//Open color Italic yellow <= NOT A GOOD PRACTICE< JUST4FUN
    std::cout   <<"\033[3;33m";
    anonym.announce();
    num = 3;
//Important anonym.getName returns an address
    std::cout   << *anonym.getName() << ": Me wants to have "<< num <<" sons." 
                << "\033[0m" << std::endl;//closing color
// string manipulation just for learning
    std::string const* namePtr = anonym.getName();// Get the name as a const pointer
    std::string nameCopy = *namePtr;// Create a modifiable copy of the string
    str = "oooo's";
    nameCopy.append(str);// Append to the copy
// end of the string manipulation    
    Zombie *horda2 = zombieHorde(3, nameCopy);
    for (int iter = 0; iter < num; iter++)
    {
        horda2[iter].announce();
    }
    delete [] horda2;
    return (0);
}