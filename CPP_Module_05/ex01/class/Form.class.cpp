/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:44:55 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/15 16:42:40 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Form.class.hpp"

Form::Form(void) 
: m_name("Formy"), m_signed(false), m_gr_to_sign(HIGHEST), m_gr_to_exec(HIGHEST)
{}

Form::Form(const std::string name, int grade_sign, int grade_exec) 
: m_name(name), m_signed(false), m_gr_to_sign(grade_sign), m_gr_to_exec(grade_exec)
{
	if (m_gr_to_sign < HIGHEST || m_gr_to_exec < HIGHEST)
	{
		throw Form::GradeTooHighException();
	}
	if (m_gr_to_sign > LOWEST || m_gr_to_exec > LOWEST)
	{
		throw Form::GradeTooLowException("The grade of the form is too low even for us\n");
	}
}

Form::Form(const Form &other) 
: m_name(other.m_name), m_signed(other.m_signed), m_gr_to_sign(other.m_gr_to_sign), 
m_gr_to_exec(other.m_gr_to_exec)
{}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		m_signed = other.m_signed;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << m_name <<"  PAPERLESS has arrived!" << std::endl;
}

const std::string	Form::getName() const
{
	return (this->m_name);
}

bool 		Form::getSigned() const
{
	return (this->m_signed);
}

int	Form::getGradeToSign() const
{
	return (this->m_gr_to_sign);
}

int	Form::getGradeToExe() const
{
	return (this->m_gr_to_exec);
}

const char *	Form::GradeTooHighException::what() const throw()
{
	return ("The grade of the form is too high to be processed by this Universe\n");
}

Form::GradeTooLowException::GradeTooLowException()
: m_msg("My grade is too low to process this form\n")
{}

Form::GradeTooLowException::GradeTooLowException(const char *msg)
: m_msg(msg)
{}

const char *	Form::GradeTooLowException::what() const throw()
{
	return (m_msg);
}

//this->m_signed ^= true;
void Form::beSigned(Bureaucrat &fdp)
{
	if (m_signed)
	{
		std::cout 	<< "The form "<< *this << "\n"
					<< "has been already signed"
					<< std::endl;
	}
	else if (fdp.getGrade() <= this->getGradeToSign())
	{
		this->m_signed = true;
	}
	else
	{
		std::cout 	<< *this << "\n"
					<< "This form must be signed at minimum level " 
					<< this->getGradeToSign()
					<< "\nI cannot sign forms higher than "
					<< fdp.getGrade() << "!!!!"
					<< std::endl;
		throw Form::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream & oss, const Form &fdp)
{
	oss << fdp.getName() << "  Form status " 
		<< (fdp.getSigned() ? "\033[32mSigned\033[0m" : "\033[31mUnsigned\033[0m")
		<< "\tGrade to sign: " << fdp.getGradeToSign()
		<< "\tGrade to execute: " << fdp.getGradeToExe();

	return (oss);
}