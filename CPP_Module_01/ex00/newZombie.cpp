/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:04:45 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/23 17:14:28 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

/*
//Function defined as a class member
Zombie *Zombie::newZombie(std::string name)
{
    Zombie *bicho = new Zombie (name);
    return (bicho);
}
*/
Zombie* newZombie(std::string name)
{
    return new Zombie(name);
}