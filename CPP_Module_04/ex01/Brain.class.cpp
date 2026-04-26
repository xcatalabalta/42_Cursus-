/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:43:42 by fcatala-          #+#    #+#             */
/*   Updated: 2025/02/01 18:07:38 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"

Brain::Brain(void)
{
    std::cout << "\033[3mBrain default constructor called\033[0m" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "\033[3mBrain copy constructor called\033[0m" << std::endl;
    
    for (int i = 0; i < 100; i++)
    {
        this->m_ideas[i] = other.m_ideas[i];
    }
    
    //*this = other;//It calls the Brain assignation constructor
}

Brain   &Brain::operator=(const Brain& other)
{
    std::cout << "\033[3mBrain assignation constructor called\033[0m" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            //this->m_ideas[i]=(other.m_ideas[i]);
            this->m_ideas[i].assign(other.m_ideas[i]);//Assigns a new content to the string, replacing its current contents.
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "\033[3mBrain default destructor called\033[0m" << std::endl;
}

std::string Brain::getIdea(int i) const
{
    if (i > 99 || i < 0)
    {
        std::cout << "\033[3;31mError! Ideas'index must be between 0 and 99\n\033[0m";
        return("");
    }
    if (&m_ideas[i] != NULL)
    {
        return(m_ideas[i]);
    }
    return("");
}

 void    Brain::setIdea(std::string idea, int i)
 {
    if (i > 99 || i < 0)
    {
        std::cout << "\033[3;31mError! Ideas'index must be between 0 and 99\n\033[0m";
        return;
    }
    m_ideas[i] = idea;
 } 