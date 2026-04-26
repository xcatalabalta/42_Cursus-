/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:00:58 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/09 13:18:08 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CLASS_HPP
# define ARRAY_CLASS_HPP

# include <iostream>
# include <exception>

template <typename T>

class 	Array
{
	private:
		T 				*m_arr;
		unsigned int 	m_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &other);
		Array	&operator=(Array const &other);
		~Array();
		T&	operator[](const int index);
		const T& operator[](const int index) const;
		unsigned int	size(void) const;
};

#include "../templ/Array.class.tpp"

#endif