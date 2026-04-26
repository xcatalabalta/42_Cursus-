/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:06:43 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/15 18:08:43 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/PresidentialPardonForm.class.hpp"
#include "incl/ShrubberyCreationForm.class.hpp"
#include "incl/RobotomyRequestForm.class.hpp"
#include <sys/stat.h>

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
		std::cout << "\n\nTEST 1: Executing from Forms" << std::endl;
		PresidentialPardonForm  presi("Mysty");
		ShrubberyCreationForm 	shuprova("Mysty");
		RobotomyRequestForm 	robot("Mysty");
		Bureaucrat 				manel("manel", 25);
		Bureaucrat				maxaka("pringao", 125);
		Bureaucrat				boss("Boss", 2);

		std::cout 	<< "Meet the Bureaucrats\n"
					<< manel << "\n" << maxaka << "\n"
					<< boss << "\n"
					<< "\nMeet the job: \n"
					<< shuprova << "\n" << robot << "\n"
					<< presi 
					<< std::endl;
		try
		{
			std::cout 	<< "\n"<< maxaka << " Trying to sign\n" 
						<< std::endl;
			shuprova.beSigned(maxaka);
			robot.beSigned(maxaka);
			presi.beSigned(maxaka);
			std::cout 	<< "\n"<< maxaka <<" Trying to execute\n" 
						<< std::endl;
			shuprova.execute(maxaka);
			robot.execute(maxaka);
			presi.execute(maxaka);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout 	<< "After the tries by " << maxaka << "\n"
					<< shuprova << "\n" << robot << "\n"
					<< presi 
					<< std::endl;
		try
		{
			std::cout 	<< "\n" << manel <<" Trying to sign\n" 
						<< std::endl;
			shuprova.beSigned(manel);
			robot.beSigned(manel);
			presi.beSigned(manel);
			std::cout 	<< "\n" << manel <<" Trying to execute\n" 
						<< std::endl;
			shuprova.execute(manel);
			robot.execute(manel);
			presi.execute(manel);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout 	<< "After the tries by " << manel << "\n"
					<< shuprova << "\n" << robot << "\n"
					<< presi 
					<< std::endl;
		try
		{
			std::cout 	<< "\n"<< boss <<" Trying to sign\n" 
						<< std::endl;
			shuprova.beSigned(boss);
			robot.beSigned(boss);
			presi.beSigned(boss);
			std::cout 	<< "\n"<< boss <<" Trying to execute\n" 
						<< std::endl;
			shuprova.execute(boss);
			robot.execute(boss);
			presi.execute(boss);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout 	<< "After the tries by " << boss << "\n"
					<< shuprova << "\n" << robot << "\n"
					<< presi 
					<< std::endl;
		ft_next("Presidential executed from Bureaucrat");
	}
	{
		std::cout << "\n\nTEST Presidential" << std::endl;
		PresidentialPardonForm  prova("Barrabas");
		Bureaucrat 				manel("manel", 2);

		std::cout 	<< "Meet the Bureaucrat\n"
					<< manel << std::endl
					<< "Meet the job: \n"
					<< prova << std::endl;
		try
		{
			std::cout << "Trying to sign\n" << std::endl;
			manel.signForm(prova);
			std::cout << "Trying to execute\n" << std::endl;
			manel.executeForm(prova);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << prova << std::endl;
		ft_next("Presidential not signed from Bureaucrat");
	}
	{
		std::cout << "\n\nTEST Presidential not signed" << std::endl;
		PresidentialPardonForm  prova("Barrabas");
		Bureaucrat 				manel("manel", 2);

		std::cout 	<< "Meet the Bureauctrat\n"
					<< manel << std::endl
					<< "Meet the job: \n"
					<< prova << std::endl;
		try
		{
			std::cout << "Trying to execute before signing\n" << std::endl;
			manel.executeForm(prova);
			std::cout << "Trying to sign\n" << std::endl;
			manel.signForm(prova);
			std::cout << "Trying to execute after the 1st try\n" << std::endl;
			manel.executeForm(prova);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << prova << std::endl;
	}
	{
		ft_next("Shrubbery access permission to file: denied");
		std::cout << "\n\nTEST Shrubbery access permission denied" << std::endl;
		ShrubberyCreationForm  	prova("Barrabas");
		Bureaucrat 				manel("Poncio", 5);

		std::cout 	<< "Meet the Bureauctrat\n"
					<< manel << std::endl
					<< "Meet the job: \n"
					<< prova << std::endl;
		
		const char* 			filename = "Barrabas_shrubbery";
		std::ifstream 			infile(filename);
		
		if (!infile.good())
		{
			std::ofstream			file(filename);		
			file.open(filename, std::ios::in);
			if (!file.is_open())
			{
				std::cout << "Error opening file." << std::endl;
        		return 3;
			}
			file.close();
			chmod(filename, S_IRUSR | S_IRGRP | S_IROTH);//Permissions changed 444 Only reading
		}
		try
		{
			std::cout << "Trying to sign\n" << std::endl;
			manel.signForm(prova);
			std::cout << "Trying to execute\n" << std::endl;
			manel.executeForm(prova);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << prova << std::endl;
	}
	{
		ft_next("Shrubbery: target contains \\ ");
		std::cout << "\n\nTEST Shrubbery impossible file" << std::endl;
		ShrubberyCreationForm  	prova("cosa/Barrabas");
		Bureaucrat 				manel("Poncio", 5);

		std::cout 	<< "Meet the Bureauctrat\n"
					<< manel << std::endl
					<< "Meet the job: \n"
					<< prova << std::endl;
		try
		{
			std::cout << "Trying to sign\n" << std::endl;
			manel.signForm(prova);
			std::cout << "Trying to execute\n" << std::endl;
			manel.executeForm(prova);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << prova << std::endl;
	}
	{
		ft_next("Shrubbery finally creates a file");
		std::cout << "\n\nTEST Shrubbery successful" << std::endl;
		ShrubberyCreationForm  	prova("Puchito");
		Bureaucrat 				manel("Poncio", 5);

		std::cout 	<< "Meet the Bureauctrat\n"
					<< manel << std::endl
					<< "Meet the job: \n"
					<< prova << std::endl;
		try
		{
			std::cout << "Trying to sign\n" << std::endl;
			manel.signForm(prova);
			std::cout << "Trying to execute\n" << std::endl;
			manel.executeForm(prova);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << prova << std::endl;
	}
	{
		ft_next("Noisy Robotomy will be executed n times");
		std::cout << "\n\nTEST Robotomy" << std::endl;
		RobotomyRequestForm  	prova("Barrabas");
		Bureaucrat 				manel("Poncio", 5);
		std::srand(std::time(0));

		std::cout 	<< "Meet the Bureauctrat\n"
					<< manel << std::endl
					<< "Meet the job: \n"
					<< prova << std::endl;
		try
		{
			std::cout << "Trying to sign\n" << std::endl;
			manel.signForm(prova);
			std::cout << "Trying to execute 15 times\n" << std::endl;
			for (int i = 0; i < 15; i++)
			{
				manel.executeForm(prova);
			}
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << prova << std::endl;
	}
	return 0;
}

