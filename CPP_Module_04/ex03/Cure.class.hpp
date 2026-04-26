/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:38:50 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/04 12:28:36 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_CLASS_HPP
# define CURE_CLASS_HPP

# include "AMateria.class.hpp"
# include "ICharacter.class.hpp"

class Cure : public AMateria 
{
	public:
		// Orthodox Canonical Form
    	Cure(void); // Default constructor
    	Cure(const Cure& other); // Copy constructor
    	virtual ~Cure(); // Destructor
    	Cure& operator=(const Cure& other); // Copy assignment operator

    	 // Override pure virtual function
		virtual Cure* clone() const;
		// Override virtual function
    	virtual void use(ICharacter& target);
};

#endif