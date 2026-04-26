/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:44:55 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/15 16:56:00 by fcatala-         ###   ########.fr       */
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

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		if (form.getSigned())
		{
			std::cout 	<< "\nJob done before:\n"
						<< form << "\nwas processed by another Dept.\n"
						<< std::endl;
			return ;
		}
		form.beSigned(*this);
		std::cout	<< *this << " signed " << form
					<< std::endl;
	}
	catch (const char* msg)
	{
		std::cout 	<< *this << " couldn't sign "
					<< "because "
					<< msg
					<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout 	<< *this << " couldn't sign "
					<< form << "\nbecause "
					<< e.what()
					<< std::endl;
	}
}

void 	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout	<< *this << " executed " << form
					<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const char* msg)
	{
			std::cout << "\033[31m" << msg << "\033[0m";
	}	
	catch(...)
	{
		std::cout << "\033[31mNew problem found\033[0m" << std::endl;
	}
}

//Testing string conversions (just for learning)
const char *	Bureaucrat::GradeTooHighException::what() const throw()
{
	
	static std::string ciao;
	std::ostringstream oss;

	oss << TOO_HIGH << HIGHEST << NEXT_W;
	ciao = oss.str();
	return (ciao.c_str());
}

//Testing string conversions (just for learning)
const char *	Bureaucrat::GradeTooLowException::what() const throw()
{
	
	static std::string ciao;
	std::ostringstream oss;
	
	oss << TOO_LOW << LOWEST << NEXT_W;
	ciao = oss.str();
	return (ciao.c_str());
}

std::ostream &operator<<(std::ostream & o, const Bureaucrat &fdp)
{
	o << fdp.getName() << ", bureaucrat grade " << fdp.getGrade();
	return (o);
}