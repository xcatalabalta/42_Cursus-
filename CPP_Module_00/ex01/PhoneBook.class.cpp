/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:03:18 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/14 16:42:58 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <sstream>
#include <cstdlib>

//Rejected code and notes
//It belongs to c++11
//			index = std::stoi(input);

// Phone numbers may be larger than integers
/*
static bool ft_IsInteger(const std::string& input)
{
    int number;

	if (input[0] == '+')
		return (0);
	std::stringstream ss(input);
	return (ss >> number) && (ss.eof());
}
*/
/*	if (!message.compare(IN_PHONE) && ft_IsInteger(input))
	{
		std::istringstream iss(input);
		iss >> num;
		if (num < 0)
		{
			std::cin.clear();
			input.clear();
			std::cout << L_BLANK << "\033[1;31mNot negative numbers\033[0m\033[A\033[2K\r";
		}
	}
*/

PhoneBook::PhoneBook()
{
	this->_index = 0;
	this->_size = 0;
}

PhoneBook::~PhoneBook(){}

static bool ft_IsNumber(const std::string& input)
{
    for (int i = 0; input[i]; i++)
	{
		if (input[i] < '0' || input[i] > '9')
			return (0);
	}
	return (1);
}

static std::string ft_InputNoEmpty(std::string message)
{
	std::string input;

	while (input.empty())
	{
		std::cout << L_BLANK << message << ":\t";
		std::getline(std::cin, input);
		if (!std::cin)
			exit(0);
		if (input.empty())
			std::cout << "\033[A\033[2K";
		if (!message.compare(IN_PHONE) && !ft_IsNumber(input))
		{
			std::cin.clear();
			input.clear();
			std::cout << L_BLANK <<"\033[1;31mEnter only numbers\033[0m \033[A\033[2K\r";
		}		
	}
	return (input);
}

static void ft_PutField(const std::string& field)
{
	if (field.length() > 10)
		std::cout << field.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << field;
	std::cout << "|";
}

void PhoneBook::ft_add()
{
	std::string	input;

	std::cout << "Enter the required information. (Ctrl+d to quit the program)" << std::endl;
	input = ft_InputNoEmpty(IN_NAME);
	this->_contacts[this->_index % NUM].setFirstName(input);
	input.clear();
	input = ft_InputNoEmpty(IN_SURN);
	this->_contacts[this->_index % NUM].setLastName(input);
	input.clear();
	input = ft_InputNoEmpty(IN_NICK);
	this->_contacts[this->_index % NUM].setNick(input);
	input.clear();
	input = ft_InputNoEmpty(IN_PHONE);
	this->_contacts[this->_index % NUM].setPhone(input);
	input.clear();
	input = ft_InputNoEmpty(IN_SECRET);
	this->_contacts[this->_index % NUM].setSecret(input);
	input.clear();
	this->_index++;
	if (this->_size < NUM)
		this->_size++;
	return;
}

void PhoneBook::ft_search() const
{
	int			index = 0;
	std::string input;

	std::cout <<"Actual contacts:           " << std::endl;
	std::cout <<"+----------+----------+----------+----------+"<< std::endl;
	std::cout <<"|     index|first name| last name|  nickname|"<< std::endl;
	std::cout <<"+----------+----------+----------+----------+"<< std::endl;
	for (int i = 0; i < this->_size; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i + 1;
		std::cout << "|";
		ft_PutField(this->_contacts[i].getFirstName());
		ft_PutField(this->_contacts[i].getLastName());
		ft_PutField(this->_contacts[i].getNick());
		std::cout << std::endl;
		std::cout <<"+----------+----------+----------+----------+"<< std::endl;
	}
	std::cout << std::endl;
	if (this->_size == 0)
	{
		std::cout << "Empty table, nothing to select." << std::endl;
		std::cout << "Back to main menu" << std::endl;
		return;
	}
	while (1)
	{
		std::cout << "Enter an index from 1 to " << this->_size;
		std::cout << ", 0 to get back to main menu"
					<< " or Ctrl+d to quit the program: ";
		std::getline(std::cin, input);
		if (!std::cin)
		{
			exit(1);
		}
		if (input.empty())
		{
			std::cout << "\033[A\033[2K";
			continue ;
		}
		if (ft_IsNumber(input))
		{
			std::istringstream iss(input);
			iss >> index;
		}
		if (!ft_IsNumber(input) || std::cin.fail() || (index < 0) || index > this->_size)
		{
			std::cin.clear();
			std::cout << "\033[1;31mInvalid index\033[0m";
			std::cout << "\r\033[A\033[2K";
			continue ;
		}
		else if (index == 0)
		{
			std::cin.clear();
			std::cout << "Back to main menu." << std::endl;
			return;
		}
		else
			break ;
	}
	std::cout << "Displaying required information of contact num " << index << std::endl;
	std::cout << IN_NAME << ":\t" << this->_contacts[index - 1].getFirstName() << std::endl;
	std::cout << IN_SURN << ":\t" << this->_contacts[index - 1].getLastName() << std::endl;
	std::cout << IN_NICK << ":\t" << this->_contacts[index - 1].getNick() << std::endl;
	std::cout << IN_PHONE << ":\t" << this->_contacts[index - 1].getPhone() << std::endl;
	std::cout << IN_SECRET << ":\t" << this->_contacts[index - 1].getSecret() << std::endl;
	std::cin.clear();
	std::cout << "Back to main menu." << std::endl;
	return;
}
