/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:18:53 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/05 17:52:31 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_CLASS_HPP
# define WHATEVER_CLASS_HPP

#include <iostream>

template <typename T>
void  swap (T &a, T &b)
{
	T aux = a;
	a = b;
	b = aux;
}

template <typename T>
const T &max (const T &a, const T &b)
{
	return ((a > b) ? a : b);
}

template <typename T>
const T &min (const T &a, const T &b)
{
	return ((a < b) ? a : b);
}

#endif

/*
// alternative, but requires specify the types
template <typename T>

struct Functions
{
	static void  swap (T &a, T &b)
	{
		T aux = a;
		a = b;
		b = aux;
	}

	static const T &max (const T &a, const T &b)
	{
		return ((a > b) ? a : b);
	}

	static const T &min (const T &a, const T &b)
	{
		return ((a > b) ? b : a);
	}
};
*/