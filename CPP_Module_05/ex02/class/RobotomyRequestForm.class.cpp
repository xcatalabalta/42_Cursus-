/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:44:55 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/12 10:34:37 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RobotomyRequestForm.class.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) 
: AForm (FORM_TYPE, SIGN_GRADE, EXEC_GRADE), m_target("Lucky fellow")
{}

RobotomyRequestForm::RobotomyRequestForm (const std::string target)
: AForm (FORM_TYPE, SIGN_GRADE, EXEC_GRADE), m_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm (const RobotomyRequestForm &other) 
: AForm(FORM_TYPE, SIGN_GRADE, EXEC_GRADE), m_target(other.m_target)//m_target(other.getTarget())
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		m_target = other.m_target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

const std::string	RobotomyRequestForm::getTarget() const
{
	return (m_target);
}

//std::srand(std::time(0)); // Seed moved to main
void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!this->getSigned())
	{
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExe())
	{
		throw AForm::GradeTooLowException();
	}
	for (int i = 30; i < 38; i++)
	{
		int colorCode = i;
		std::ostringstream oss;
		oss << "\033[" << colorCode << "m";
		std::cout << oss.str() << "*noise* " << "\033[0m";
	}
	std::cout << std::endl;

	if (std::rand() % 2)
	{
		std::cout 	<< this->getTarget()
					<< " has been robotomized successfully"
					<< std::endl;
	}
	else
	{
		std::cout 	<< "Robotomy to " << this->getTarget()
					<< " has failed"
					<< std::endl;
	}
	
}

