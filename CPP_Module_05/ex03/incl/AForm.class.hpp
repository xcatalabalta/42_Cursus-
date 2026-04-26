/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:15:10 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/12 09:58:22 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CLASS_HPP
# define AFORM_CLASS_HPP

#include "Bureaucrat.class.hpp"

# define NEXT_F			"\nGo to floor AK-72. Next!\n"
# define TRY_NEW_FORM	"\nAtempting to create a new form:\n"

class Bureaucrat;

class AForm
{
	private:
		const std::string	m_name;
		bool				m_signed;
		const int 			m_gr_to_sign;
		const int 			m_gr_to_exec;

	public:
		AForm(void);
		AForm(const std::string name, int grade_sign, int grade_exec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();//destructor must be virtual (why?)

		//getters
		const std::string	getName() const;
		bool 				getSigned() const;
		int 				getGradeToSign() const;
		int					getGradeToExe() const;
		//member functions
		void				beSigned(Bureaucrat &fdp);
		virtual void		execute(const Bureaucrat& executor) const = 0;

		class GradeTooHighException : public std::exception 
		{
			public:
				const char *what() const throw();
			//In C++98, std::exception already declares what() as virtual
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

		class NotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream & o, const AForm &fdp);

#endif