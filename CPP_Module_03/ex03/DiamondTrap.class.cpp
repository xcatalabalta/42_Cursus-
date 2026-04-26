/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:05:48 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/21 18:13:41 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"

DiamondTrap::DiamondTrap(void) 
            : ClapTrap(), ScavTrap(), FragTrap()
{
    ClapTrap::_name = "def_Diam_clap_name";
    _name = "def_Diam";
    _hit_pts = FragTrap::_hit_pts;  // Use FragTrap's hit points
    _attack_dmg = FragTrap::_attack_dmg;
    ScavTrap::_energy_pts = S_ENER;
    _energy_pts = ScavTrap::_energy_pts;
    std::cout << "\033[3mDiamondTrap default constructor called\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
            : ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav_name"), FragTrap(name + "_frag_name"), _name(name)
{
    _hit_pts = FragTrap::_hit_pts;
    _attack_dmg = FragTrap::_attack_dmg;
    ScavTrap::_energy_pts = S_ENER;
    _energy_pts = ScavTrap::_energy_pts;
    std::cout   << "\033[3mDiamondTrap named constructor called for the name "
                << name << "\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
            : ClapTrap(src), ScavTrap(src), FragTrap(src)//, _name(src._name)
{
    std::cout << "\033[3mDiamondTrap copy constructor called\033[0m" << std::endl;
    *this = src;
}

DiamondTrap::~DiamondTrap()
{
    std::cout   << "\033[3;31mDiamondTrap default destructor called for "
                << this->_name <<"\033[0m" 
                << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        /*
        this->m_name = other.m_name;
        this->m_hit_pts = other.m_hit_pts;
        this->m_energy_pts = other.m_energy_pts;
        this->m_attack_dmg = other.m_attack_dmg;
        */
       ClapTrap::operator=(other);
       _name = other._name;
    }
    return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(void) const
{
    std::cout   << "I am Diamond called " << this->_name
                << " son of ClapTrap " <<  ClapTrap::_name//this->ClapTrap::getName()//ClapTrap::m_name
                << " king of Diamlandia." << ScavTrap::_energy_pts
                << std::endl;
}

void    DiamondTrap::identify(void) const
{
    std::cout   << "I am Diamond called " << this->_name
                << " Hit:\t" << this->_hit_pts
                << "\tEnergy:\t" << this->_energy_pts
                << "\tAttack:\t" << this->_attack_dmg
                << std::endl;
}