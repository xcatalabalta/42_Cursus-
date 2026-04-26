/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:15:10 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/12 09:40:24 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <stdexcept>//Contains specific information about system errors
# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>
#include "../incl/Form.class.hpp"

# define LOWEST		150
# define HIGHEST	1
# define TOO_LOW	"This grade is too low. Minimum is "
# define TOO_HIGH	"This grade is too high. Maximum is "
# define NEXT_W		"\nGo to floor B-27. Next!\n"

class Form;

class Bureaucrat 
{
	private:
		const std::string	m_name;
		int 				m_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		//Getters
		const std::string	getName() const;
		int					getGrade() const;

		//Member functions
		void 				incrementGrade();
		void 				decrementGrade();
		void				signForm(Form &form);

		//Execptions
		class GradeTooHighException : public std::exception 
		{
			public:
				const char *what() const throw();//In C++98, std::exception already declares what() as virtual
		};

		class GradeTooLowException : public std::exception 
		{
			public:
				const char* what() const throw();
		};
};

//Override
std::ostream &operator<<(std::ostream & o, const Bureaucrat &fdp);

#endif