/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:37:20 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/01 12:18:57 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RPN.class.hpp"

RPN::RPN(void){}

RPN::RPN(const RPN &other)
{
	m_stack = other.m_stack;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		m_stack = other.m_stack;
	}
	return (*this);
}

RPN::~RPN(){}

/*
bool RPN::validOperator(std::string oper) const
{
	return (oper == "+" || oper == "-" || oper == "*" || oper == "/");
}
*/

bool RPN::validOperator(char &oper) const
{
	return (oper == '+' || oper == '-' || oper == '*' || oper == '/');
}

double RPN::operation(double &lhs, double &rhs, char &oper) const
{
	if (oper == '+')
	{
		return (lhs + rhs);
	}
	if (oper == '-')
	{
		return (lhs - rhs);
	}
	if (oper == '*')
	{
		return (lhs * rhs);
	}
	if (rhs == 0)
	{
		throw std::runtime_error("\n\033[41mError: Attempted to divide by Zero.\033[0m\n");
	}
	else 
	{
		return (lhs / rhs);
	}
}

double RPN::calculatorRPN(char *seq)
{
	size_t 	len = 0;
	double 	res = 0;
	bool	up = true;

	while (seq[len] != '\0')
	{
		if (seq[len] == ' ')
		{
			if (!up || len == 0)
			{
				up = true;
				++len;
			}
			else
			{
				throw ("\n\033[41mError: Operands and operators must be separated with a single space.\033[0m\n");
			}
		}
		else if (this->validOperator(seq[len]))
		{
			if (m_stack.size() < 2)
			{
				throw ("\n\033[41mError: Not enough operands to perform the operation.\033[0m\n");
			}
			else if (up)
			{
				res = m_stack.top();
				m_stack.pop();
				if (VERBOSE)
				{
					std::cout 	<< "\033[97;42m" << m_stack.top() << " " << seq[len] << " " << res
								<< " = " << this->operation(m_stack.top(), res, seq[len])
								<< "\033[0m\n" << std::endl;
				}
				res = this->operation(m_stack.top(), res, seq[len]);
				m_stack.pop();
				m_stack.push(res);
				++len;
				up = false;
			}
			else
			{
				throw ("\n\033[41mError: Operands and operators must be separated with spaces.\033[0m\n");
			}
		}
		else if (isdigit(seq[len]))
		{
			if (up)
			{
				m_stack.push(seq[len] - '0');
				++len;
				up = false;			
			}
			else
			{
				throw ("\n\033[41mError: Operands and operators must be separated with spaces.\033[0m\n");
			}
		}
		else
		{
			throw ("\n\033[41mError: Wrong parameter.\033[0m\n");
		}
	}
	if (m_stack.size() != 1)
	{
		throw("\n\033[41mError: Not enough parameters to perform the operation.\033[0m\n");
	}
	return (m_stack.top());
}
