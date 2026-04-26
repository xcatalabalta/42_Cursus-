/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:20:37 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/23 17:27:00 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

//void Zombie::randomChump( std::string name )
void randomChump( std::string name )
{
    Zombie bicho3 (name);

    bicho3.announce();
    return ;
}