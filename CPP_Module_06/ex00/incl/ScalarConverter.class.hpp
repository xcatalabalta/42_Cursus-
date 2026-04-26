/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:44:48 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/30 17:44:19 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP

# include <climits> // CHAR_MIN CHAR_MAX
# include <cmath> //std::isinf
# include <cstdlib> //std::atof
# include <iomanip> //std::setprecision(0)
# include <iostream>
# include <limits> //std::numeric_limits<int>::max()
# include <string>

# include <cctype> // isprint should be there but it is also in string
//# include <ostream>
//# include <sstream>
//# include <cstring> //for memcpy
//# include <bitset>


class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);

	public:
		~ScalarConverter();
		static void convert(const std::string &liter);// char int float double

};

#endif
