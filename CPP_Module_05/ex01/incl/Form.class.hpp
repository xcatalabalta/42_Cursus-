/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:15:10 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/15 16:42:40 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

#include "Bureaucrat.class.hpp"

# define NEXT_F			"\nGo to floor AK-72. Next!\n"
# define TRY_NEW_FORM	"\nAtempting to create a new form:\n"

class Bureaucrat;

class Form 
{
	private:
		const std::string	m_name;
		bool				m_signed;
		const int 			m_gr_to_sign;
		const int 			m_gr_to_exec;

	public:
		Form(void);
		Form(const std::string name, int grade_sign, int grade_exec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		//getters
		const std::string	getName() const;
		bool 				getSigned() const;
		int 				getGradeToSign() const;
		int					getGradeToExe() const;
		//member functions
		void				beSigned(Bureaucrat &fdp);

		class GradeTooHighException : public std::exception 
		{
			public:
				const char *what() const throw();//In C++98, std::exception already declares what() as virtual
		};

		class GradeTooLowException : public std::exception 
		{
			private:
				const char*	m_msg;	//The message is stored safely inside the exception object.
									//The standard std::exception typically stores its message internally.
	
			public:
				GradeTooLowException(void);
				GradeTooLowException(const char *msg);
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream & oss, const Form &fdp);

#endif