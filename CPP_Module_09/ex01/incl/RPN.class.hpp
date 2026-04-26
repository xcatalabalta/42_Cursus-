/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:27:52 by fcatala-          #+#    #+#             */
/*   Updated: 2025/05/31 19:59:45 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CLASS_HPP
# define RPN_CLASS_HPP

# include <stack>
# include <string>
# include <iostream>
# include <stdexcept>
# ifndef VERBOSE
#  define VERBOSE 0
# endif

class RPN
{
	private:
		std::stack<double> 	m_stack;

	public:
		RPN(void);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		//bool validOperator(std::string oper) const;
		bool validOperator(char &oper) const;
		//double calculatorRPN(std::string seq);
		double calculatorRPN(char *seq);
		double operation(double &lhs, double &rhs, char &oper) const;


};
#endif