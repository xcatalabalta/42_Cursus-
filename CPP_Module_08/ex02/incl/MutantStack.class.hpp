/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:33:23 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/22 05:55:35 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_CLASS_HPP
# define MUTANTSTACK_CLASS_HPP

# include <stack>
# include <deque>
# include <list>//used in the main
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		// Orthodox Class Elements
		MutantStack();
		MutantStack(MutantStack const &other);
		MutantStack(const std::stack<T>& other);//Not required by the subject
		MutantStack &operator=(MutantStack const &other);
		~MutantStack();

		// Definition of the types of iterators const forward and reverse
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		// Overrides begin() end() forward & reverse
		iterator begin();
		iterator end();

		const_iterator begin() const;
		const_iterator end() const;

		reverse_iterator rbegin();
		reverse_iterator rend();

		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;

};
# include "../templ/MutantStack.class.tpp"

#endif