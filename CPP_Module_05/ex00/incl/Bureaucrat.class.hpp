/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:15:10 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/12 09:42:14 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

//#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string>
//#include <cstdlib>

# define LOWEST		150
# define HIGHEST	1
# define TOO_LOW	"This grade is too low. Minimum is "
# define TOO_HIGH	"This grade is too high. Maximum is "
# define NEXT_W		"\nGo to floor B-27. Next!\n"

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

		const std::string	getName() const;
		int					getGrade() const;


		void 				incrementGrade();
		void 				decrementGrade();

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

std::ostream &operator<<(std::ostream & o, const Bureaucrat &fdp);

#endif