/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:04:55 by fcatala-          #+#    #+#             */
/*   Updated: 2025/07/13 08:58:28 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/BitcoinExchange.class.hpp"

BitcoinExchange::BitcoinExchange()
{
	const char	*path = "assets/data.csv";
	std::string 	line;
	std::ifstream 	infile;

	checkFile(path, 1);
	infile.open(path, std::ios::in);
	try 
	{
		infile.exceptions(std::ifstream::badbit);
		std::getline(infile, line);

		std::string 	date, exchange;
		double 			price = 0.0;
		time_t			timeKey;

		while (std::getline(infile, line))
		{
			std::istringstream 	ss(line);
			if (line.find(",") == line.npos || line.find(",") != line.rfind(","))
			{
				continue;
			}
			std::getline(ss, date, ',');
			std::getline(ss, exchange, ',');
			bool 		isDecimal = false;
			bool 		isValid = true;
			for (unsigned long i = 0; i < exchange.length(); ++i)
			{
				if (!isdigit(exchange[i]))
				{
					if(exchange[i] == '.')
					{
						if (!isDecimal)
						{
							isDecimal = true;
						}
						else
						{
							isValid = false;
							break;
						}
					}
					else
					{
						isValid = false;
						break;
					}
				}
			}
			if (!isValid)
			{
				continue;
			}
			std::istringstream value(exchange);
			if (!(value >> price))
			{
				continue;
			}
			timeKey = stringToTimeT(date);
			if (timeKey != -1)
				m_timeMap[timeKey] = price;
		}
		infile.close();
	}
	catch (const std::ios::failure& e)
	{
		std::cerr 	<< "\033[1;31mRead error: " << e.what()
					<< " file: "  << path << "\033[0m"
					<< std::endl;
					exit (1);
	}
	catch (const std::exception& e)
		{
		std::cerr 	<< "\033[1;31mUnexpected File error: " << e.what()
					<< " file: " << path << "\033[0m"
					<< std::endl;
		exit (1);
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	m_timeMap = other.m_timeMap;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &other)
{
	if (this != &other)
	{
		m_timeMap = other.m_timeMap;
	}
	return (*this);
}

BitcoinExchange::BitcoinExchange(const char *path)
{
	std::string 	line;
	std::ifstream 	infile;

	checkFile(path, 1);
	infile.open(path, std::ios::in);
	try 
	{
		infile.exceptions(std::ifstream::badbit);
		std::getline(infile, line);

		std::string 	date, exchange;
		double 			price = 0.0;
		time_t			timeKey;

		while (std::getline(infile, line))
		{
			std::istringstream 	ss(line);
			if (line.find(",") == line.npos || line.find(",") != line.rfind(","))
			{
				continue;
			}
			std::getline(ss, date, ',');
			std::getline(ss, exchange, ',');
			bool 		isDecimal = false;
			bool 		isValid = true;
			for (unsigned long i = 0; i < exchange.length(); ++i)
			{
				if (!isdigit(exchange[i]))
				{
					if(exchange[i] == '.')
					{
						if (!isDecimal)
						{
							isDecimal = true;
						}
						else
						{
							isValid = false;
							break;
						}
					}
					else
					{
						isValid = false;
						break;
					}
				}
			}
			if (!isValid)
			{
				continue;
			}
			std::istringstream value(exchange);
			if (!(value >> price))
			{
				continue;
			}
			timeKey = stringToTimeT(date);
			if (timeKey != -1)
				m_timeMap[timeKey] = price;
		}
		infile.close();
	}
	catch (const std::ios::failure& e)
	{
		std::cerr 	<< "\033[1;31mRead error: " << e.what()
					<< " file: "  << path << "\033[0m"
					<< std::endl;
					exit (1);
	}
	catch (const std::exception& e)
		{
		std::cerr 	<< "\033[1;31mUnexpected File error: " << e.what()
					<< " file: " << path << "\033[0m"
					<< std::endl;
		exit (1);
	}
}

BitcoinExchange::~BitcoinExchange()
{}

void BitcoinExchange::getValue(const char *path) const
{
	std::ifstream 	dataFile;
	std::string 	line;
	std::string 	date;
	std::string  	value;
	std::string 	separator;

	float  			num = 0;
	time_t			timeKey;
	try
	{
		dataFile.open(path, std::ios::in);
		dataFile.exceptions(std::ifstream::badbit);
		std::getline(dataFile, line);
		std::cout << std::fixed << std::setprecision(2);
		while (std::getline(dataFile, line))
		{
			num = 0;
			if (line.length() == 0)
			{
				printError(line, "empty line");
				continue;
			}
			if (line.find(" | ") == line.npos || line.find(" | ") != line.rfind(" | "))
			{
				printError(line, "line not properly formated");
				continue;
			}
			std::istringstream 	ss(line);
			std::getline(ss, date, ' ');
			if (date.length() == 0)
			{
				printError(line, "date not provided");
				continue;
			}
			timeKey = stringToTimeT(date);
			if (timeKey == -1)
			{
				printError(line, "invalid date");
				continue;
			}
			std::getline(ss, separator, ' ');
			std::getline(ss, value, ' ');
			if (value.length() == 0)
			{
				printError(line, "data not provided");
				continue;
			}
			bool 		isDecimal = false;
			bool 		isValid = true;
			bool 		hasSign = false;
			float 		dec = 1;
			for (unsigned long i = 0; i < value.length(); ++i)
			{
				if (!isdigit(value[i]))
				{
					if(value[i] == '.')
					{
						if (!isDecimal)
						{
							isDecimal = true;
						}
						else
						{
							isValid = false;
							break;
						}
					}
					else if (value[i] == '-')
					{
						if (!hasSign)
						{
							hasSign = true;
						}
						else
						{
							isValid = false;
							break;
						}
					}
					else
					{
						isValid = false;
						break;
					}
				}
				else
				{
					if (!isDecimal)
					{
						num = num * 10 + value[i] - '0';
					}
					else
					{
						dec = dec / 10;
						num = num + (value[i] - '0') * dec;
					}
				}
			}
			if (!isValid)
			{				
				printError(line, "invalid number");
				continue;
			}
			if (hasSign)
			{
				printError(line, "data is not a positive number");
				continue;
			}
			if (num > 1000)
			{
				printError(line, "data is too large");
				continue;
			}
			std::map<std::time_t, double>::const_iterator it = m_timeMap.begin();
			std::map<std::time_t, double>::const_iterator lit = m_timeMap.end();
			std::advance(lit, -1);
			if (timeKey < it->first || timeKey > lit->first)
			{
				printError(line, "date is out of range");
				continue;
			}
			lit = m_timeMap.end();
			for (; it != lit; ++it)
			{
				if (it->first == timeKey)
				{
					std::cout   << date << " => " << value 
								<< " x "
								<< it->second
								<< " = "
								<< num * it->second
								<< std::endl;
					break;
				}
				else if (it->first > timeKey)
				{
					--it;
					std::cout   << date << " => " << value 
								<< " x "
								<< it->second
								<< " = "
								<< num * it->second
								<< std::endl;
					break;	
				}
			}
		}
		dataFile.close();
	}
	catch(const std::ios::failure& e)
	{
		std::cerr 	<< "\033[1;31mRead error: " << e.what()
					<< " file: "  << path << "\033[0m"
					<< std::endl;
		exit (1);
	}
	catch (const std::exception& e)
	{
		std::cerr 	<< "\033[1;31mUnexpected File error: " << e.what()
					<< " file: " << path << "\033[0m"
					<< std::endl;
		exit (1);
	}
		catch (...)
	{
		std::cerr 	<< "\033[1;31mUnknown error in file: " 
					<< path << "\033[0m"
					<< std::endl;
        exit (1);
	}
}

void checkFile(const char *path, int type)
{
	struct stat 	fileStat;
	std::ifstream 		file;
	std::string 		line;

	if (stat(path, &fileStat) == -1)
	{
		if (errno == ENOENT)
		{
			std::cerr 	<< "\033[1;31mError: File or directory does not exist: "
						<< path << "\033[0m"
						<< std::endl;
			exit (1);
		}
		else if (errno == EACCES)
		{
			std::cerr 	<< "\033[1;31mError: Access denied to: "
						<< path << "\033[0m"
						<< std::endl;
			exit (1);
		}
		else
		{
			std::cerr 	<< "\033[1;31mError: Unexpected error while accessing to: "
						<< path << "\033[0m"
						<< std::endl;
			exit (1);
		}
	}
	if (S_ISDIR(fileStat.st_mode))
	{
		std::cerr 	<< "\033[1;31mError: "
						<< path << " is a directory.\033[0m"
						<< std::endl;
			exit (1);
	}
	file.open(path, std::ios::in);
	if (!file.is_open())
	{
		if (errno == EACCES)
		{
			std::cerr 	<< "\033[1;31mError: Reading permision denied: "
						<< path << "\033[0m"
						<< std::endl;
			exit (1);
		}
		else
		{
			std::cerr 	<< "\033[1;31mError: "
						<< path << " failed.\033[0m"
						<< std::endl;
			exit (1);
		}
	}
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try 
	{
		std::getline(file, line);
		{
			if ((type == 1 && line != "date,exchange_rate") || (type == 2 && line != "date | value"))
			{
				std::cerr 	<< "\033[1;31mError: "
							<< "Columns do not correspond to the expected input for file "
							<< path << "\033[0m"
						<< std::endl;
				file.close();
				exit (1);
			}
		}
	}
	catch (const std::ios::failure& e)
	{
		std::cerr 	<< "\033[1;31mRead error: " << e.what()
					<< " file: "  << path << "\033[0m"
					<< std::endl;
		exit (1);
	}
	file.close();
}

void 	printError(std::string 	line, std::string msg)
{
	std::cout 	<< "\033[3;41m\"" << line 
				<<"\"\033[1;23;31;49m Error: "<< msg << ".\033[0m" 
				<< std::endl;
}

time_t stringToTimeT(const std::string& dateStr) 
{
	struct tm 			tm ={};

    tm.tm_isdst = -1; // Auto-detect DST => Daylight Saving Time
    
	std::istringstream 	iss(dateStr);
    char 				dash1;
	char 				dash2;
    
	iss >> tm.tm_year >> dash1 >> tm.tm_mon >> dash2 >> tm.tm_mday;
    
    if (iss.fail() || dash1 != '-' || dash2 != '-') 
		return -1;
    
    tm.tm_year -= 1900;  // Adjust for struct tm
    tm.tm_mon -= 1;      // Months are 0-based  

	time_t result = mktime(&tm);
	if (result == -1) 
	{
		return (-1);
	}
	char buf[80];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d", localtime(&result));
	if (buf != dateStr)
	{
		return (-1);
	}
    return (result);
}
/*
// Not used
std::string timeTtoString(time_t date)
{
	char buf[80];
	std::strftime(buf, sizeof(buf), "%Y-%m-%d", localtime(&date));
	return (buf);
}
*/

