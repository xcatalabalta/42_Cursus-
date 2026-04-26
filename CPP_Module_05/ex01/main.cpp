/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:06:43 by fcatala-          #+#    #+#             */
/*   Updated: 2025/04/15 17:12:09 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/Form.class.hpp"
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
		std::cout 	<< "\033[32mTest 1: Testing Right & wrong forms in different scopes" 
					<< "\033[0m"
					<< std::endl;

		Form 	top;

		std::cout 	<< "Form created:\n"
					<< top << std::endl;
		try
		{
			std::cout 	<< TRY_NEW_FORM
						<< "Grade to sign: 83\t"
						<< "Grade to execute: 0"
						<< std::endl;
			Form a32m("a32m", 83, 0);
			std::cout 	<< "New form created:\n"
						<< a32m << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout 	<< TRY_NEW_FORM 
						<< "Build from: " << top
						<< std::endl;
			Form 	*a68c = new Form(top);
			std::cout 	<< "New form 2 created:\n"
						<< *a68c << std::endl;
			std::cout 	<< "Life is short when you have been created "
						<< "in a try / catch scope: "
						<< std::endl;
			delete a68c;
		}
		catch(...)
		{
			std::cout 	<< "It's breakfast time. " 
						<< NEXT_W << std::endl;
		}
		try
		{
			std::cout 	<< TRY_NEW_FORM
						<< "Grade to sign: 42\t"
						<< "Grade to execute: -3"
						<< std::endl;
			Form 	a39c("a39c", 42, -3);
			std::cout 	<< "Form created\n"
						<< a39c << std::endl;
		}
		catch(...)
		{
			std::cout 	<< "I am not going to tell why I have rejected this."
						<< " It's lunch time. " 
						<< NEXT_W << std::endl;
		}
		try
		{
			std::cout 	<< TRY_NEW_FORM
						<< "Grade to sign: 342\t"
						<< "Grade to execute: 12"
						<< std::endl;
			Form 	*a74c = new Form("a74c", 342, 12);
			std::cout 	<< "Form created\n"
						<< *a74c << std::endl;
			delete a74c;
		}
		catch(const std::exception& e)
		{
			std::cout 	<< "It's time to leave. "
						<< e.what() << "\n"
						<< NEXT_W << std::endl;
		}
		std::cout << "Form 1: "<< top << std::endl;
		ft_next("Signing forms");
		std::cout << "\033[32mEND of Test 1 (destruction time)\033[0m" << std::endl;
	}
	{
		std::cout 	<< "\033[32m\n\n\nTest 2: Testing signing forms in different scopes" 
					<< "\033[0m" << std::endl;
		
			Bureaucrat 	boss("Boss", HIGHEST);
			Bureaucrat	pring("Mandao", LOWEST);
			Form 		top("TOP", 1, 5);
			Form 		truc;
			Form 		mini("Simple", LOWEST, LOWEST);
		try
		{
			std::cout 	<< "The stack to sign:\n"
						<< mini << std::endl
					 	<< top << std::endl
					 	<< truc << std::endl
						<< "Our hero:\n"
						<< pring << std::endl;
			mini.beSigned(pring);
			std::cout << mini << std::endl;
			truc.beSigned(pring);
			std::cout << truc << std::endl;
			top.beSigned(boss);
			std::cout << top << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
			try
			{
				std::cout << boss << " will deal with it:" << std::endl;
				std::cout << mini << std::endl;
				std::cout << truc << std::endl;
				std::cout << top << std::endl;
				mini.beSigned(boss);
				truc.beSigned(boss);
				top.beSigned(boss);
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() << '\n';
			}
		}
		
		std::cout << boss << " Job done!:" << std::endl;
		std::cout << mini << std::endl;
		std::cout << truc << std::endl;
		std::cout << top << std::endl;
		ft_next("Bureaucrats sign forms: \033[32mdifferent behaviour\033[0m");
		std::cout << "\033[32mEND of Test 2 (destruction time)\033[0m" << std::endl;
	}
	{
		std::cout 	<< "\033[32m\n\n\nTest 2b: Testing Bureaucrats sign forms" 
					<< "\033[0m" << std::endl;
		
			Bureaucrat 	boss("Boss", HIGHEST);
			Bureaucrat	pring("Mandao", LOWEST);
			Form 		top("TOP", 1, 5);
			Form 		truc;
			Form 		mini("Simple", LOWEST, LOWEST);
		try
		{
			std::cout 	<< "The stack to sign:\n"
						<< mini << std::endl
					 	<< top << std::endl
					 	<< truc << std::endl
						<< "Our hero:\n"
						<< pring << std::endl;
			pring.signForm(mini);
			std::cout << mini << std::endl;
			pring.signForm(truc);
			std::cout << truc << std::endl;
			std::cout << "\n" << boss << " will REVISE your job:" << std::endl;
			std::cout << mini << std::endl;
			std::cout << top << std::endl;
			std::cout << truc << std::endl;
			boss.signForm(mini);
			boss.signForm(top);
			boss.signForm(truc);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		catch (...)
		{
			std::cout << "\033[31mNew problem found\033[0m" << std::endl;
		}
		std::cout << boss << " Job done!:" << std::endl;
		std::cout << top << std::endl;
		std::cout << truc << std::endl;
		ft_next("Arrays");
		std::cout << "\033[32mEND of Test 2b (destruction time)\033[0m" << std::endl;
	}
	{
		std::cout 	<< "\033[32m\n\n\nTest 3: Creation of a crew of 160 Bureaucrats " 
					<< "from 182 candicates. \nCreation of a bunch of 30 forms, "
					<< "which exceeds the limit of the maximum possible (12)"
					<< "\033[0m" << std::endl;

		Bureaucrat 	*depart[160];
		int 		crew = 182;
		int 		enrolled = 0;
		std::string dept = "Sudokus Lvl ";
		Form 		*papers[12];
		int 		max_job = 30;
		int 		created = 0;
		std::string typo = "A210/";
		int 		dept_signer = 3;

		try
		{
			std::cout 	<< "Let's recruit some people (max 160)"
						<< std::endl;
			for (int i = 1; i <= crew; i++)
			{
				if ((i -1) >= 160)
				{
					throw ("Crew limit exceeded\n");
				}
				std::ostringstream ss;
				ss << dept << (int)(i / 2 + 1);
				depart[i-1] = new Bureaucrat((std::string)(ss.str()), (int)(i / 2 + 1));
				enrolled++;
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
		std::cout 	<< "Let's create some forms (max 12)"
					<< std::endl;
		try
		{
			for (int i = 1; i <= max_job; i++)
			{
				if ((i -1) >= 12)
				{
					throw ("Too much work will kill us\n");
				}
				std::ostringstream ss;
				ss << typo << (int)(i / 2 + 1) << "-42";
				papers[i-1] = new Form((std::string)(ss.str()), (int)(i / 2 + 1), 42);
				created++;
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
		std::cout	<< *depart[dept_signer]
					<< ": I am going to sign all the stack!"
					<< std::endl;
		for (int i = 0; i < created; i++)
		{
			std::cout << *papers[created - 1 - i] << std::endl;
			depart[dept_signer]->signForm(*papers[created - 1 - i]);
		}
		std::cout << "After a very trying day ..." << std::endl;
		for (int i = 0; i < created; i++)
		{
			std::cout << *papers[i] << std::endl;
		}
		std::cout << "\n\n\033[32mEND of Test 3 (destruction time)\033[0m" << std::endl;
		for (int i = 0; i < enrolled; i++)
		{
			if (depart[i] != NULL)
				delete depart[i];
		}
		for (int i = 0; i < created; i++)
		{
			if (papers[i] != NULL)
				delete papers[i];
		}
	}
	{
		ft_next("Double sign\n");
		try
		{
			Bureaucrat 	pepe("Pepe", 40);
			Form 		a42("a42", 50, 50);

			pepe.signForm(a42);
			pepe.signForm(a42);

			Bureaucrat bomb("bomber", -3);
		}
		catch (...)
		{
			std::cout 	<< "Somebody tried something ugly"
						<< std::endl;
		}
	}
	return 0;
}

