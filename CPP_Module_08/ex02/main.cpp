/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:07:16 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/22 08:19:23 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/MutantStack.class.hpp"
#include <iomanip>
#include <sstream> 
#include <string>

void 	goNext(std::string msg)
{
    std::string line;
	std::cout   << "\033[32m\nTake your time to check the accuracy "
                << "of the above implementation.\n"
                << "Enter any key to continue with the next section: "
				<< "\033[1;4m" << msg << "\033[0m"
                << std::endl;
	std::getline(std::cin, line);//#include <sstream> #include <string>
	line.clear();
	//std::getchar();//#include <cstdio>
}

template<typename T, size_t N>
size_t getArraySize(T (&)[N]) 
{
    return N;
}

int main()
{
	{
		//+/- the Given main
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout 	<< "Actually on top of the stack: "<< mstack.top() << std::endl;
		mstack.pop();
		std::cout 	<< "Actually on top of the stack, after removing the previous value: "<< mstack.top() << std::endl;
		std::cout 	<< "Actual number of elements in the stack: "<< mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(10);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout 	<< "\nShowing the elements in the stack after some additions (forward iterator): " << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		std::cout 	<< "\nShowing the elements in the stack (reverse iterator): " << std::endl;
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
		s.push(-1968);
		MutantStack<int> thing(s);
		std::cout 	<< "\nWhile in the \"real\" stack \'std::stack<int> s(mstack)\' the top is " << s.top() << std::endl;
		MutantStack<int>::iterator pit = thing.begin();
		MutantStack<int>::iterator pite = thing.end();
		std::cout 	<< "\nShowing the elements in the new mutant stack after some additions (forward iterator): " << std::endl;
		while (pit != pite)
		{
			std::cout << *pit << std::endl;
			++pit;
		}
		goNext("\nEnd of the given main. Let's try using lists\n");
		std::list<int> mystack;
		mystack.push_front(5);
		mystack.push_front(17);
		std::cout 	<< "Actually on top of the list: "<< mystack.front() << std::endl;
		mystack.pop_front();
		//mystack.erase(mystack.begin());
		std::cout 	<< "Actually on top of the list, after removing the previous one: "<< mystack.front() << std::endl;
		std::cout 	<< "Actual number of elements in the list: "<< mystack.size() << std::endl;
		mystack.push_back(3);
		mystack.push_back(5);
		mystack.push_back(737);
		//[...]
		mystack.push_back(10);
		std::cout 	<< "\nShowing the elements in the list after some additions: " << std::endl;
		std::list<int>::iterator lit = mystack.begin();
		std::list<int>::iterator lite = mystack.end();
		++lit;
		--lit;
		while (lit != lite)
		{
			std::cout << *lit << std::endl;
			++lit;
		}
		std::list<int>::reverse_iterator rlit = mystack.rbegin();
		std::list<int>::reverse_iterator rlite = mystack.rend();
		std::cout 	<< "\nShowing the elements in the list (reverse iterator): " << std::endl;
		while (rlit != rlite)
		{
			std::cout << *rlit << std::endl;
			++rlit;
		}
		goNext("\nReinterpretation of the given main\n");
	}
	{
		//Reinterpretation of the given main
		MutantStack<int> myStack;
		int 			i = 0;
		std::cout 	<< "\nFilling \033[3mMutantStack<int> mystack\033[23m with 10 correlative numbers:"
					<< std::endl;
		for (; i < 10; ++i)
		{
			myStack.push(i);
			std::cout	<< "["<< i << "] value = " << i << std::endl;
		}
		std::cout 	<< "\nDisplaying the content of \033[3mMutantStack<int> mystack\033[23m "
					<< "using a \033[34mMutantStack iterator\033[0m (forward) :-)"
					<< std::endl;
		MutantStack<int>::iterator it = myStack.begin();
		MutantStack<int>::iterator ite = myStack.end();
		i = 0;
		while (it != ite)
		{
			std::cout	<< "["<< i << "] value = " << *it << std::endl;
			++i;
			++it;
		}
		std::cout 	<< "Declaration of \033[3;34mstd::stack<int> stacky(mystack)\033[0m"
					<< std::endl;
		std::stack<int> stacky(myStack);
		std::cout 	<< "Adding 2 new values to \033[3;34mstd::stack<int> stacky(mystack)\033[0m (-24 and 42)"
					<< std::endl;
		stacky.push(-24);
		stacky.push(42);
		std::cout 	<< "\nDeclaration of \033[3;34mMutantStack<int> otherStack(stacky)\033[0m"
					<< std::endl;
		MutantStack<int> otherStack(stacky);
		std::cout 	<< "\nDisplaying the content of \033[3mMutantStack<int> otherStack\033[23m "
					<< "using a \033[34mMutantStack iterator\033[0m (reverse) :-)"
					<< std::endl;
		MutantStack<int>::reverse_iterator rit = otherStack.rbegin();
		MutantStack<int>::reverse_iterator rite = otherStack.rend();
		i = stacky.size() - 1;
		while (rit != rite)
		{
			std::cout	<< "["<< i << "]\tvalue = " << std::right << std::setw(3)  << *rit << std::endl;
			--i;
			++rit;
		}

		goNext("\nMutantStack working with strings, and a customized constructor\n");
	}
	{
		const std::string myStrings[] = {
				"Peter ", 
				"Jennifer ", 
				"is ", 
				"born to be wild  ", 
				"son of the revolution ", 
				"Andele, Manito!!! "
				};
		size_t 	arraySize = getArraySize(myStrings);
		std::cout 	<< "\nShowing the elements of the array of strings: "
					<< std::endl;
		for (size_t i = 0; i < arraySize; i++)
		{
			std::cout << myStrings[i] << std::endl;
		}
		MutantStack<std::string> strStack_1;
		std::cout 	<< "\nPushing elements with an odd index to \033[3mMutantStack<std::string> strStack\033[0m"
					<< std::endl;
		for (size_t i = 0; i < arraySize; i++)
		{
			if (i % 2 == 1)
			{
				strStack_1.push(myStrings[i]);
				std::cout 	<< "\033[7;35m" << myStrings[i] << "\033[0m pushed to \033[3mMutantStack<std::string> strStack_1\033[0m"
							<< std::endl;
			}
		}
		std::cout 	<< "\nDisplaying the content of \033[3mMutantStack<std::string> strStack_1\033[23m "
					<< "using a \033[34mMutantStack iterator\033[0m (forward) :-)"
					<< std::endl;
		MutantStack<std::string>::iterator it = strStack_1.begin();
		MutantStack<std::string>::iterator ite = strStack_1.end();
		int i = 0;
		while (it != ite)
		{
			std::cout	<< "["<< i << "] string = " << *it << std::endl;
			++i;
			++it;
		}
		std::cout 	<< "Declaration of \033[3;34mstd::stack<std::string> stacky(strStack_1)\033[0m"
					<< std::endl;
		std::stack<std::string> stacky(strStack_1);
		std::cout 	<< "\nPushing odd elements to \033[3mstd::stack<std::string> stacky\033[0m"
					<< std::endl;
		for (size_t i = 0; i < arraySize; i++)
		{
			if (i % 2 == 0)
			{
				stacky.push(myStrings[i]);
				std::cout 	<< "\033[7;35m" << myStrings[i] << "\033[0m pushed to \033[3mstd::stack<std::string> stacky\033[0m"
							<< std::endl;
			}
		}
		std::cout 	<< "\nDeclaration of \033[3;34mMutantStack<std::string> otherStack(stacky)\033[0m"
					<< std::endl;
		MutantStack<std::string> otherStack(stacky);
		std::cout 	<< "\nDisplaying the content of \033[3mMutantStack<<std::string> otherStack\033[23m "
					<< "using a \033[34mMutantStack iterator\033[0m (reverse) :-)"
					<< std::endl;
		MutantStack<std::string>::reverse_iterator rit = otherStack.rbegin();
		MutantStack<std::string>::reverse_iterator rite = otherStack.rend();
		i = stacky.size() - 1;
		while (rit != rite)
		{
			std::cout	<< "["<< i << "] string = \t" << *rit << std::endl;
			--i;
			++rit;
		}
		std::cout 	<< "\nDisplaying the content of \033[3mMutantStack<<std::string> otherStack\033[23m "
					<< "using a \033[34mMutantStack iterator\033[0m (forward) :-)"
					<< std::endl;
		MutantStack<std::string>::iterator fit = otherStack.begin();
		MutantStack<std::string>::iterator fite = otherStack.end();
		i = 0;
		while (fit != fite)
		{
			std::cout	<< "["<< i << "] string = \t" << *fit << std::endl;
			++i;
			++fit;
		}
		goNext("\n\033[5mOutstanding\033[0m project!!\n");
	}
	return 0;
}