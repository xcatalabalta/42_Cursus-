/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:49:47 by fcatala-          #+#    #+#             */
/*   Updated: 2025/07/13 08:46:47 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_CLASS_HPP
# define BITCOINEXCHANGE_CLASS_HPP
# include <map>
# include <ctime>
# include <sys/stat.h>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <string>
# include <exception>
# include <stdexcept>


class BitcoinExchange
{
	private:
		std::map<std::time_t, double> 	m_timeMap;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange(const char *path);
		BitcoinExchange &operator=(BitcoinExchange &);
		~BitcoinExchange();

		void getValue(const char *path) const;

};
void 			checkFile(const char *path, int type);
void 			printError(std::string 	line, std::string msg);
time_t 			stringToTimeT(const std::string& dateStr);
//std::string 	timeTtoString(time_t date);
#endif