/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:12:07 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/02 08:07:24 by fcatala-         ###   ########.fr       */
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
		int 				m_value;
		static const int	m_fractBits = 8;
	
	public:
		Fixed(void);//Canonical default constructor
		Fixed(const Fixed& current);//Canonical copy constructor
		Fixed(const int num);//Parameterized Constructor
		Fixed(const float num);//Parameterized Constructor
		~Fixed(void);//Canonical destructor

		Fixed&	operator=(const Fixed& another);//Canonical assignment operator: used to assign one value to another
		//Comparison operators
		bool	operator>(const Fixed& another) const;
		bool	operator>=(const Fixed& another) const;
		bool	operator<(const Fixed& another) const;
		bool	operator<=(const Fixed& another) const;
		bool	operator==(const Fixed& another) const;
		bool	operator!=(const Fixed& another) const;

		//Arithmetic operators
		Fixed 	operator*(const Fixed& rhs) const;
		Fixed 	operator/(const Fixed& rhs) const;
		Fixed	operator+(const Fixed& rhs) const;
		Fixed	operator-(const Fixed& rhs) const;


		//Getters setters and displayers
		int 	getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		//Max and min functions
		static Fixed& max(Fixed& x, Fixed& y);
		static const Fixed& max(const Fixed& x, const Fixed& y);
		static Fixed& min(Fixed& x, Fixed& y);
		static const Fixed& min(const Fixed& x, const Fixed& y);

		//Pre in/decrement
		Fixed&	operator++(void);
		Fixed&	operator--(void);

		//Post in/decrement
		Fixed	operator++(int);
		Fixed	operator--(int);
};
std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
#endif
