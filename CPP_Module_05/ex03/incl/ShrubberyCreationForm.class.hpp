/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:15:10 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/05 14:22:31 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP
# define SHRUBBERYCREATIONFORM_CLASS_HPP

# include "AForm.class.hpp"
# include <fstream>

# undef		FORM_TYPE
# define 	FORM_TYPE	"ShrubberyCreationForm"
# undef		SIGN_GRADE
# define	SIGN_GRADE 	145
# undef		EXEC_GRADE
# define	EXEC_GRADE 	137


class ShrubberyCreationForm : public AForm
{
	private:
		std::string	m_target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();//destructor must be virtual (why?)

		//getters
		const std::string	getTarget() const;

		//member functions
		void		execute(const Bureaucrat& executor) const;
		//added functions
		void 		plantTree() const;
};

#endif