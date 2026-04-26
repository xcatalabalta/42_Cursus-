/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 09:00:19 by fcatala-          #+#    #+#             */
/*   Updated: 2025/05/01 10:22:16 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_CLASS_HPP
# define SERIALIZER_CLASS_HPP
# include <stdint.h> 
# include <iostream>
# include <string>

typedef struct s_Data 
{
	std::string name;
	char 		grade;
	double 		mark;
	int 		age;

}	Data;

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &);
		Serializer &operator=(const Serializer &);

	public:
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif