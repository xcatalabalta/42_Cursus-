/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:13:07 by fcatala-          #+#    #+#             */
/*   Updated: 2024/12/18 13:12:26 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():v_value(0)
{
	std::cout << "\033[3mDefault constructor called\033[0m" << std::endl;
}

Fixed::Fixed(const Fixed& current)
{
	std::cout << "\033[3mCopy constructor called\033[0m" << std::endl;
	*this = current;
}

Fixed::Fixed(const int num):v_value(num << Fixed::v_fractBits)
{
	std::cout << "\033[3mInt constructor called\033[0m" << std::endl;
}

Fixed::Fixed(const float num)
{
	std::cout << "\033[3mFloat constructor called\033[0m" << std::endl;
	this->v_value = static_cast<int>(roundf(num * (1 << Fixed::v_fractBits)));
}

Fixed::~Fixed()
{
	std::cout << "\033[3mDestructor called\033[0m" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& another)
{
	if (this != &another)
	{
		std::cout << "\033[3mAssignation operator called\033[0m" << std::endl;
		this->setRawBits(another.getRawBits());
	}
	return (*this);
}

int		Fixed::getRawBits() const
{
	return (this->v_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->v_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->v_value) / static_cast<float>((1 << Fixed::v_fractBits)));
}

int		Fixed::toInt(void) const
{
	if (this->v_value < 0)
	{
		return ((this->v_value + (1 << Fixed::v_fractBits) - 1) >> Fixed::v_fractBits);
	}
	return (this->v_value >> Fixed::v_fractBits);
}

std::ostream & operator<<( std::ostream & out, Fixed const & rhs)
{
	out << rhs.toFloat();
	return (out);
}
