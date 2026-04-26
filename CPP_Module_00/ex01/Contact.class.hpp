/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:16:11 by fcatala-          #+#    #+#             */
/*   Updated: 2024/10/16 17:31:53 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

class Contact
{
private:

	std::string _firstName;
	std::string _lastName;
	std::string _nick;
	std::string _phone;
	std::string _secret;

public:
//Default constructor and destructor in c+11
//	Contact() = default;
//	~Contact() = default;

	Contact();
	~Contact();

//Getter methods
	const std::string&	getFirstName() const;
	const std::string&	getLastName() const;
	const std::string&	getNick() const;
	const std::string&	getPhone() const;
	const std::string&	getSecret() const;

//Setter methods
	void 				setFirstName(const std::string firstName);
	void 				setLastName(const std::string lastName);
	void 				setNick(const std::string nick);
	void 				setPhone(const std::string phone);
	void 				setSecret(const std::string secret);

};

#endif
