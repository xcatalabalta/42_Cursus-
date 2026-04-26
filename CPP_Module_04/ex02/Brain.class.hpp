/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:34:37 by fcatala-          #+#    #+#             */
/*   Updated: 2025/02/01 14:32:49 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include <string>
# include <iostream>
# include <cstdlib> 

class Brain
{
protected:
    std::string m_ideas[100];
public:
    Brain(void);
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    //getter and setter functions
    std::string getIdea(int i) const;
    void        setIdea(std::string idea, int i);
};
 
#endif