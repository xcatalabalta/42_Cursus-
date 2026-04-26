/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:42:37 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/04 12:55:32 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_CLASS_HPP
# define IMATERIASOURCE_CLASS_HPP

#include "AMateria.class.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void 	learnMateria(AMateria*) = 0;
		virtual 		AMateria* createMateria(std::string const & type) = 0;
};
#endif
