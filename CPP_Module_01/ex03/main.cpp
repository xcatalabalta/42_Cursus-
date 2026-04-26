/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:56:21 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/04 15:29:32 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.class.hpp"
#include "HumanB.class.hpp"


// The following code has been given in the subject
int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    
    {
       Weapon club = Weapon("crude spiked club");
       
       HumanB jim("Jim");
       jim.setWeapon(club);
       jim.attack();
       club.setType("some other type of club");
       jim.attack();
    }
    //This block is a variation of the above one
    //HumanB attacks before getting a weapon
    {
        Weapon bomba = Weapon ("Goma 2!!!");
        HumanB jazz("Xavier");
        jazz.attack();
        jazz.setWeapon(bomba);
        jazz.attack();
    }
    //   
    //This block is a variation of the given one
    //HumanB attacks before a weapon is created
    {
        HumanB jazz("Xavier");
        jazz.attack();
        Weapon bomb = Weapon ("AMONAL!!!");
        jazz.setWeapon(bomb);
        jazz.attack();
        bomb.setType("TNT");
    }
    //
    return 0;
}