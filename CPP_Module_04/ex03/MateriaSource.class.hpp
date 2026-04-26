/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:45:40 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/04 13:03:17 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_CLASS_HPP
# define MATERIASOURCE_CLASS_HPP

# include "IMateriaSource.class.hpp"

class MateriaSource : public IMateriaSource 
{
	private:
		AMateria* m_learned[INV];

	public:
		// Orthodox Canonical Form
    	MateriaSource(void); // Default constructor
    	MateriaSource(const MateriaSource& other); // Copy constructor
    	virtual ~MateriaSource(); // Destructor
    	MateriaSource& operator=(const MateriaSource& other); // Copy assignment operator

		// required functions to implement
    	void 		learnMateria(AMateria* m);
    	AMateria* 	createMateria(std::string const & type);
};
#endif