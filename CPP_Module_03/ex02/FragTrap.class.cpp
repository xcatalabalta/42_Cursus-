/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 07:43:15 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/21 17:50:28 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.class.hpp"

//Constructor and destructor
FragTrap::FragTrap(void): ClapTrap()
{
    std::cout << "\033[3mFragTrap default constructor called\033[0m" << std::endl;
    this->_name = "def_Frag";
    this->_hit_pts = 100;
    this->_energy_pts = 100;
    this->_attack_dmg = 30;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
    std::cout << "\033[3mFragTrap copy constructor called\033[0m" << std::endl;
    this->_name = src._name;
    this->_hit_pts = src._hit_pts;
    this->_energy_pts = src._energy_pts;
    this->_attack_dmg = src._attack_dmg;
    //*this = src;
}

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
    this->_hit_pts = 100;
    this->_energy_pts = 100;
    this->_attack_dmg = 30;
    this->_name = name;
    std::cout   << "\033[3mFragTrap named constructor called for the name "
                << _name << "\033[0m" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout   << "\033[3;31mFragTrap default destructor called for "
                << this->_name <<"\033[0m" 
                << std::endl;
}

// Overloaded Operators
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "\033[3mFragTrap assignation called\033[0m" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hit_pts = other._hit_pts;
        this->_energy_pts = other._energy_pts;
        this->_attack_dmg = other._attack_dmg;
    }
    return (*this);
}

//Public functions
void    FragTrap::highFivesGuy(void) const
{
    std::string msg;

    if  (this->_hit_pts > 0 && this->_energy_pts > 0)
    {
        msg = "BIG";
    }
    else if (this->_energy_pts == 0)
    {
        msg = "TIRED";
    }
    else
    {
        msg = "ZOMBI";
    }
    std::cout   << "FragTrap " << this->_name
                << " gives you a " << msg <<" HIGH FIVES !!!!!."
                << std::endl;
}