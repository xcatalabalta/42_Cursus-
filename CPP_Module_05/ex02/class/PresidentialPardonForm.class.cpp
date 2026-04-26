/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:44:55 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/05 11:37:56 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PresidentialPardonForm.class.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) 
: AForm (FORM_TYPE, SIGN_GRADE, EXEC_GRADE), m_target("Lucky fellow")
{}

PresidentialPardonForm::PresidentialPardonForm (const std::string target)
: AForm (FORM_TYPE, SIGN_GRADE, EXEC_GRADE), m_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm (const PresidentialPardonForm &other) 
: AForm(FORM_TYPE, SIGN_GRADE, EXEC_GRADE), m_target(other.m_target)//m_target(other.getTarget())
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		m_target = other.m_target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

const std::string	PresidentialPardonForm::getTarget() const
{
	return (m_target);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!this->getSigned())
	{
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExe())
	{
		throw AForm::GradeTooLowException();
	}
	std::cout 	<< this->getTarget()
				<< " has been pardoned by Zaphod Beeblebrox"
				<< std::endl;
}

