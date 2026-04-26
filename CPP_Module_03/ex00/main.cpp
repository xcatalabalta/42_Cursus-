/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:01:46 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/03 06:39:30 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

int main (void)
{
    ClapTrap    Manolito("Manolito");
    ClapTrap    Pepe("Joselito");
    ClapTrap    Juan(Manolito);
    ClapTrap    Nobody;
    ClapTrap    Nadie;

    Juan = Nobody = Pepe;
    
    std::cout << "\nHere are our gladiators" << std::endl;
    Manolito.identify();
    Pepe.identify();
    Juan.identify();
    Nobody.identify();
    Nadie.identify();
    std::cout << "\nLet's start the combat" << std::endl;
    for (int i = 0; i < 12; i++)
    {
        std::cout << std::endl;
        Pepe.attack("Manolito");
        Manolito.takeDamage(i);
        Manolito.beRepaired(3);
        Manolito.identify();
        Pepe.identify();
    }
    std::cout << std::endl;
    std::cout << "Final result: " << std::endl;
    Pepe.identify();
    Manolito.identify();
    Juan.identify();
    Nobody.identify();
    Nadie.identify();
    return (0);
}