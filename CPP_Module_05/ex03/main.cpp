/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:14:23 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/19 07:30:32 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/Intern.class.hpp"

int	main(void)
{
	{
		std::srand(std::time(0));
		Intern someRandomIntern;
		Bureaucrat staff("staff", 100);
		Bureaucrat boss("boss", 9);
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	
		staff.signForm(*rrf);
		staff.executeForm(*rrf);
		boss.signForm(*rrf);
		for (int i = 0; i < 12; i++)
		{
			boss.executeForm(*rrf);
			try
			{
				boss.incrementGrade();
			}
			catch(const std::exception& e)
			{
				std::cout 	<< e.what() << std::endl;
				break;
			}
			catch (...)
			{
				std::cout 	<< "Something weird happened." << std::endl;
				break;
			}
		}
		delete rrf;
		try
		{
			rrf = someRandomIntern.makeForm("roboomy request", "Bender");
			staff.signForm(*rrf);
			staff.executeForm(*rrf);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		catch (const char *msg)
		{
			std::cout 	<< "I knew it: " << msg
						<< std::endl; 
		}
		catch (...)
		{
			std::cout 	<< "Wild thing happenned.\n";
		}
		try
		{
			std::cout 	<< "Something wrong is going to happen.\n"
						<< std::endl;
			//Bureaucrat bomb("bomber", -9);
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			Bureaucrat bomb("bomber", -9);
			bomb.signForm(*rrf);
			bomb.executeForm(*rrf);
			Bureaucrat kbomb("bomber", -9);
			delete rrf;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "Upas! " << e.what() << std::endl;
			delete rrf;

		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		catch (const char *msg)
		{
			std::cout 	<< "I knew it: " << msg
						<< std::endl; 
		}
		catch (...)
		{
			std::cout 	<< "Wild thing happenned\n";
		}
	}
	{
		std::cout 	<< "\n<=== Testing Bureaucrat and Form Creation ===>\n"
					<< std::endl;
		std::srand(std::time(0));
		Intern 		becari;
		Intern 		adjunt(becari);
		Intern 		cafetonet;

		cafetonet = adjunt;
		std::cout << "Our staff of Interns: all from the same origin, all diffent\n";
		std::cout << "Our first Intern:\t" << &becari << std::endl;
		std::cout << "Our second Intern:\t" << &adjunt << std::endl;
		std::cout << "Our third Intern:\t" << &cafetonet << std::endl;

		Bureaucrat*	bomb = NULL;
		Bureaucrat* bomby = NULL;
		AForm* 		rdf = NULL;
		
		try
		{
			bomb = new Bureaucrat("BomberA", 30);
			//bomb = new Bureaucrat("BomberA", 1000);//Throws an exception
			std::cout << *bomb << std::endl;
			//rdf = becari.makeForm("kosa", "Tu tia");//Throws an exception
			//rdf = becari.makeForm("shrubbery creation", "Tu/tia");//Throws an exception
			rdf = becari.makeForm("shrubbery creation", "Tutia");//change permissions after execution to test the exception
			std::cout 	<< "\nTransferring " << *rdf << " (code: " << rdf << ")"
						<< "\nTo be signed and executed by\n"
						<< *bomb << " (Id: "<< bomb << ")"
						<< std::endl;
			bomb->signForm(*rdf);
			bomb->executeForm(*rdf);
			if (rdf != NULL)
			{
				delete rdf;
				rdf = NULL;
			}
			rdf = adjunt.makeForm("robotomy request", "Tu tia");
			std::cout 	<< "\nTransferring " << *rdf << " (code: " << rdf << ")"
						<< "\nTo be signed and executed by\n"
						<< *bomb << " (Id: "<< bomb << ")"
						<< std::endl;
			bomb->signForm(*rdf);
			bomb->executeForm(*rdf);
			if (rdf != NULL)
			{
				delete rdf;
				rdf = NULL;
			}
			//rdf = cafetonet.makeForm("robotomy request", "Tu tia");
			rdf = cafetonet.makeForm("presidential pardon", "Tu tia");
			bomby = new Bureaucrat("Killer", 0);//Throws an exception
			bomby->signForm(*rdf);
			bomby->executeForm(*rdf);
			if (rdf != NULL)
			{
				delete rdf;
				rdf = NULL;
			}
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "\nToo High! " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << "\nToo Low " << e.what() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout 	<< "I understand it is important but\033[3m\n" 
						<< e.what() << "\n\033[0m" << std::endl;
		}
		catch (const char  *msg)
		{
			std::cout 	<< "Sometime happens: \033[3m" << msg
						<< "\n\033[0m"<< std::endl;
		}
		catch(...)
		{
			std::cout 	<< "\033[3;31mSomething weird happend\033[0m"
						<< std::endl;
		}
		if (bomb != NULL)
		{
			delete bomb;
		}
		if (bomby != NULL)
		{
			delete bomby;
		}
		if (rdf != NULL)
		{
			delete rdf;
		}
	}
	return (0);
}
