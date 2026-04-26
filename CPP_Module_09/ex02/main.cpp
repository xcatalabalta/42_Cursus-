/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:15:24 by fcatala-          #+#    #+#             */
/*   Updated: 2025/07/14 18:56:16 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/PmergeMe.class.hpp"

int main (int argc, char **argv)
{
	if (argc > 1)
	{
		try 
		{
			PmergeMe sorter;
			sorter.fillContainer(argc, argv);
    		sorter.execute();
			std::cout 	<< "Happy End!"
						<< std::endl;
		}
		catch (const std::exception &e)
		{
			return (0);
		}
	}
	else
	{
		std::cout 	<< "Please provide arguments"
					<< std::endl;
		return (0);
	}
	return (0);
}