/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:12:07 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/30 13:17:14 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
	private:
		int 				v_value;
		static const int	v_fractBits = 8;
	
	public:
		Fixed(void);//Canonical default constructor
		Fixed(const Fixed& current);//Canonical copy constructor
		Fixed(const int num);//Parameterized Constructor
		Fixed(const float num);//Parameterized Constructor
		~Fixed(void);//Canonical destructor

		Fixed&	operator=(const Fixed& another);//Canonical assignment operator: used to assign one value to another
		int 	getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};
std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
#endif