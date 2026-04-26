/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:15:10 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/05 11:37:56 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_CLASS_HPP
# define PRESIDENTIALPARDONFORM_CLASS_HPP

#include "AForm.class.hpp"

# undef		FORM_TYPE
# define 	FORM_TYPE	"PresidentialPardonForm"
# undef		SIGN_GRADE
# define	SIGN_GRADE 	25
# undef		EXEC_GRADE
# define	EXEC_GRADE 	5


class PresidentialPardonForm : public AForm
{
	private:
		std::string	m_target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();//destructor must be virtual (why?)

		//getters
		const std::string	getTarget() const;

		//member functions
		void		execute(const Bureaucrat& executor) const;
};

//std::ostream &operator<<(std::ostream & o, const PresidentialPardonForm &fdp);

#endif