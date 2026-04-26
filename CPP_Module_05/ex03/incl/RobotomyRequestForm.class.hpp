/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:15:10 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/12 10:09:45 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTORM_CLASS_HPP
# define ROBOTOMYREQUESTFORM_CLASS_HPP

#include "AForm.class.hpp"
#include <cstdlib> // For std::rand, std::srand, and RAND_MAX
#include <ctime>    // For std::time

# undef		FORM_TYPE
# define 	FORM_TYPE	"RobotomyRequestForm"
# undef		SIGN_GRADE
# define	SIGN_GRADE 	72
# undef		EXEC_GRADE
# define	EXEC_GRADE 	45


class RobotomyRequestForm : public AForm
{
	private:
		std::string	m_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();//destructor must be virtual (why?)

		//getters
		const std::string	getTarget() const;

		//member functions
		void		execute(const Bureaucrat& executor) const;
};

//std::ostream &operator<<(std::ostream & o, const RobotomyRequestForm &fdp);

#endif