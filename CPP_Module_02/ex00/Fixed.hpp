/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:12:07 by fcatala-          #+#    #+#             */
/*   Updated: 2024/12/18 12:54:43 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed 
{
	private:
		int 				_value;
		static const int	_fractBits = 8;
	
	public:
		Fixed(void);
		Fixed(const Fixed& current);
		~Fixed(void);

		Fixed&	operator=(const Fixed& current);
		int 	getRawBits(void) const;
		void	setRawBits(const int raw);
};
