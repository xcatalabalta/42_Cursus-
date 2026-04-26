/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 07:06:07 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/09 09:06:30 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_CLASS_HPP
# define ITER_CLASS_HPP

# include <iostream>

class MaxTracker;//this class has a specialized template

// Generic functions
template <typename T>
void iter(T *array, size_t size, void (*func)(T &))
{
	for (size_t i = 0; i < size; i++)
	{
		func(array[i]);
	}
}

// Functors
template<typename T_array, typename T_function>
void iter(T_array *array, size_t size, T_function func)
{
	for (size_t i = 0; i < size; i++)
	{
		func(array[i]);
	}
}

//Specialized template
template<typename T_array>
void iter(T_array *array, size_t size, MaxTracker& tracker)
{
	for (size_t i = 0; i < size; i++)
	{
		tracker(array[i]);
	}
}

#endif