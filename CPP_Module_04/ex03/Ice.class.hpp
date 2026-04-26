/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:15:54 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/04 12:28:36 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_CLASS_HPP
# define ICE_CLASS_HPP

# include "AMateria.class.hpp"
# include "ICharacter.class.hpp"

class Ice : public AMateria 
{
	public:
		// Orthodox Canonical Form
    	Ice(void); // Default constructor
    	Ice(const Ice& other); // Copy constructor
    	virtual ~Ice(); // Destructor
    	Ice& operator=(const Ice& other); // Copy assignment operator

    	// Override pure virtual function
		virtual Ice* clone() const;
		// Override virtual function
    	virtual void use(ICharacter& target);
};

# endif