/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:23:24 by fcatala-          #+#    #+#             */
/*   Updated: 2024/12/18 17:06:02 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): m_x(0), m_y(0){} //m_x(Fixed 0), m_y(Fixed 0)

Point::Point(const Point &current): m_x(current.m_x), m_y(current.m_y)
{}
Point::Point (const float m_x, const float m_y): m_x(Fixed (m_x)), m_y(Fixed (m_y))
{}
Point::Point (const Fixed &x, const Fixed &y): m_x(x), m_y(y)
{}
Point::~Point(){}

Point& Point::operator=(const Point &another)
{
    if (this != &another)
    {
        this->~Point();
        new (this) Point(another);
    }
    return (*this);
}
bool	Point::operator==(const Point& rhs) const
{
    if (this->getX() == rhs.getX() && this->getY() == rhs.getY())
    {
        return (true);
    }
    return (false);
}

bool	Point::operator!=(const Point& rhs) const
{
    if (*this == rhs)
    {
        return (false);
    }
    return (true);
}

const Fixed&    Point::getX(void) const
{
    return (this->m_x);
}

const Fixed&    Point::getY(void) const
{
    return (this->m_y);
}

// Overload for ostream
std::ostream & operator<<(std::ostream & o, Point const & point)
{
    o << "(" << point.getX() << "," << point.getY() << ")";
    return (o);
}
