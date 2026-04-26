/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.class.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:50:15 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/09 13:05:52 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Array.class.hpp"

template <typename T>
Array<T>::Array(): m_size(0)
{
	this->m_arr = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n): m_size(n)
{
	this->m_arr = new T[n];
}

template <typename T>
Array<T>::Array(Array const  &other): m_size(other.m_size)
{
	this->m_arr = new T[other.m_size];
	*this = other;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &other)
{
	if (this != &other)
	{
		if (this->m_size > 0)
		{
			delete [] this->m_arr;
		}
		this->m_size = other.m_size;
		this->m_arr = new T[other.m_size];
		for (unsigned int i = 0; i < this->m_size; i++)
		{
			this->m_arr[i] = other.m_arr[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (this->m_size > 0)
	{
		delete [] this->m_arr;
	}
}

template <typename T>
T &Array<T>::operator[](const int index)
{
	
	if (index < 0)
	{
		throw std::out_of_range("Index cannot be negative");
	}
	else if (static_cast<unsigned>(index) >= this->m_size)
	{
		throw std::out_of_range("Index out of range");
	}
	return (this->m_arr[index]);
}

template <typename T>
const T &Array<T>::operator[](const int index) const
{
	
	if (index < 0)
	{
		throw std::out_of_range("Index cannot be negative");
	}
	else if (static_cast<unsigned>(index) >= this->m_size)
	{
		throw std::out_of_range("Index out of range");
	}
	return (this->m_arr[index]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->m_size);
}

