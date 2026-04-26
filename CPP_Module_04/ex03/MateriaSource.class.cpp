/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:57:02 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/06 18:30:36 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.class.hpp"


// Default constructor
MateriaSource::MateriaSource(void) 
{
    for (int i = 0; i < INV; i++) 
	{
        m_learned[i] = NULL;
    }
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource& other) 
{
    for (int i = 0; i < INV; i++)
	{
        if (other.m_learned[i])
		{
            m_learned[i] = other.m_learned[i]->clone(); // Deep copy
        }
		else
		{
            m_learned[i] = NULL;
        }
    }
}

// Destructor
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < INV; i++) 
	{
        if (m_learned[i]) 
		{
            std::cout   << "Deleting " << this->m_learned[i]->getType()
                    << std::endl;
            delete m_learned[i];
        }
    }
}

// Copy assignment operator
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
	{
        for (int i = 0; i < INV; i++)
		{
            if (m_learned[i])
			{
                delete m_learned[i]; // Clean up existing resources
            }
            if (other.m_learned[i]) 
			{
                m_learned[i] = other.m_learned[i]->clone(); // Deep copy
            } 
			else 
			{
                m_learned[i] = NULL;
            }
        }
    }
    return (*this);
}

// Learn a new materia
void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < INV; i++) 
	{
        if (!m_learned[i]) 
		{
            m_learned[i] = m;
            std::cout   << "\nLearned " << m->getType()
                        << " pos " << i
                        << std::endl;
            return;
        }
    }
    std::cout   << "\nNot enough learning capacity.\n"
                << std::endl;
                delete m;
}

// Create a materia of a specific type
AMateria* MateriaSource::createMateria(std::string const & type) 
{
    for (int i = 0; i < INV; i++)
	{
        if (m_learned[i] && m_learned[i]->getType() == type) 
		{
            std::cout   << "\nMateria " << type << " created."
                        << std::endl;
            return m_learned[i]->clone();
        }
    }
    std::cout   << "\nUnable to create materia " << type
                << "\nPlease learn it first.\n"
                << std::endl;
    return NULL;
}