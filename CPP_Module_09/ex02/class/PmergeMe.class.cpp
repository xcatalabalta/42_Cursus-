/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:47:23 by fcatala-          #+#    #+#             */
/*   Updated: 2025/07/15 17:24:57 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.class.hpp"

// Orthodox Canonical
PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	m_list = other.m_list;
	m_list_orig = other.m_list_orig;
	m_vec = other.m_vec;
	m_vec_orig = other.m_vec_orig;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		m_list = other.m_list;
		m_list_orig = other.m_list_orig;
		m_vec = other.m_vec;
		m_vec_orig = other.m_vec_orig;
	}
	return (*this);
}
PmergeMe::~PmergeMe(){}

//setter
void PmergeMe::fillContainer(int argc, char **input)
{
	for (int i = 1; i < argc; ++i)
	{
		if (!validateInput(input[i]))
		{
			throw std::invalid_argument ("Invalid argument");
		}
		std::istringstream iss(input[i]);
		int num;
		if (iss >> num) 
		{
			m_vec.push_back(num);
			m_vec_orig.push_back(num);
			m_list.push_back(num);
			m_list_orig.push_back(num);
		} 
		else 
		{
			std::cerr 	<< "Error: Invalid input: " << input[i]
						<< " is not a valid integer."
						<< std::endl;
			throw std::invalid_argument ("Invalid argument");
		}
	}
}

// Search utils
int PmergeMe::findInsertPosition(const std::vector<int>& arr, int element, int maxPos) const
{
    int left = 0;
    int right = std::min(maxPos, static_cast<int>(arr.size()) - 1);
    
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= element) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }
    return (left);
}

// Important potential change: linear search instead of binary search due to list iterator limitations
// Binary search is expensive in terms of comparison
// Hypothetical list binary search - Inefficient
std::list<int>::iterator PmergeMe::findInsertPosition(std::list<int>& lst, int element, int maxPos) const 
{
    if (lst.empty()) 
    {
        return lst.begin();
    }
    // Convert maxPos to actual search range
    int searchRange = std::min(maxPos + 1, static_cast<int>(lst.size()));
    if (searchRange <= 0) 
    {
        return lst.begin();
    }
    
    int left = 0;
    int right = searchRange - 1;
    
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        
        // Get iterator to mid position
        std::list<int>::iterator midIter = lst.begin();
        for (int i = 0; i < mid; ++i) 
        {
            ++midIter;
        }
        if (*midIter <= element) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }    
    // Convert final position back to iterator
    std::list<int>::iterator result = lst.begin();
    for (int i = 0; i < left && result != lst.end(); ++i) 
    {
        ++result;
    }
    return (result);
}
//

void PmergeMe::execute()
{
	std::cout << "Unsorted parameters: ";
	for (size_t i = 0; i < m_vec.size(); ++i) 
    {
        std::cout << m_vec[i] << " ";
    }
    std::cout << std::endl;
	clock_t startFJ = clock();
	m_vec = fordJohnsonSort(m_vec);
	clock_t endFJ = clock();
	double FJ_time = static_cast<double>(endFJ - startFJ) / CLOCKS_PER_SEC;
	std::vector<int> orig_sorted = m_vec_orig;
	clock_t startVector = clock();
	std::sort(orig_sorted.begin(), orig_sorted.end());
	clock_t endVector = clock();
	double vector_time = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC;
    clock_t startLFJ = clock();
    m_list = fordJohnsonSort(m_list);
    clock_t endLFJ = clock();
    double LFJ_time = static_cast<double>(endLFJ - startLFJ) / CLOCKS_PER_SEC;
	clock_t startList = clock();
	m_list_orig.sort();
	clock_t endList = clock();
	double list_time = static_cast<double>(endList - startList) / CLOCKS_PER_SEC;
    std::cout << "\033[32mSorted parameters:\033[0m   ";
    for (size_t i = 0; i < m_vec.size(); ++i) 
    {
        std::cout << m_vec[i] << " ";
    }
    std::cout 	<< std::fixed << std::setprecision(6);
    std::cout 	<< "\nTime to process a range of "<< m_vec_orig.size()
				<< " elements with std::vector<int>:\t" << FJ_time << " s"
                << "\nTime to process a range of "<< m_list_orig.size() 
                << " elements with std::list<int>:\t" << LFJ_time << " s"
				<< std::endl;
    goNext("Visualize parameters vertically and a +");
    std::list<int>::iterator it = m_list_orig.begin();
    std::list<int>::const_iterator lit = m_list.begin();
	std::cout 	<<"Original  VectFJ  VectST  ListFJ  ListST" << std::endl;
	for (size_t i = 0; i < m_vec.size(); ++i) 
    {
        std::cout 	<< std::right << std::setw(8)
					<< m_vec_orig[i] 
					<< std::right << std::setw(8) 
					<< m_vec[i] 
					<< std::right << std::setw(8)  
					<< orig_sorted[i]
                    << std::right << std::setw(8)
					<< *lit
					<< std::right << std::setw(8)
					<< *it
					<< std::endl;

		if (m_vec[i] != orig_sorted[i] || *lit != *it)
		{
			std::cout << "WTF!!!!" << std::endl;
			break;
		}
        ++it;
        ++lit;
    }
	std::cout 	<< std::fixed << std::setprecision(3);
    std::cout 	<< "\nTime to process a range of "<< m_vec_orig.size()
				<< " elements (miliseconds):\nFJ vector:\t" << std::right << std::setw(8) << FJ_time * 1000 << " ms"
				<< "\nNative vector:\t" << std::right << std::setw(8) << vector_time * 1000 << " ms"
                << "\nFJ list:\t" << std::right << std::setw(8) << LFJ_time * 1000 << " ms"
				<< "\nNative list:\t" << std::right << std::setw(8) << list_time * 1000 << " ms"
				<< std::endl;
}
// THE algorithm
// Vector
std::vector<int> PmergeMe::fordJohnsonSort(const std::vector<int>& input) const 
{
    int n = input.size();
    
    // Base cases
    if (n <= 1) 
    {
        return (input);
    }    
    if (n == 2) 
    {
        std::vector<int> result = input;
        if (result[0] > result[1]) 
        {
            std::swap(result[0], result[1]);
        }
        return (result);
    }    
    // Step 1: Create pairs
    std::vector<ElementPair> pairs;
    int unpaired_element = -1;
    bool has_unpaired = false;
    for (int i = 0; i < n - 1; i += 2) 
    {
        if (input[i] <= input[i + 1]) 
        {
            pairs.push_back(ElementPair(input[i], input[i + 1], i, i + 1));
        } 
        else 
        {
            pairs.push_back(ElementPair(input[i + 1], input[i], i + 1, i));
        }
    }    
    // Handle unpaired element
    if (n % 2 == 1) 
    {
        unpaired_element = input[n - 1];
        has_unpaired = true;
    }    
    // Step 2: Recursively sort the larger elements
    std::vector<int> larger_elements;
    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        larger_elements.push_back(pairs[i].larger);
    }
    std::vector<int> sorted_larger = fordJohnsonSort(larger_elements);
    // Step 3: Create ordered pairs based on sorted larger elements
    std::vector<ElementPair> ordered_pairs;
    for (size_t i = 0; i < sorted_larger.size(); ++i) 
    {
        // Find the pair that contains this larger element
        for (size_t j = 0; j < pairs.size(); ++j) 
        {
            if (pairs[j].larger == sorted_larger[i]) 
            {
                ordered_pairs.push_back(pairs[j]);
                // Mark this pair as used by setting larger to a sentinel value
                pairs[j].larger = -999999;
                break;
            }
        }
    }    
    // Step 4: Build main chain
    std::vector<int> main_chain;    
    // Insert first smaller element
    if (!ordered_pairs.empty()) 
    {
        main_chain.push_back(ordered_pairs[0].smaller);
    }    
    // Insert all larger elements in sorted order
    for (size_t i = 0; i < sorted_larger.size(); ++i) 
    {
        main_chain.push_back(sorted_larger[i]);
    }    
    // Step 5: Insert remaining smaller elements using Jacobsthal sequence
    if (ordered_pairs.size() > 1) 
    {
        std::vector<bool> inserted(ordered_pairs.size(), false);
        inserted[0] = true; // First element already inserted        
        std::vector<int> jacobsthal = generateJacobsthal(ordered_pairs.size());
        // Process Jacobsthal numbers
        for (size_t j = 1; j < jacobsthal.size() && jacobsthal[j] <= static_cast<int>(ordered_pairs.size()); ++j)
        {
            int current_jacob = jacobsthal[j];
            int prev_jacob = (j > 1) ? jacobsthal[j-1] : 1;            
            // Insert elements from current_jacob down to prev_jacob + 1
            for (int pos = std::min(current_jacob, static_cast<int>(ordered_pairs.size())); pos > prev_jacob; --pos) 
            {
                int idx = pos - 1; // Convert to 0-based index
                if (idx < static_cast<int>(ordered_pairs.size()) && !inserted[idx]) 
                {
                    int element_to_insert = ordered_pairs[idx].smaller;
                    int corresponding_larger = ordered_pairs[idx].larger;
                    
                    // Find position of corresponding larger element
                    int larger_pos = -1;
                    for (size_t k = 0; k < main_chain.size(); ++k) 
                    {
                        if (main_chain[k] == corresponding_larger) 
                        {
                            larger_pos = k;
                            break;
                        }
                    }                    
                    // Insert using binary search up to the larger element's position
                    int insert_pos = findInsertPosition(main_chain, element_to_insert, larger_pos - 1);
                    main_chain.insert(main_chain.begin() + insert_pos, element_to_insert);
                    inserted[idx] = true;
                }
            }
        }        
        // Insert any remaining elements. Flag = false.
        for (size_t i = 1; i < ordered_pairs.size(); ++i)
        {
            if (!inserted[i])
            {
                int element_to_insert = ordered_pairs[i].smaller;
                int corresponding_larger = ordered_pairs[i].larger;
                
                // Find position of corresponding larger element
                int larger_pos = -1;
                for (size_t k = 0; k < main_chain.size(); ++k)
                {
                    if (main_chain[k] == corresponding_larger)
                    {
                        larger_pos = k;
                        break;
                    }
                }
                // Insert using binary search up to the larger element's position
                int insert_pos = findInsertPosition(main_chain, element_to_insert, larger_pos - 1);
                main_chain.insert(main_chain.begin() + insert_pos, element_to_insert);
            }
        }
    }    
    // Step 6: Insert unpaired element if exists
    if (has_unpaired) 
    {
        int insert_pos = findInsertPosition(main_chain, unpaired_element, main_chain.size() - 1);
        main_chain.insert(main_chain.begin() + insert_pos, unpaired_element);
    }    
    return (main_chain);
}

// lIST
// Using list-specific operations instead of vector indexing
// 1) Using list iterators instead of vector indices
// 2) Using lists instead of vectors for any operation linked to sorting except Jabosthal
// 3) Pairs Modified to work with list of sorted larger elements
std::list<int> PmergeMe::fordJohnsonSort(const std::list<int>& input) const 
{
    int n = input.size();
    
    // Base cases
    if (n <= 1) 
    {
        return (input);
    }
    if (n == 2) 
    {
        std::list<int> result = input;
        if (result.front() > result.back()) 
        {            
            int temp = result.front();
            result.pop_front();
            result.push_back(temp);
        }
        return (result);
    }
    // Step 1: Create pairs
    std::vector<ElementPair> pairs;
    int unpaired_element = -1;
    bool has_unpaired = false;    
    std::list<int>::const_iterator it = input.begin();
    while (it != input.end()) 
    {
        std::list<int>::const_iterator next_it = it;
        ++next_it;
        
        if (next_it != input.end()) 
        {
            if (*it <= *next_it) 
            {
                pairs.push_back(ElementPair(*it, *next_it, 0, 0));
            } 
            else 
            {
                pairs.push_back(ElementPair(*next_it, *it, 0, 0));
            }
            ++it;
            ++it; // Move to next pair
        } 
        else 
        {
            // Unpaired element
            unpaired_element = *it;
            has_unpaired = true;
            break;
        }
    }    
    // Step 2: Recursively sort the larger elements
    std::list<int> larger_elements;
    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        larger_elements.push_back(pairs[i].larger);
    }    
    std::list<int> sorted_larger = fordJohnsonSort(larger_elements);    
    // Step 3: Create ordered pairs based on sorted larger elements
    std::vector<ElementPair> ordered_pairs;
    for (std::list<int>::iterator it = sorted_larger.begin(); it != sorted_larger.end(); ++it) 
    {
        // Find the pair that contains this larger element
        for (size_t j = 0; j < pairs.size(); ++j) 
        {
            if (pairs[j].larger == *it) 
            {
                ordered_pairs.push_back(pairs[j]);
                // Mark this pair as used by setting larger to a sentinel value
                pairs[j].larger = -999999;
                break;
            }
        }
    }    
    // Step 4: Build main chain
    std::list<int> main_chain;    
    // Insert first smaller element
    if (!ordered_pairs.empty()) 
    {
        main_chain.push_back(ordered_pairs[0].smaller);
    }    
    // Insert all larger elements in sorted order
    for (std::list<int>::iterator it = sorted_larger.begin(); it != sorted_larger.end(); ++it) 
    {
        main_chain.push_back(*it);
    }    
    // Step 5: Insert remaining smaller elements using Jacobsthal sequence
    if (ordered_pairs.size() > 1) 
    {
        std::vector<bool> inserted(ordered_pairs.size(), false);
        inserted[0] = true; // First element already inserted        
        std::vector<int> jacobsthal = generateJacobsthal(ordered_pairs.size());        
        // Process Jacobsthal numbers
        for (size_t j = 1; j < jacobsthal.size() && jacobsthal[j] <= static_cast<int>(ordered_pairs.size()); ++j)
        {
            int current_jacob = jacobsthal[j];
            int prev_jacob = (j > 1) ? jacobsthal[j-1] : 1;            
            // Insert elements from current_jacob down to prev_jacob + 1
            for (int pos = std::min(current_jacob, static_cast<int>(ordered_pairs.size())); pos > prev_jacob; --pos) 
            {
                int idx = pos - 1; // Convert to 0-based index                
                if (idx < static_cast<int>(ordered_pairs.size()) && !inserted[idx]) 
                {
                    int element_to_insert = ordered_pairs[idx].smaller;
                    int corresponding_larger = ordered_pairs[idx].larger;                    
                    // Find position of corresponding larger element
                    int larger_pos = -1;
                    int current_pos = 0;
                    for (std::list<int>::iterator it = main_chain.begin(); it != main_chain.end(); ++it, ++current_pos) 
                    {
                        if (*it == corresponding_larger) 
                        {
                            larger_pos = current_pos;
                            break;
                        }
                    }                    
                    // Insert using binary search up to the larger element's position
                    std::list<int>::iterator insert_pos = findInsertPosition(main_chain, element_to_insert, larger_pos - 1);
                    main_chain.insert(insert_pos, element_to_insert);
                    inserted[idx] = true;
                }
            }
        }        
        // Insert any remaining elements
        for (size_t i = 1; i < ordered_pairs.size(); ++i)
        {
            if (!inserted[i])
            {
                int element_to_insert = ordered_pairs[i].smaller;
                int corresponding_larger = ordered_pairs[i].larger;                
                // Find position of corresponding larger element
                int larger_pos = -1;
                int current_pos = 0;
                for (std::list<int>::iterator it = main_chain.begin(); it != main_chain.end(); ++it, ++current_pos)
                {
                    if (*it == corresponding_larger)
                    {
                        larger_pos = current_pos;
                        break;
                    }
                }                
                // Insert using binary search up to the larger element's position
                std::list<int>::iterator insert_pos = findInsertPosition(main_chain, element_to_insert, larger_pos - 1);
                main_chain.insert(insert_pos, element_to_insert);
            }
        }
    }    
    // Step 6: Insert unpaired element if exists
    if (has_unpaired) 
    {
        std::list<int>::iterator insert_pos = findInsertPosition(main_chain, unpaired_element, main_chain.size() - 1);
        main_chain.insert(insert_pos, unpaired_element);
    }    
    return (main_chain);
}

// Auxiliar Struct constructor
ElementPair::ElementPair(int s, int l, int s_idx, int l_idx) 
        : smaller(s), larger(l), original_smaller_idx(s_idx), original_larger_idx(l_idx)
{}

// Util functions
bool validateInput(std::string num)
{
	long output = 0;
	for (unsigned int i = 0; i < num.length(); ++i)
	{
		if (!isdigit(num[i]))
		{
			std::cerr 	<< "Error: Invalid input: " << num
						<< " is not a valid/positive integer."
						<< std::endl;
			return (false);
		}
		output *= 10;
		output += num[i] - '0';
		if (output > std::numeric_limits<int>::max())
		{
			std::cerr 	<< "Error: Invalid input: " << num
						<< " is outside integer values."
						<< std::endl;
			return (false);
		}
	}
	return (true);
}

std::vector<int> generateJacobsthal(int n) 
{
    std::vector<int> jacobsthal;
    if (n <= 0)
    {
        return (jacobsthal);
    }    
    jacobsthal.push_back(1);
    if (n <= 1)
    {
        return (jacobsthal);
    }
    jacobsthal.push_back(1);        
    for (int i = 2; jacobsthal.back() < n; ++i) 
    {
        int next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
        jacobsthal.push_back(next);
    }
    return (jacobsthal);
}

// List Utils
std::list<int>::iterator advanceIterator(std::list<int>::iterator it, 
                                        std::list<int>::iterator end, 
                                        int distance) 
{
    for (int i = 0; i < distance && it != end; ++i) 
    {
        ++it;
    }
    return (it);
}

int getDistance(std::list<int>::iterator first, std::list<int>::iterator last) 
{
    int dist = 0;
    while (first != last) 
    {
        ++first;
        ++dist;
    }
    return (dist);
}

// To pause the execution
void 	goNext(std::string msg)
{
    std::cout   << "\033[32m\nNext section:"
				<< "\033[1;4m" << msg << "\033[0m"
                << std::endl;
	getchar();
}

