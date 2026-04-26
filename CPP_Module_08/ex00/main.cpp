/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:14:18 by fcatala-          #+#    #+#             */
/*   Updated: 2025/05/17 08:02:07 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/easyfind.class.hpp"

#include <algorithm>
#include <deque>
#include <list>
#include <set>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdio>

template< typename T >
std::string display(T &it, const T& end)
{
	std::ostringstream oss;
	oss << std::right << std::setw(6);
	if (it != end)
	{		
		oss << *it;
		++it;
	}
	else
	{
		oss << " ";
	}
		oss << " ";
	return (oss.str());
}

void 	ft_goNext(std::string msg)
{
    std::string line;
	std::cout   << "\033[32m\nTake your time to revise the accuracy "
                << "of the above implementation.\n"
                << "Enter any key to continue with the next section:"
				<< "\033[1;4m" << msg << "\033[0m"
                << std::endl;
	std::getline(std::cin, line);//#include <sstream> #include <string>
	line.clear();
	//std::getchar();//#include <cstdio>
}

int main (void)
{
	std::deque<int>		deq;
	std::list<int> 		lst;
	std::set<int>		st;
	std::vector<int>	vec;

	for (int i = 0; i < 100; i++)
	{

		int a = i % 5;

		switch (a)
		{
			case 0:
				deq.push_back(i);
				break;
			case 1:
				lst.push_front(i);
				vec.push_back(i);
				break;
			case 2:
				st.insert(i);
				vec.push_back(i);
				deq.push_back(i);
				break;
			case 3:
				lst.push_front(-i);
				break;
			case 4:
				deq.push_back(i);
				deq.push_back(i + 3);
				lst.push_front(i);
				st.insert(i);
				vec.push_back(i);
				break;
			default:
				break;
		}
	}
	vec.push_back(1968);
	std::srand(std::time(0));
	unsigned long int val;
	std::cout << "\nSearching 10 random values in a container (Type list): " << std::endl;
	for (int i = 0; i < 10; i++)
	{
		val = std::rand() % 100;
		std::list<int>::iterator list_it = easyfind(lst, val);
		if (list_it != lst.end())
			std::cout 	<< "\033[32mValue " << *list_it << " found!\033[0m" 
						<< std::endl;
	}
	std::cout << "\nSearching \033[32m" << val << "\033[0m in different containers: " << std::endl;
	std::list<int>::iterator 	list_it = easyfind(lst, val);
	if (list_it != lst.end())
		std::cout << "Value " << *list_it << " found in the list!\n";
	std::deque<int>::iterator 	deq_it = easyfind(deq, val);
	if (deq_it != deq.end())
		std::cout << "Value " << *deq_it << " found in the deque!\n";
	std::set<int>::iterator 	set_it = easyfind(st, val);
	if (set_it != st.end())
		std::cout << "Value " << *set_it << " found in the set!\n";
	std::vector<int>::iterator 	vec_it = easyfind(vec, val);
	if (vec_it != vec.end())
		std::cout << "Value " << *vec_it << " found in the vector!\n";
	ft_goNext("Displaying the content of the containers");
	val = (lst.size() > deq.size() ? lst.size() : deq.size());
	val = (val > st.size() ? val : st.size());
	val = (val > vec.size() ? val : vec.size());
	deq_it = deq.begin();
	std::list<int>::reverse_iterator rit = lst.rbegin();
	set_it = st.begin();
	vec_it = vec.begin();
	std::cout 	<< "\nThe content of the containers:\n" << std::endl;
	std::cout 	<< "+--------+--------+--------+--------+\n";
	std::cout 	<< "| " << std::setw(6) << "deq "
				<< " | " << std::setw(6) << "list"
				<< " | " << std::setw(6) << "set"
				<< " | " << std::setw(6) << "vector |\n";
	std::cout << "+--------+--------+--------+--------+\n";
	for (unsigned long int i = 0; i < val ; ++i)
	{
		std::cout 	<< "| " << display(deq_it, deq.end())
					<< "| " << display(rit, lst.rend())
					<< "| " << display(set_it, st.end())
					<< "| " << display(vec_it, vec.end()) << "|"
					<< "\n";
	}
	std::cout << "+--------+--------+--------+--------+\n";
	std::cout 	<< "\nHave you realized that the containers have different sizes?\n\n" << std::endl;
	ft_goNext("Displaying the content of the containers properly aligned");
	std::cout 	<< "Displaying the values of the list, just to play with the iterators "
				<< "and practice the alignments:\n\n";
	val = 0;
	for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
	{
		std::cout 	<< "Value at pos" << std::right << std::setw(3) 
					<< ++val << " = " << std::right << std::setw(3) << *lit 
					<< std::endl;
	}
	std::cout 	<< "\nThat's all!!! Let's move to the next exercise!\n";
	return (0);
}
