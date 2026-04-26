/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:44:55 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/15 18:15:30 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.class.hpp"

Bureaucrat::Bureaucrat(void) : m_name("Nexty"), m_grade(LOWEST) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) 
: m_name(name), m_grade(grade)
{
	if (grade < HIGHEST)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > LOWEST)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : m_name(other.m_name), m_grade(other.m_grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		m_grade = other.m_grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << m_name <<"  DOGE has arrived!" << std::endl;
}

const std::string	Bureaucrat::getName() const
{
	return (m_name);
}

int	Bureaucrat::getGrade() const
{
	return (m_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (m_grade <= HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	else
		m_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (m_grade >= LOWEST)
		throw Bureaucrat::GradeTooLowException();
	else
		m_grade++;
}

//Testing string conversions (just for learning)
const char *	Bureaucrat::GradeTooHighException::what() const throw()
{
	
	static std::string ciao;
	std::ostringstream oss;

	oss << TOO_HIGH << HIGHEST << NEXT_W; // Convert HIGHEST to string and concatenate
	ciao = oss.str(); // Store the result in a static string
	return (ciao.c_str()); // returns a non-modifiable standard C character array version of the string
	
	//return ("The grade is too high. Can you try 1, for example?\n");//Easier solution
}

//Testing string conversions (just for learning)
const char *	Bureaucrat::GradeTooLowException::what() const throw()
{
	
	static std::string ciao;
	std::ostringstream oss;
	
	oss << TOO_LOW << LOWEST << NEXT_W; // Convert LOWEST to string and concatenate
	ciao = oss.str(); // Store the result in a static string
	return (ciao.c_str()); // returns a non-modifiable standard C character array version of the string
	
	//return ("The grade is too low. Can you try 150, for example?\n");//Easier solution
}

std::ostream &operator<<(std::ostream & o, const Bureaucrat &fdp)
{
	o << fdp.getName() << ", bureaucrat grade " << fdp.getGrade() << ".";
	return (o);
}