/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:12:11 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/23 18:21:28 by fcatala-         ###   ########.fr       */
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
    Zombie();
    ~Zombie();
    
    void                announce() const;
    void                setName(std::string const name);
    std::string const*  getName() const;
};
Zombie*      zombieHorde( int N, std::string name );
#endif
/*
Previuosly public functions:
    static Zombie*      zombieHorde( int N, std::string name );
*/