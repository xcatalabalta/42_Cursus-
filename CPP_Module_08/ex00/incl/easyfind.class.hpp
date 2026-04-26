/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 08:33:04 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/21 11:10:56 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_CLASS_HPP
# define EASYFIND_CLASS_HPP

// headers for search
#include <algorithm>
#include <deque>
#include <list>
#include <set>
#include <vector>
#include <iostream>


template <typename T>
typename T::iterator  easyfind(T &contain, int indx);

#include "../templ/easyfind.class.tpp"
#endif

