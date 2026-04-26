/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:13:07 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/02 08:08:04 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():m_value(0){}

Fixed::Fixed(const Fixed& current)
{
	*this = current;
}

Fixed::Fixed(const int num):m_value(num << Fixed::m_fractBits){}

//Precision lost when using
//this->m_value = static_cast<int>(roundf(static_cast<long long>(num * (1 << Fixed::m_fractBits))));
Fixed::Fixed(const float num)
{
	this->m_value = static_cast<int>(roundf(num * (1 << Fixed::m_fractBits)));
}

Fixed::~Fixed(){}

Fixed&	Fixed::operator=(const Fixed& another)
{
	if (this != &another)
	{
		this->setRawBits(another.getRawBits());
	}
	return (*this);
}

int		Fixed::getRawBits() const
{
	return (this->m_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->m_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->m_value) / static_cast<float>((1 << Fixed::m_fractBits)));
}

//Rounding negative numbers adjusted
int		Fixed::toInt(void) const
{
	if (this->m_value < 0)
	{
		return ((this->m_value + (1 << Fixed::m_fractBits) - 1) >> Fixed::m_fractBits);
	}
	return (this->m_value >> Fixed::m_fractBits);
}

bool	Fixed::operator>(const Fixed& another) const
{
	return (this->getRawBits() > another.getRawBits());
}

bool	Fixed::operator>=(const Fixed& another) const
{
	return (this->getRawBits() >= another.getRawBits());
}

bool	Fixed::operator<(const Fixed& another) const
{
	return (this->getRawBits() < another.getRawBits());
}

bool	Fixed::operator<=(const Fixed& another) const
{
	return (this->getRawBits() <= another.getRawBits());
}

bool	Fixed::operator==(const Fixed& another) const
{
	return (this->getRawBits() == another.getRawBits());
}
		
bool	Fixed::operator!=(const Fixed& another) const
{
	return (this->getRawBits() != another.getRawBits());
}

//Arithmetic operators. Two different approaches: direct toFloat and through setRawBits
Fixed 	Fixed::operator*(const Fixed& rhs) const
{
	
	Fixed	output;//(this->toFloat() * rhs.toFloat());

	output.setRawBits((this->getRawBits() * rhs.getRawBits()) >> Fixed::m_fractBits);
	return (output);	
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	if (rhs == 0)
		{
			std::cerr << "Error. Cannot divide by 0" << std::endl;
			exit (-1);
		}
	Fixed	output(this->toFloat() / rhs.toFloat());

	return (output);
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed	output;

	output.setRawBits((this->getRawBits() + rhs.getRawBits()));
	return (output);
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed	output(this->toFloat() - rhs.toFloat());
	return (output);
}

//Max and min functions
Fixed&	Fixed::max(Fixed& x, Fixed& y)
{
	if (x > y)
		return (x);
	return (y);
}

const Fixed&	Fixed::max(const Fixed& x, const Fixed& y)
{
	if (x > y)
		return (x);
	return (y);
}

Fixed&	Fixed::min(Fixed& x, Fixed& y)
{
	if (x < y)
		return (x);
	return (y);
}

const Fixed&	Fixed::min(const Fixed& x, const Fixed& y)
{
	if (x < y)
		return (x);
	return (y);
}

//Pre in/decrement
//*this = *this + 1; Increments integer
Fixed&	Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);;
	return (*this);
}

//Post in/decrement
Fixed	Fixed::operator++(int)
{
	Fixed	output(*this);

	this->setRawBits(this->getRawBits() + 1);
	return (output);
}

Fixed	Fixed::operator--(int)
{
	Fixed	output(*this);

	this->setRawBits(this->getRawBits() - 1);
	return (output);
}

std::ostream & operator<<( std::ostream & out, Fixed const & rhs)
{
	out << rhs.toFloat();
	return (out);
}
