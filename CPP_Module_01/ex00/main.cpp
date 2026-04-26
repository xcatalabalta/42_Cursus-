/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:30:29 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/23 17:27:57 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

int main (void)
{
    Zombie  bicho1 = Zombie("Manolo");
    bicho1.announce();
//    Zombie  *bicho2 = Zombie::newZombie("Pepita");
    Zombie*  bicho2 = newZombie("Pepita");
    bicho2->announce();
//    Zombie::randomChump("Jorgito");
    randomChump("Jorgito");    
    delete bicho2;
    return (0);
}