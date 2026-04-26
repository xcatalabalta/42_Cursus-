/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 08:05:01 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/20 16:19:33 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP
# ifndef MAX_VEC
#  define MAX_VEC 300
# endif

# include <vector>
# include <algorithm>
# include <iostream>
# include <string>
# include <stdexcept>
# include <limits>
# include <numeric> //adjacent_difference
# include <iomanip>  // setw

class Span
{
	private:
		unsigned int 		m_N;
		std::vector<int> 	m_vec;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &);
		Span &operator=(const Span &);
		~Span();

		//additional constructors
		Span(unsigned int N, const int value);//Constructs the container filled with the value
		Span(const std::vector<int> vec);//Constructs the container filled with the vec
		
		//Required by the subject
		void addNumber(const int num);
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;

		//Ranged filler required by the subject
		void addVector(std::vector<int>::const_iterator init, std::vector<int>::const_iterator end);

		
		//Fillers
		void addVector(const std::vector<int> &vec);
		void appendSpan(const Span &);
		//append from another Span to the end
		//random filler
		//ranged random filler
		//replace
		
		//Additional functions
		unsigned int capacity(void) const;
		unsigned int size(void) const;
		int max() const;
		int min() const;
		void displayValues(void) const;
		void clear(void);
		void displaySorted(void) const;

		// Custom exception
		class NotEnoughElements : public std::exception
		{
			public:
				const char * what() const throw();
		};

};

#endif