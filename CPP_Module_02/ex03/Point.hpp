/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:04:45 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/02 07:10:34 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
private:
    const Fixed     m_x;
    const Fixed     m_y;
public:
    //Constructors
    Point(void);
    Point (const Point &current);
    Point (const float m_x, const float m_y);
    Point (const Fixed &x, const Fixed &y);
    //Destructor
    ~Point();

    //Overloaded Operator
    Point& operator=(const Point &another);

    //Comparison operators
    bool	operator==(const Point& rhs) const;
    bool    operator!=(const Point& rhs) const;

    //Getters
    const Fixed&    getX(void) const;
    const Fixed&    getY(void) const;

    //Setter
    //Point class cannot have setters because its private are const
};
// Overload for ostream
std::ostream & operator<<(std::ostream & o, Point const & rhs);
#endif