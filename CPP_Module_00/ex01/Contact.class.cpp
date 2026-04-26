/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:35:41 by fcatala-          #+#    #+#             */
/*   Updated: 2024/10/16 18:08:03 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(){}
Contact::~Contact(){}

//Getter methods
const std::string&	Contact::getFirstName() const
{
	return (this->_firstName);
}

const std::string&	Contact::getLastName() const
{
	return (this->_lastName);
}

const std::string&	Contact::getNick() const
{
	return (this->_nick);
}

const std::string&	Contact::getPhone() const
{
	return (this->_phone);
}

const std::string&	Contact::getSecret() const
{
	return (this->_secret);
}

//Setter methods
void	Contact::setFirstName(const std::string firstName)
{
	this->_firstName = firstName;
	return;
}

void	Contact::setLastName(const std::string lastName)
{
	this->_lastName = lastName;
	return;
}

void	Contact::setNick(const std::string nick)
{
	this->_nick = nick;
	return;
}

void	Contact::setPhone(const std::string phone)
{
	this->_phone = phone;
	return;
}

void	Contact::setSecret(const std::string secret)
{
	this->_secret = secret;
	return;
}
