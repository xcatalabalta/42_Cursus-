/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:51:07 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/04 10:56:56 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_CLASS_HPP
# define AMATERIA_CLASS_HPP

# include <iostream>
# include <string>
//# include "ICharacter.hpp" // cyclic inclusion

# define INV 4

class ICharacter; // Forward declaration to avoid circular dependencies

class AMateria 
{
	protected:
    	std::string m_type;

	public:
		// Orthodox Canonical Form
    	AMateria(void); // Default constructor
    	AMateria(std::string const & type); // Parameterized constructor
    	AMateria(const AMateria& other); // Copy constructor
    	virtual ~AMateria(); // Destructor
    	AMateria& operator=(const AMateria& other); // Copy assignment operator

    	/// getter
		const std::string  & getType(void) const;
		// Pure virtual function no implementation in this class
    	virtual AMateria* clone(void) const = 0;
		// Virtual function
    	virtual void use(ICharacter& target); 
};

#endif