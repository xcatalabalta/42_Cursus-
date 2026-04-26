/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:21:53 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/21 17:19:10 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

// Constructors and destructor
ClapTrap::ClapTrap(void) 
        : _name("default_Clap"), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
    std::cout << "\033[3mClapTrap default constructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    this->_attack_dmg = other._attack_dmg;
    this->_energy_pts = other._energy_pts;
    this->_hit_pts = other._hit_pts;
    this->_name = other._name;
    std::cout   << "\033[3mClapTrap copy constructor called with name "
                << this->_name << " \033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
    std::cout   << "\033[3mClapTrap named constructor called for the name "
                << name << "\033[0m" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout   << "\033[3;31mClapTrap default destructor called for "
                << this->_name <<"\033[0m" 
                << std::endl;
}

// Overloaded Operators
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "\033[3mClapTrap assignation called\033[0m" << std::endl;
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
void    ClapTrap::attack(const std::string& target)
{
        if (this->_energy_pts > 0 && this->_hit_pts > 0)
        {
            std::cout   << "ClapTrap " << this->_name
                        << " attacks " << target
                        << " causing " << this->_attack_dmg
                        << " points of damage!" << std::endl;
            --this->_energy_pts;
        }
        else if (this->_hit_pts == 0)
        {
            std::cout   << "ClapTrap " << this->_name
                        << " is dead."
                        << std::endl;
        }
        else
        {
            std::cout   << "ClapTrap " << this->_name
                        << " has not enough energy to attack."
                        << std::endl;
        }
    }

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hit_pts == 0)
    {
        std::cout   << "ClapTrap " << this->_name
                    << " cannot take further damage."
                        << std::endl;
    }
    else
    {
        if (amount >= this->_hit_pts)
        {
            this->_hit_pts = 0;
        }
        else
        {
            this->_hit_pts -= amount;
        }
        std::cout   << "ClapTrap " << this->_name
                    << " has taken " << amount
                    << " points of damage. Now it has "
                    << this->_hit_pts << " hit points left."
                    << std::endl;
        }
    }

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energy_pts > 0 && this->_hit_pts > 0)
    {
        this->_hit_pts += amount;
        std::cout   << "ClapTrap " << this->_name
                    << " has increased its hit points in "
                    << amount << " Now it has "
                    << this->_hit_pts << " points."
                    << std::endl;
        --this->_energy_pts;
    }
    else if (this->_hit_pts == 0)
    {
        std::cout   << "ClapTrap " << this->_name
                    << " cannot be repaired because is already dead."
                    << std::endl;
    }
    else
    {
        std::cout   << "ClapTrap " << this->_name
                    << " has not enough energy to get repaired."
                    << std::endl;
    }
}

//Not required, but useful
void    ClapTrap::identify(void) const
{
    std::cout   << this->_name
                << " Hit:\t" << this->_hit_pts
                << "\tEnergy:\t" << this->_energy_pts
                << "\tAttack:\t" << this->_attack_dmg
                << std::endl;
}