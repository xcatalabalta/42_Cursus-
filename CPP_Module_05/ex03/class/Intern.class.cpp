/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 10:48:40 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/13 12:40:01 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Intern.class.hpp"

Intern::Intern(void)
{}
Intern::Intern(const Intern &other)
{
	*this = other;
}
Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}
Intern::~Intern() 
{}

static void ft_strtolower(std::string *str)
{
	for (size_t i = 0; i < str->size(); i++)
	{
		(*str)[i] = static_cast<char>(std::tolower((*str)[i]));
	}
	return ;
}

static AForm* createPresidentialPardon(const std::string& target)
{
        return new PresidentialPardonForm(target);
}
    
static AForm* createRobotomyRequest(const std::string& target) 
{
        return new RobotomyRequestForm(target);
}
    
static AForm* createShrubberyCreation(const std::string& target) 
{
        return new ShrubberyCreationForm(target);
}
AForm* 	Intern::makeForm(std::string formName, std::string target)
{
	if (formName.empty() || target.empty())
	{
		std::cout 	<< "Please provide type and target"
					<< std::endl;
		return (NULL);
	}
	std::string 	check = formName;
	ft_strtolower(&check);
	int 	i = 0;
	const t_FormTemplate paperwork[]= 
	{
        { "presidential pardon", createPresidentialPardon },
        { "robotomy request", createRobotomyRequest },
        { "shrubbery creation", createShrubberyCreation },
        { "", NULL }
    };
	while (paperwork[i].creator != NULL)
	{
		if (paperwork[i].name == check)
		{
			AForm *diligence = paperwork[i].creator(target);
			std::cout	<< "Intern creates " << *diligence
						<< std::endl;
			return (diligence);
		}
		i++;
	}
	std::cout 	<< "Form " << formName << " belongs to another department. "
				<< NEXT_F
				<< std::endl;
	throw ("\033[1;34mForm not created\033[0m\n");
	return (NULL);
}