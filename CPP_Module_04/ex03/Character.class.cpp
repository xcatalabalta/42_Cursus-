/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:02:15 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/15 08:11:52 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.class.hpp"

Character::Character(void) : m_name("undefined") 
{
	for (int i = 0; i < INV; i++)
	{
		m_inventory[i] = NULL;
	}
	std::cout 	<< "Character default constructor called"
				<< std::endl;
}

// Parameterized constructor
Character::Character(std::string const & name) : m_name(name)
{
	for (int i = 0; i < INV; i++)
	{
		m_inventory[i] = NULL;
	}
	std::cout 	<< "Parameterized default constructor called "
				<< "named " << m_name
				<< std::endl;
}

// Copy constructor
Character::Character(const Character& other) : m_name(other.m_name)
{
	///*
		for (int i = 0; i < INV; i++) 
	{
        if (other.m_inventory[i]) 
		{
            m_inventory[i] = other.m_inventory[i]->clone();
        } 
		else 
		{
            m_inventory[i] = NULL;
        }
    }
	//*/
	// The code below provides an error
	//Conditional jump or move depends on uninitialised value(s)
	/*
	for (int i = 0; i < INV; i++) 
	{
        if (m_inventory[i]) 
		{
            delete m_inventory[i];
        }
        if (other.m_inventory[i]) 
		{
            m_inventory[i] = other.m_inventory[i]->clone();
        } 
		else 
		{
            m_inventory[i] = NULL;
        }
    }
	*/
	std::cout 	<< "\033[3;32mCharacter copy constructor called\033[0m" 
				<< std::endl;
}

Character::~Character()
{
	for (int i = 0; i < INV; i++)
	{
		if (this->m_inventory[i] != NULL)
			delete this->m_inventory[i];
	}
	std::cout   << "\033[3;31mDefault destructor of character " << this->getName()
                << "\033[0m" 
				<< std::endl;
}

Character& Character::operator=(const Character& other)
{
	std::cout	<< "Equalizing " << m_name << " to " << other.m_name
				<< std::endl;
	if (this != &other)
	{
        m_name = other.m_name;
        for (int i = 0; i < 4; i++) 
		{
            if (m_inventory[i]) 
			{
                delete m_inventory[i];
            }
            if (other.m_inventory[i]) 
			{
                m_inventory[i] = other.m_inventory[i]->clone();
            } 
			else 
			{
                m_inventory[i] = NULL;
            }
        }
    }
	std::cout 	<< "Pure assignment 'a = b' operator called for "  
				<< this->m_name
				<< std::endl;
    return (*this);
}

// getter
const std::string & Character::getName(void) const
{
	return (m_name);
}

// required functions to implement
void	Character::equip(AMateria* m)
{
	if (!m)
	{
		return;
	}
	const std::string	&stringREF = m->getType();
	for (int i = 0; i < INV; i++) 
	{
        if (m_inventory[i]) 
		{
			//const std::string	&stringREFB = m_inventory[i]->getType();
			//if (&stringREF == &stringREFB)
			if (m == m_inventory[i])
			{
            	std::cout 	<< "Materia rejected: already equiped in pos " 
							<< i << std::endl;
				return;
			}
        }
    }
	for (int i = 0; i < INV; i++) 
	{
        if (!m_inventory[i]) 
		{
            m_inventory[i] = m;
			std::cout 	<< m_name <<" has equiped a new materia " << m->getType()
						<< " at pos "<< i << "\taddress\t" << &stringREF 
			<< std::endl;
            return;
        }
    }
	std::cout 	<< "Inventory full. "
				<< "Please unequip a materia before trying to equip a new one"
				<< std::endl;
	//delete m;
}

void 	Character::unequip(int idx)
{
	if (idx >= 0 && idx < INV)
	{
		m_inventory[idx] = NULL;
	}
	else
	{
		std::cout	<< "\nError: out of range,"
					<< " inventory ranges from 0 to "
					<< INV - 1
					<< std::endl;
	}
}

void 	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < INV && m_inventory[idx])
	{
		std::cout << m_name << " ";
		m_inventory[idx]->use(target);
	}
}

// extra functions
void Character::display(void) const
{
	int 	i = 0;
	int 	j = 0;

	std::cout 	<< "\nShowing "<< this->m_name <<"'s inventory:"
				<< std::endl;
	for (; i < INV; i++)
	{
		if (m_inventory[i])
		{
			//This can be possible because m_type is a string
			const std::string	&stringREF = this->m_inventory[i]->getType();
			std::cout 	<< "Materia\t" << i
						<< " is\t" << m_inventory[i]->getType()
						<< "\tlocated at \t" << &stringREF
						<< std::endl;
			j++;
		}
		//else
		//	break;
	}
	std::cout   << "End of "<< this->m_name <<"'s inventory:\t"
				<< j << " materials listed"
				<< std::endl;
}

AMateria *Character::getMateria(int idx) const
{
	if (idx >= 0 && idx < INV && m_inventory[idx])
	{
		return (m_inventory[idx]);
	}
	return (NULL);
}

int 	Character::getInvSize(void) const
{
	int	j = 0;

	for (int i = 0; i < INV; i++)
	{
		if (m_inventory[i])
		{
			j++;
		}
	}
	return (j);
}
