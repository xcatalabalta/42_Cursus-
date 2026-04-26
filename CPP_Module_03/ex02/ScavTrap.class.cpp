/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 07:43:15 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/21 17:50:28 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"

//Constructor and destructor
ScavTrap::ScavTrap(void): ClapTrap()
{
    std::cout << "\033[3mScavTrap default constructor called\033[0m" << std::endl;
    this->_name = "default_Scav";
    this->_hit_pts = 100;
    this->_energy_pts = 50;
    this->_attack_dmg = 20;
    //this->m_guard = false;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src)
{
    //*this = src;
    std::cout << "\033[3mScavTrap copy constructor called\033[0m" << std::endl;
    this->_name = src._name;
    this->_hit_pts = src._hit_pts;
    this->_energy_pts = src._energy_pts;
    this->_attack_dmg = src._attack_dmg;
    //this->m_guard = src.m_guard;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
    this->_hit_pts = 100;
    this->_energy_pts = 50;
    this->_attack_dmg = 20;
    //this->m_guard = false;
    std::cout   << "\033[3mScavTrap named constructor called for the name "
                << this->_name << "\033[0m" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout   << "\033[3;31mScavTrap default destructor called for "
                << this->_name <<"\033[0m" 
                << std::endl;
}

// Overloaded Operators
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "\033[3mScavTrap assignation called\033[0m" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hit_pts = other._hit_pts;
        this->_energy_pts = other._energy_pts;
        this->_attack_dmg = other._attack_dmg;
        //this->m_guard = other.m_guard;
    }
    return (*this);
}

//Public functions
void    ScavTrap::attack(const std::string& target)
{
    if (this->_energy_pts > 0 && this->_hit_pts > 0)
    {
        std::cout   << "ScavTrap " << this->_name
                    << " attacks " << target
                    << " causing " << this->_attack_dmg
                    << " points of damage!" << std::endl;
        --this->_energy_pts;
    }
    else if (this->_hit_pts == 0)
    {
        std::cout   << "ScavTrap " << this->_name
                    << " is dead."
                    << std::endl;
    }
    else
    {
        std::cout   << "ScavTrap " << this->_name
                    << " has not enough energy to attack."
                    << std::endl;
    }
}

void    ScavTrap::guardGate(void)
{
    std::cout   << "ScavTrap " << this->_name
                << " is now in Gate keeper mode."
                << std::endl;
    //this->m_guard = true;
}

void    ScavTrap::identify(void) const
{
    ClapTrap::identify();
    //std::cout   << "\033[A\033[4;36m\t\t\t\t\t\t\tGuard mode: "
   //             << this->m_guard << "\033[0m"
    //            << std::endl;
}