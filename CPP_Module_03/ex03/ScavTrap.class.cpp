/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 07:43:15 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/21 18:31:40 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"

//Constructor and destructor
ScavTrap::ScavTrap(void) : ClapTrap()
{
    std::cout << "\033[3mScavTrap default constructor called\033[0m" << std::endl;
    _name = "default_Scav";
    _hit_pts = S_HIT;//100;
    _energy_pts = S_ENER;//50;
    _attack_dmg = S_ATT;//20;
    //m_guard = false;
    //this->identify();
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
    std::cout << "\033[3mScavTrap copy constructor called\033[0m" << std::endl;
    //*this = src;
    //this->identify();
    this->_name = src._name;
    this->_hit_pts = src._hit_pts;
    this->_energy_pts = src._energy_pts;
    this->_attack_dmg = src._attack_dmg;
    //this->m_guard = src.m_guard;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hit_pts = S_HIT;//100;
    _energy_pts = S_ENER;//50;
    _attack_dmg = S_ATT;//20;
    //m_guard = false;
    std::cout   << "\033[3mScavTrap named constructor called for the name "
                << name << "\033[0m" << std::endl;
    //this->identify();
}
/*
ScavTrap::ScavTrap(const unsigned int hit, const unsigned int ener, const unsigned int att) 
        : ClapTrap(hit, ener, att)
{
    _name = "default_Scav";
    m_guard = false;
    std::cout << "\033[3mScavTrap default param constructor called\033[0m" << std::endl;
}
*/
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
    /*
    if (this != &other)
    {
        this->m_name = other.m_name;
        this->m_hit_pts = other.m_hit_pts;
        this->m_energy_pts = other.m_energy_pts;
        this->m_attack_dmg = other.m_attack_dmg;
        this->m_guard = other.m_guard;
    }
    */
   ClapTrap::operator=(other);
    return (*this);
}

//Public functions
unsigned int ScavTrap::getEnergy(void) const
{
    return (_energy_pts);
}
void    ScavTrap::attack(const std::string& target)
{
    if (_energy_pts > 0 && this->_hit_pts > 0)
    {
        std::cout   << "ScavTrap " << this->_name
                    << " attacks " << target
                    << " causing " << this->_attack_dmg
                    << " points of damage!" << std::endl;
        //--this->_energy_pts;
        --ScavTrap::_energy_pts;
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
    if (this->_hit_pts > 0 && this->_energy_pts > 0)
    {
        //m_guard = m_guard ^ 1;
        std::cout   << "ScavTrap " << this->_name
                    << " is now in Gate keeper mode "
                    //<< this->m_guard
                    << std::endl;
    }
    else if (this->_energy_pts == 0)
    {
        std::cout   << "ScavTrap " << this->_name
                    << " cannot change the Gate keeper mode "
                    //<< " and remains in Gate keeper mode "
                    //<< this->m_guard
                    << std::endl;
    }
    else
    {
        std::cout   << "ScavTrap " << this->_name
                    << " is dead."
                    << std::endl;
    }    
}

//Extra functions (not required)
void    ScavTrap::identify(void) const
{
    ClapTrap::identify();
}