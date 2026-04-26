/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:01:46 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/21 18:02:04 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"
#include "FragTrap.class.hpp"

int main (void)
{
    {
        ClapTrap    Manolito("Manolito");
        ClapTrap    Juan(Manolito);
        ClapTrap    Nadie;
        ScavTrap    Pepe("Joselito");
        ScavTrap    Nobody;
        ScavTrap    Kako;
        FragTrap    Nene("Morenito");
        FragTrap    Otro;
        FragTrap    Moto;

        Juan = Nobody = Pepe;
        Nadie = Nene;
        Otro = Nene;
        std::cout << "\nUps! Somebody is leaving!" << std::endl;
        Otro.~FragTrap();
        Kako.~ScavTrap();
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
            Pepe.attack(Nobody.getName());
            Nobody.takeDamage(Pepe.getAttack());
            Nobody.guardGate();
            Nene.highFivesGuy();
            Nobody.attack(Nene.getName());
            Nene.takeDamage(Nobody.getAttack() - 7);
            Nene.beRepaired(3 * (i % 2));
            Nene.attack("Antes Moto");
            Moto.takeDamage(Nene.getAttack());
            Moto.highFivesGuy();

            std::cout << "\nAfter round "<< i + 1 << std::endl;
            Nene.identify();
            Manolito.identify();
            Pepe.identify();
            Nobody.identify();
            Moto.identify();
        }
        std::cout << std::endl;
        std::cout << "Final result: " << std::endl;
        Pepe.identify();
        Manolito.identify();
        Juan.identify();
        Nobody.identify();
        Nadie.identify();
        Moto.identify();
    }
    {
        std::cout   << "\nNEW BLOCK!" << std::endl;
        ClapTrap    clapper("Clapper");
        ClapTrap    upper("Upper");
        ScavTrap    hitman("Hitman");
        FragTrap    happy("Happy");

        std::cout   << "\nHere are the robots"
                    << std::endl;
        clapper.identify();
        upper.identify();
        hitman.identify();
        happy.identify();
        std::cout   << "\nHitting time!"
                    << std::endl;
        hitman.hit(clapper);
        hitman.hit(upper);
        happy.highFivesGuy();
        hitman.hit(happy);
        clapper.identify();
        upper.identify();
        hitman.identify();
        happy.identify();
        std::cout   <<"\nMutation time! Upper becomes as Happy"
                    << std::endl;
        upper = happy;
        upper.identify();
        happy.hit(hitman);
        clapper.hit(hitman);
        upper.identify();
        happy.identify();
        happy.highFivesGuy();
        for (int i = 0; i < 7; i++)
        {
            std::cout   << "\nHitting time! "
                        << 7 - i << " more times"
                        << std::endl;
            hitman.hit(happy);
            if (i % 2)
            {
                happy.hit(hitman);
                hitman.guardGate();
            }
            happy.highFivesGuy();
        }
        hitman.guardGate();
        clapper.identify();
        upper.identify();
        hitman.identify();
        happy.identify();
    }
    return (0);
}