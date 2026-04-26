/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:08:42 by fcatala-          #+#    #+#             */
/*   Updated: 2025/05/01 08:07:07 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ScalarConverter.class.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{}

static bool isValidNum(std::string input)
{
	bool 	hasNum = false;
	int 	j = 0;
	if (input[0] == '+' || input[0] == '-')
		j++;
	for (; input[j]; j++)
	{
		if (!isdigit(input[j]) && input[j] != 'f' && input[j] != '.')
			return (false);
		if (isdigit(input[j]))
			hasNum = true;
	}
	return (hasNum);
}

static int getLastZeros(std::string input)
{
	int len = input.length();
	int zero = 0;// + input[len - 1] == 'f';
	while (input[--len] == '0' || input[len] == 'f')
	{
		++zero;
	}
	return (zero);
}

void ScalarConverter::convert(const std::string &liter)
{
	if (liter.length() == 0)
	{
		std::cout 	<< "Empty argument."
					<< std::endl;
		return ;
	}
	if (liter == "+inff" || liter == "+inf")
	{
		std::cout  	<< "char:  \t" << "Impossible\n"
					<< "int:   \t" << "Impossible\n"
					<< "float: \t" << "+inff\n"
					<< "double:\t" << "+inf"
					<< std::endl;
		return ;
	}
	else if (liter == "-inff" || liter == "-inf")
	{
		std::cout  	<< "char:  \t" << "Impossible\n"
					<< "int:   \t" << "Impossible\n"
					<< "float: \t" << "-inff\n"
					<< "double:\t" << "-inf"
					<< std::endl;
		return ;
	}
	else if (liter == "nan" || liter == "nanf")
	{
		std::cout  	<< "char:  \t" << "Impossible\n"
					<< "int:   \t" << "Impossible\n"
					<< "float: \t" << "nanf\n"
					<< "double:\t" << "nan"
					<< std::endl;
		return ;
	}
	if (liter.length() == 1)
	{
		if (isprint(liter[0]))
		{
			std::cout  	<< "char:  \t'" << static_cast<char>(liter[0]) << "'"
						<< std::endl;
		}
		else
		{
			std::cout  	<< "char:  \t" << "Non displayable."
						<< std::endl;
		}
			std::cout 	<< "int:   \t" << (isdigit(liter[0]) ? static_cast<int>(liter[0] - '0') : static_cast<int>(liter[0]))
						<< "\nfloat: \t" << (isdigit(liter[0]) ? static_cast<float>(liter[0] - '0') : static_cast<float>(liter[0])) << ".0f"
						<< "\ndouble:\t" << (isdigit(liter[0]) ? static_cast<double>(liter[0] - '0') : static_cast<double>(liter[0])) << ".0"
						<< std::endl;
		return ;
	}
	else
	{
		std::string::size_type rev;
		std::string::size_type fro;
		std::string::size_type f;

		rev = liter.rfind('.');
		fro = liter.find('.');
		f = liter.find('f');
		int adjust = 0;
		//if (fro == rev && rev != (liter.length() - 1) && ((f == liter.length() - 1 && fro != liter.npos) || f == liter.npos) && isValidNum(liter))
		if (fro == rev	 && ((f == liter.length() - 1 && fro != liter.npos) || f == liter.npos) && isValidNum(liter))
		{
			const char *input = liter.c_str();
			long		lvalue = std::atol(input);
			bool 		excess = (lvalue > std::numeric_limits<int>::max()) || (lvalue < std::numeric_limits<int>::min());
			if (excess)
			{
				std::cout  	<< "char:  \t" << "Impossible.\n"
							<< "int:   \t" << "Impossible.\n";
			}
			else if (!excess)
			{
				if (isprint(lvalue))
				{
					std::cout  	<< "char:  \t'" << static_cast<char>(std::atoi(input)) << "'"
								<< std::endl;
				}
				else
				{
					std::cout  	<< "char:  \t" << ((lvalue < CHAR_MIN || lvalue > CHAR_MAX) ? "Impossible." : "Non displayable.")
								<< std::endl;
				}
				std::cout  	<< "int:   \t" << static_cast<int>(lvalue) << "\t";
				std::cout	<< std::endl;
			}
			std::cout 	<< std::fixed << std::setprecision(0);//prevents scientific notation
			std::cout  	<< "float: \t"
						<< ((std::isinf(static_cast<float>(std::atof(input))) && liter[0] != '-') ? "+" : "");
			if (fro != liter.npos)
			{
				std::cout 	<< std::setprecision(liter.length() - fro - 1 - getLastZeros(liter));
				if ((liter.length() - fro - 1 - getLastZeros(liter)) == 0)
				{
					std::cout 	<< std::setprecision(1);
				}
				adjust = fro + getLastZeros(liter) + 1;		
			}
			std::cout 	<< ((liter[liter.length() - 1] == 'f' && !std::isinf(static_cast<float>(std::atof(input)))) 
							? std::atof(input) : static_cast<float>(std::atof(input)))
						<< ((!std::isinf(static_cast<float>(std::atof(input))) && fro == liter.npos) ? ".0" : "")
						<< "f\n";
			std::cout  	<< "double:\t" 
						<< ((std::isinf(static_cast<double>(std::atof(input))) && liter[0] != '-') ? "+" : "")
						<< std::setprecision((liter.length() - adjust) * (lvalue != std::atof(input)) + (lvalue == std::atof(input)));
			if (fro == liter.npos)
			{
				std::cout 	<< std::fixed << std::setprecision(0);
			}
			std::cout	<< ((liter[liter.length() - 1] == 'f') ? static_cast<double>(std::atof(input)) : std::atof(input))
						<< ((!std::isinf(static_cast<double>(std::atof(input))) && fro == liter.npos ) ? ".0" : "") 
						<< std::endl;
		}
		else
		{
			std::cout  	<< "char:  \t" << "Impossible.\n"
						<< "int:   \t" << "Impossible.\n"
						<< "float: \t" << "Impossible.\n"
						<< "double:\t" << "Impossible."
						<< std::endl;
			return ;
		}
	}
}
