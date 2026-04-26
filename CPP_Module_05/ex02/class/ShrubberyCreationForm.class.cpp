/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:44:55 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/13 11:55:16 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ShrubberyCreationForm.class.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) 
: AForm (FORM_TYPE, SIGN_GRADE, EXEC_GRADE), m_target("Lucky fellow")
{}

ShrubberyCreationForm::ShrubberyCreationForm (const std::string target)
: AForm (FORM_TYPE, SIGN_GRADE, EXEC_GRADE), m_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm &other) 
: AForm(FORM_TYPE, SIGN_GRADE, EXEC_GRADE), m_target(other.m_target)//m_target(other.getTarget())
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		m_target = other.m_target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

const std::string	ShrubberyCreationForm::getTarget() const
{
	return (m_target);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!this->getSigned())
	{
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExe())
	{
		std::cout 	<< "Grade to execute: " << this->getGradeToExe()
					<< "\tMy grade is " << executor.getGrade()
					<< std::endl;
		throw AForm::GradeTooLowException();
	}
	this->plantTree();
}

//additional function
/*
	//First implementation:
	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	file.open(fileName);
	if (!file.is_open())//file cannot be opened
	{
		std::ifstream infile(fileName);
		if (infile.good())//file already exists
		{
			throw std::runtime_error("Writting permission denied.\n");
		}
		else
		{
			throw ("Unexpected error while opening file.\n");
		}
	}
	//Second Implementation:
        std::ifstream infile(fileName);
        if (infile.good()) 
		{
			infile.close();
			throw std::runtime_error("Shrubbery file already exists but cannot be overwritten (\033[32mpermission denied\033[0m).");
        } 
		else 
		{
            throw std::runtime_error("Unexpected error while opening shrubbery file: " + std::string(e.what()));
        }
*/
void ShrubberyCreationForm::plantTree() const
{
	std::ofstream	file;
	std::string 	name = this->getTarget() + "_shrubbery";
	const 	char 	*fileName = name.c_str();
	
	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try 
	{
        file.open(fileName, std::ios::out | std::ios::trunc); // Force overwrite if possible
		int 			copa = 13;
		int 			tronc = 2;

		for (int i = 0; i < copa; i++)
		{
			if (i % 2)
			{
				for(int j = 0; j < (copa - i) / 2; j++)
				{
					file <<" ";
				}
				for (int j = 0; j < i; j++)
				{
					file <<"*";
				}
				for (int j = 0; j < (copa - i) / 2; j++)
				{
					file <<" ";
				}
				file << std::endl;
			}
		}
		for (int i = 0; i < tronc; i++)
		{
			for (int j = 0; j < copa / 2 - 1 ; j++)
			{
				if (i == tronc - 1)
					file	<<"_";
				else
					file	<<" ";
			}
			file << "|||";
			for (int j = 0; j < copa / 2 - 1 ; j++)
			{
				if (i == tronc - 1)
					file	<<"_";
				else
					file	<<" ";
			}
			file << std::endl;
		}
		try
		{
			file.close();
		}
		catch (const std::ofstream::failure& e)
		{
			throw std::runtime_error("Error while closing shrubbery file: " + std::string(e.what()));
		}
    }
    catch (const std::ofstream::failure& e) 
	{
		if (file.is_open())
		{
			try
			{
				file.close();
			}
			catch(...)
			{
				std::cout 	<< "Unexpected error while closing file " << name
							<< std::endl;
			}
			
		}
    	int errorCode = errno;// Get the system error code
		if (errorCode == EACCES || errorCode == EPERM) 
		{
        	throw std::runtime_error("Shrubbery file cannot be created or overwritten \033[0;31m(permission denied)\033[0m.");
    	} 
    	else if (errorCode == ENOENT) 
		{
        	throw std::runtime_error("\033[0;31mDirectory does not exist \033[0mfor shrubbery file "+ name);
    	}
    	else if (errorCode == ENOSPC) 
		{
        	throw std::runtime_error("No space left on device for shrubbery file.");
    	}
    	else 
		{
			std::ostringstream oss;
			oss 	<< "\033[0;31mUnexpected error while opening shrubbery file: "
					<< std::string(e.what()) 
					<< " (error code: " << errorCode << ")\033[0m\n";
        	throw std::runtime_error(oss.str());
    	}
	}
}
