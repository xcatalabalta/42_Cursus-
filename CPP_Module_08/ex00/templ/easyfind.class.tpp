/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.class.tpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 08:40:24 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/21 10:25:26 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/easyfind.class.hpp"

template <typename T>
typename T::iterator  easyfind(T &contain, int indx)
{
	typename T::iterator  it = std::find(contain.begin(), contain.end(), indx);

	if (it == contain.end())
	{
		std::cout << "Value " << indx << " not found." << std::endl;
	}
	return (it);
}

