/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 09:06:31 by fcatala-          #+#    #+#             */
/*   Updated: 2025/05/01 09:42:14 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Serializer.class.hpp"

Serializer::Serializer(void)
{}

Serializer::Serializer(const Serializer &other)
{
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer()
{}

uintptr_t Serializer::serialize(Data *ptr) 
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data * Serializer::deserialize(uintptr_t raw) 
{
	return reinterpret_cast<Data *>(raw);
}