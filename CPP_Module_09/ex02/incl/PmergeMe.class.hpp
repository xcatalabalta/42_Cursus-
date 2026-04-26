/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:33:21 by fcatala-          #+#    #+#             */
/*   Updated: 2025/07/15 17:07:54 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP
# include <iostream>
# include <iomanip>
# include <vector>
# include <list>
# include <algorithm>
//# include <cstdlib>
# include <ctime>
# include <sstream>
# include <string>
# include <limits>
# include <stdexcept>
# include <cstdio>

class PmergeMe
{
	private:
		std::vector<int> 	m_vec;
		std::vector<int>  	m_vec_orig;
		std::list<int>  	m_list;
		std::list<int>  	m_list_orig;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

	
	//setter
		void fillContainer(int argc, char **input);

	// Search utils (1st Vector; 2nd List)
		int findInsertPosition(const std::vector<int>& arr, int element, int maxPos) const;
		std::list<int>::iterator findInsertPosition(std::list<int>& lst, int element, int maxPos) const;
	
	// THE algorithm 1st Vector; 2nd list
	// Vector
	std::vector<int> fordJohnsonSort(const std::vector<int>& input) const;
	std::list<int> fordJohnsonSort(const std::list<int>& input) const;


	void execute ();


};

// Auxiliar structure
struct ElementPair 
{
    int smaller;
    int larger;	
    int original_smaller_idx;
    int original_larger_idx;
    
    ElementPair(int s, int l, int s_idx, int l_idx);
};

// Util functions
bool validateInput(std::string num);
std::vector<int> generateJacobsthal(int n);
// List Utils
std::list<int>::iterator advanceIterator(std::list<int>::iterator it, 
                                        std::list<int>::iterator end, 
                                        int distance);
int getDistance(std::list<int>::iterator first, std::list<int>::iterator last);
// User experience function
void 	goNext(std::string msg);
#endif