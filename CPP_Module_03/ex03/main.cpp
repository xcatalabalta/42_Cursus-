/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:01:46 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/21 18:35:40 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"

int main (void)
{
    
    //ClapTrap    a("Clappy");
    std::cout << "Building 2 FragTraps " << std::endl;
    FragTrap    nobody;
    FragTrap    b("Fraggy");
    nobody.identify();
    b.identify();
    std::cout << "Equalizing FragTraps " << std::endl;
    nobody = b;
    nobody.identify();
    b.identify();
    std::cout << "Building 2 ScavTraps " << std::endl;
    ScavTrap    c("Scravy");
    ScavTrap    w("Warro");
    c.identify();
    w.identify();
    std::cout << "Equalizing FragTraps " << std::endl;
    w = c;
    c.identify();
    w.identify();
    std::cout << "Building a Diamond " << std::endl;
    DiamondTrap f;
    f.identify();
    f.whoAmI();
    std::cout << "Building another Diamond " << std::endl;
    DiamondTrap d("Diamy");
    d.identify();
    d.whoAmI();
    //DiamondTrap e(d);
    std::cout << "Equalizing Diamonds " << std::endl;
    f = d;
    f.identify();
    f.whoAmI();
    std::cout << "Copying Diamonds " << std::endl;
    DiamondTrap z(d);
    z.whoAmI();
    std::cout << "Destroying the original Diamond " << std::endl;
    d.~DiamondTrap();
    std::cout << "Listen to the orphan Diamond " << std::endl;
    z.identify();
    std::cout << "Energy Test" << std::endl;
    f.highFivesGuy();
    for (int i = 1; i < 10; i++)
    {
        f.attack("Somebody");
        c.attack("Other people");
    }
    f.identify();
    std::cout << "Salutation Test" << std::endl;
    f.highFivesGuy();
    c.guardGate();
    return (0);
}