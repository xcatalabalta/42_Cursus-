/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:01:46 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/21 17:37:21 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"

int main (void)
{
    {
        ClapTrap    Manolito("ClapManolito");
        ScavTrap    Pepe("ScavJoselito");
        ClapTrap    Juan(Manolito);
        ScavTrap    Nobody;
        ClapTrap    Nadie;

        std::cout << "\nLet's equalize the Scavvers!" << std::endl;
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
            Manolito.takeDamage(Pepe.getAttack() - 15);
            Manolito.beRepaired(Pepe.getAttack());
            Pepe.attack("Nobody");
            Nobody.takeDamage(Pepe.getAttack());
            Nobody.guardGate();
            Manolito.identify();
            Pepe.identify();
            Nobody.identify();
        }
        std::cout << std::endl;
        std::cout << "Final result: " << std::endl;
        Pepe.identify();
        Manolito.identify();
        Juan.identify();
        Nobody.identify();
        Nadie.identify();
    }
    {
        std::cout << "\nHitting time!" << std::endl;
        ClapTrap    Tomas("Tomas");
        ScavTrap    Dante("Dante");

        std::cout << "\nHere are our gladiators" << std::endl;
        Tomas.identify();
        Dante.identify();
        std::cout << "\nLet's start the combat" << std::endl;
        Tomas.beRepaired(32);
        for (int i = 0; i <= 3; i++)
        {
            Tomas.identify();
            Dante.hit(Tomas);
            Dante.identify();
        }
        Dante.guardGate();
        Tomas.identify();
        Dante.identify();
    }
    return (0);
}