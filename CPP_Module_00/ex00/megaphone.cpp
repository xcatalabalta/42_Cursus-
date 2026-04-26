/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:45:29 by fcatala-          #+#    #+#             */
/*   Updated: 2024/10/16 18:17:40 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void ft_putupstr (std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		std::cout << (char)std::toupper(str[i]);
	}
	return;
}

int	main (int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int arg = 1; arg < argc; arg++)
		{
			ft_putupstr(argv[arg]);
		}
		std::cout << std::endl;
	}
	return (0);
}
