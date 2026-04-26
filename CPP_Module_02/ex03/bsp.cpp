/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:58:26 by fcatala-          #+#    #+#             */
/*   Updated: 2025/01/13 15:22:18 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float ft_area(Point a, Point b, Point c)
{
    float   area;
 
    area = (a.getX().toFloat()*(b.getY().toFloat() - c.getY().toFloat())
            + b.getX().toFloat()*(c.getY().toFloat() - a.getY().toFloat())
            + c.getX().toFloat()* (a.getY().toFloat() - b.getY().toFloat()))/2.0;
    if (area < 0)
    {
        area = -area;
    }
    return(area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    if (!ft_area(a, b, c) || ft_area(a, b, point) == 0 || ft_area(a, c, point) == 0 || ft_area(b, c, point) == 0)
    {
        return(false);
    }
    if (ft_area(a, b, c) - ft_area(a, b, point) - ft_area(a, c, point) - ft_area(b, c, point) == 0)
    {
        return (true);
    }
    return (false);
}
