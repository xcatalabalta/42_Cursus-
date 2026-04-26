/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:27:50 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/13 17:56:08 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include <iostream>
#include <iomanip>

# define IN_NAME "First name"
# define IN_SURN "Last name"
# define IN_NICK "Nick name"
# define IN_PHONE "Phone number"
# define IN_SECRET "Darkest secret"
# define L_BLANK "                                                        \r"
# define NUM 8

class PhoneBook
{
private:
	int _index;
	int _size;
	Contact _contacts[NUM];

public:
	PhoneBook();
	~PhoneBook();
	void ft_add();
	void ft_search() const;
};
#endif
