/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:06:43 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/12 09:52:57 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/Bureaucrat.class.hpp"
#include <cstdio>

void 	ft_next(std::string msg)
{
	std::cout   << "\nTake your time to revise the accuracy "
                << "of the above implementation.\n"
                << "Enter any key to continue with the next section: "
				<< msg
                << std::endl;
	getchar();
}

int	main(void)
{
	{
		std::cout 	<< "\n\nTEST 1a: Bureaucrats with wrong grades: " 
					<< "testing try / catch messages"
					<< std::endl;
		int 	grade = -3;//un/acceptable grades
		try
		{
			std::cout 	<< "Declaration of a Bureaucrat with wrong grade " << grade
						<< std::endl;
			Bureaucrat	pupas("Pupas", grade);//constructor protected inside try catch
			std::cout << pupas;
			for (int cur = 0; cur < grade; cur++)
			{
				pupas.incrementGrade();
				std::cout << cur << " " << pupas << std::endl;
			}
		}
		catch (Bureaucrat::GradeTooHighException &e)//Known exception
		{
			std::cout << "Ups! " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)//Known exception
		{
			std::cout << "Yeps! " << e.what() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "\tSomehow known problem caught..." << std::endl;
		}
		ft_next("NULL Bureaucrats throw customized messages");
		std::cout 	<< "\n\nTEST 1b: Bureacrats with wrong grades: " 
					<< "testing try / catch messages\n\n"
					<< std::endl;
		Bureaucrat* muymalo = NULL;
		std::cout 	<< "Declaration of a NULL Bureaucrat: throw" 
					<< " a \033[32m\"general exception\"\033[0m "
					<< "if we try to make them \"work\" (ehem!)"
					<< std::endl;
		try
		{
			if (!muymalo)
			{
				throw std::exception();
			}
			std::cout << muymalo->getGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "Upas! " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << "Yepas! " << e.what() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "\tUnknown \033[32m\"general exception\"\033[0m caught..." << std::endl;
		}
		catch (...)
		{
			std::cout << "\tThe weird problem caught..." << std::endl;
		}
		ft_next("NULL Bureaucrats throw customized messages");
		std::cout 	<< "Declaration of a NULL Bureaucrat: throw" 
					<< " a \033[32m\"weird exception\"\033[0m caught."
					<< std::endl;
		try
		{
			if (!muymalo)
			{
				throw 69;
			}
			std::cout << muymalo->getGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "Upas! " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << "Yepas! " << e.what() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "\tUnknown problem caught..." << std::endl;
		}
		catch (...)
		{
			std::cout << "\tThe \033[32m\"weird exception\"\033[0m caught..." << std::endl;
		}
		std::cout 	<< "Declaration of a NULL Bureaucrat: throw" 
					<< " a \033[32m\"no so weird exception\"\033[0m caught by an int."
					<< std::endl;
		try
		{
			if (!muymalo)
			{
				throw 69;
			}
			std::cout << muymalo->getGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "Upas! " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << "Yepas! " << e.what() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "\tUnknown problem caught..." << std::endl;
		}
		catch (int code)
		{
			std::cout 	<< "\tThe no \033[32m\"no so weird exception\"\033[0m caught code " << code
						<< std::endl;
		}
		catch (...)
		{
			std::cout << "\tThe weird problem caught..." << std::endl;
		}
		std::cout 	<< "Declaration of a NULL Bureaucrat: throw" 
					<< " a \033[32mcustomized message\033[0m"<< std::endl;
		try
		{
			if (!muymalo)
			{
				throw std::runtime_error("\033[32mNull pointer exception: ptr is NULL!\033[0m");
			}
			std::cout << muymalo->getGrade();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "Upas! " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << "Yepas! " << e.what() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "\t" << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "\tThe weird problem caught..." << std::endl;
		}
		ft_next("Deep Copy");
		Bureaucrat	pepe = Bureaucrat("Pepe", LOWEST);
		Bureaucrat	pepe_copy(pepe);
		Bureaucrat	nene("Nene", 123);
		std::cout 	<< "New people recruited:\n"
					<< pepe << std::endl;
		std::cout 	<< "Copied from previous:\n"
					<< pepe_copy << std::endl;
		std::cout 	<< "Another one:\n"
				 	<< nene << std::endl;
		std::cout << "New burrocrate enrolled as:\t"<< pepe_copy << std::endl;
		pepe_copy = nene;
		std::cout << "The new burrocrate promoted to:\t"<< pepe_copy << std::endl;
		std::cout << "Equalized to\t=>\t=>\t" << nene << std::endl;
		std::cout << pepe.getName() << " lives at \t" << &pepe << std::endl;
		std::cout << pepe_copy.getName() << " lives at \t" << &pepe_copy << std::endl;
		std::cout << nene.getName() << " lives at \t" << &nene << std::endl;
		std::cout << "As you can see they have different addresses" << std::endl;
		std::cout << nene.getName() << " has been fired!" << std::endl;
		nene.~Bureaucrat();
		std::cout << pepe_copy << " is still here." << std::endl;
		try
		{
			pepe.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << "Buff!\t" << e.what() << std::endl;
		}
		try
		{
			std::cout 	<< "Let's try to recruit another one grade "
						<< LOWEST + 1 << std::endl;
			Bureaucrat	jose = Bureaucrat("Jose", LOWEST + 1);
			std::cout << jose << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Nope!\t" << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "\tThe weird problem caught..." << std::endl;
		}
		ft_next("Pointers and arrays");
	}
	{
		std::cout 	<< "\033[32m\n\n\nTest 2: Rectruiting an excess of bureaucrats"
					<< "\033[0m" << std::endl;

		Bureaucrat 	*depart[16];
		int 		crew = 152;
		int 		enrolled = 0;
		std::string dept = "Sudokus Lvl ";
		try
		{
			std::cout 	<< "Let's recruit some people"
						<< std::endl;
			for (int i = 1; i <= crew; i++)
			{
				if ((i -1) >= 16)
				{
					throw ("Crew limit exceeded\n");
				}
				std::ostringstream ss;
				ss << dept << i;
				depart[i-1] = new Bureaucrat((std::string)(ss.str()), i);
				enrolled++;
				std::cout	<< "Hello! I am " << *depart[i-1]
							<< std::endl;
			}
		}
		catch (const char* msg)
		{
			std::cout << "\033[31m" << msg << "\033[0m";
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		catch (...)
		{
			std::cout << "\033[31mNew problem found\033[0m" << std::endl;
		}
		for (int i = 0; i < enrolled; i++)
		{
			if (depart[i] != NULL)
				delete depart[i];
		}
		ft_next("Arrays dealing with wrong levels");
	}
	{
		std::cout 	<< "\033[32m\n\n\nTest 3: Rectruiting bureaucrats with wrong levels"
					<< "\033[0m" << std::endl;

		Bureaucrat 	*depart[160];
		int 		crew = 152;
		int 		enrolled = 0;
		std::string dept = "Sudokus Lvl ";
		try
		{
			std::cout 	<< "Let's recruit some people"
						<< std::endl;
			for (int i = 1; i <= crew; i++)
			{
				if ((i -1) >= 160)
				{
					throw ("Crew limit exceeded\n");
				}
				std::ostringstream ss;
				ss << dept << i;
				depart[i-1] = new Bureaucrat((std::string)(ss.str()), i);
				enrolled++;
				std::cout	<< "Hello! I am " << *depart[i-1]
							<< std::endl;
			}
		}
		catch (const char* msg)
		{
			std::cout << "\033[31m" << msg << "\033[0m";
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		catch (...)
		{
			std::cout << "\033[31mNew problem found\033[0m" << std::endl;
		}
		ft_next("DOGE TIME");
		for (int i = 0; i < enrolled; i++)
		{
			if (depart[i] != NULL)
				delete depart[i];
		}
	}
	return 0;
}

