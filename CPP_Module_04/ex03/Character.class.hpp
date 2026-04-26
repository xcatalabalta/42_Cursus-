/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:21:52 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/11 17:05:23 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP

#include "ICharacter.class.hpp"
#include "AMateria.class.hpp"

class Character : public ICharacter
{
	private:
		std::string 	m_name;
		AMateria*		m_inventory[INV];
	
	public:
		// Orthodox Canonical Form
    	Character(void); // Default constructor
    	Character(std::string const & name); // Parameterized constructor
    	Character(const Character& other); // Copy constructor
    	virtual ~Character(); // Destructor
    	Character& operator=(const Character& other); // Copy assignment operator

		// getter
		const std::string & getName(void) const;

		// required functions to implement
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		// extra functions
		void display(void) const;
		AMateria *getMateria(int idx) const;
		int getInvSize(void) const;
};
#endif
