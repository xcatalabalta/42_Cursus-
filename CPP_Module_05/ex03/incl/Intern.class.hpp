/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:15:10 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/19 09:14:01 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

#include "AForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"

// Define a pointer to a function type for form creation
typedef AForm* (*FormCreator)(const std::string& target);

// Advanced concept from another module
typedef struct s_FormTemplate
{
	std::string 	name;
	FormCreator 	creator;
}	t_FormTemplate;

class AForm;

class Intern 
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		//Member functions
		AForm 	*makeForm(std::string formName, std::string target);

};

#endif
