/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:04:15 by fcatala-          #+#    #+#             */
/*   Updated: 2025/05/02 08:34:54 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/A.class.hpp"
#include "incl/B.class.hpp"
#include "incl/C.class.hpp"
#include <ctime>
#include <cstdlib>


Base *generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (NULL);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A* >(p))
		std::cout << "Point: \033[34mA\033[0m" << std::endl;
	else if (dynamic_cast<B* >(p))
		std::cout << "Point: \033[35mB\033[0m" << std::endl;
	else if (dynamic_cast<C* >(p))
		std::cout << "Point: \033[36mC\033[0m" << std::endl;
	else
		std::cout << "\033[31mIdentification impossible\033[0m\n";
}

//(void) before the dynamic cast: the variable is not going to be used (avoid warning)
//also avoids the use of a dummy variable to hold the result of the dynamic cast
void 	identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "Ref => \033[7;34mA\033[0m" << std::endl;
		return ;
	}
	catch(...){}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "Ref => \033[7;35mB\033[0m" << std::endl;
		return ;
	}
	catch(...) {}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "Ref => \033[7;36mC\033[0m" << std::endl;
		return ;
	}
	catch(...) {}
	std::cout << "\033[7;31mIdentification impossible\033[0m\n";
}

class D: public Base {};//Implemented to exemlify imossible identifications

int main (void)
{
	std::srand(std::time(0));

	Base *prova;

	for (int i = 0; i < 10; i++)
	{
		prova = generate();
		identify(prova);
		identify(*prova);
		delete prova;
	}
	std::cout 	<< "Some impossible cases:\n";
	identify(NULL);
	prova = NULL;
	identify(prova);
	identify(*prova);
	D *kosa = new D;
	identify(kosa);
	identify (*kosa);
	prova = new D;
	identify(prova);
	identify(*prova);
	delete kosa;
	delete prova;
	return (0);
}

