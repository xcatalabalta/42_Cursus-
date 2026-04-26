/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:12:11 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/23 17:38:12 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
#define ZOMBIE_CLASS_HPP

#include <iostream>

class Zombie
{
private:
    std::string _name;
    
public:
    Zombie(std::string name);
    ~Zombie();
    
    void announce( void ) const;
};
Zombie* newZombie(std::string name);
void randomChump(std::string name);
#endif
/* 
Previously done but do not fit with subject:
    static Zombie *newZombie(std::string name);
    static void randomChump(std::string name);
Both were treated as public functions belonging to the class
but the subject prototyped them differently
*/