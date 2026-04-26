/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:13:20 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/11 19:16:28 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

// Initialize static members
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Helper function to display the current timestamp in the format [YYYYMMDD_HHMMSS]
// std::tm Structure containing a calendar date and time broken down into its components.
// std::time_t Returns the current calendar time as a std::time_t object. 
// This represents the time as the number of seconds since the Unix epoch
void	Account::_displayTimestamp(void)
{
	std::time_t	now;
	std::tm		*ltm;
	char		buffer[20];

	std::time(&now);
	ltm = std::localtime(&now);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", ltm);
	std::cout << buffer;
}

// Constructor
Account::Account(int initial_deposit) 
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	_nbAccounts++;
	_totalAmount += initial_deposit;
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

// Destructor
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";closed" << std::endl;
}

// Getters
int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

// Display global account information
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();

	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

// Deposit money into the account
void Account::makeDeposit(int deposit)
{
    int previousAmount;

    _displayTimestamp();
    _nbDeposits++;
    _totalNbDeposits++;
    previousAmount = _amount;
    _amount += deposit;
    _totalAmount += deposit;

	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << previousAmount
				<< ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

// Attempt to withdraw money from the account
// 1) Check if the withdrawal can be made
// 2) Process withdrawal
// 3) Display info
bool Account::makeWithdrawal(int withdrawal)
{
    int previousAmount;

	_displayTimestamp();

    if (withdrawal > _amount)
	{
        std::cout << "index:" << _accountIndex
                  << ";p_amount:" << _amount
                  << ";withdrawal:refused"
                  << std::endl;
        return false;
    }

	previousAmount = _amount;
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;

	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << previousAmount
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return true;
}

// Check the current balance (amount)
int Account::checkAmount(void) const
{
	return _amount;
}

// Display account status
void Account::displayStatus(void) const
{
	_displayTimestamp();

	std::cout 	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}
