/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:44:55 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/15 16:48:11 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/AForm.class.hpp"

AForm::AForm(void) 
: m_name("AFormy"), m_signed(false), m_gr_to_sign(HIGHEST), m_gr_to_exec(HIGHEST)
{}

AForm::AForm(const std::string name, int grade_sign, int grade_exec) 
: m_name(name), m_signed(false), m_gr_to_sign(grade_sign), m_gr_to_exec(grade_exec)
{
	if (m_gr_to_sign < HIGHEST || m_gr_to_exec < HIGHEST)
	{
		throw AForm::GradeTooHighException();
	}
	if (m_gr_to_sign > LOWEST || m_gr_to_exec > LOWEST)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm &other) 
: m_name(other.m_name), m_signed(other.m_signed), m_gr_to_sign(other.m_gr_to_sign), 
m_gr_to_exec(other.m_gr_to_exec)
{}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		m_signed = other.m_signed;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << m_name <<"  PAPERLESS has arrived!" << std::endl;
}

const std::string	AForm::getName() const
{
	return (this->m_name);
}

bool AForm::getSigned() const
{
	return (this->m_signed);
}

int	AForm::getGradeToSign() const
{
	return (this->m_gr_to_sign);
}

int	AForm::getGradeToExe() const
{
	return (this->m_gr_to_exec);
}

const char *	AForm::GradeTooHighException::what() const throw()
{
	return ("The grade of the form is too high to be processed by this Univers\n");
}


AForm::GradeTooLowException::GradeTooLowException()
: m_msg("My grade is too low to process this form\n")
{}

AForm::GradeTooLowException::GradeTooLowException(const char *msg)
: m_msg(msg)
{}

const char *	AForm::GradeTooLowException::what() const throw()
{
	return (m_msg);
}

const char * AForm::NotSignedException::what() const throw()
{
	return ("Not signed forms cannot be executed\n");
}
//this->m_signed ^= true;
void AForm::beSigned(Bureaucrat &fdp)
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
		std::cout 	<< "This form must be signed at minimum level " 
					<< this->getGradeToSign()
					<< "\nI cannot sign forms higher than "
					<< fdp.getGrade() << "!!!!"
					<< std::endl;
		throw AForm::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream & oss, const AForm &fdp)
{
	oss << fdp.getName() << "  Form status " 
		<< (fdp.getSigned() ? "\033[32mSigned\033[0m" : "\033[31mUnsigned\033[0m")
		<< "\tGrade to sign: " << fdp.getGradeToSign()
		<< "\tGrade to execute: " << fdp.getGradeToExe();

	return (oss);
}