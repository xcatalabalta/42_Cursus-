/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:05:51 by fcatala-          #+#    #+#             */
/*   Updated: 2024/10/30 14:41:33 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main (void)
{
    std::string brain =  "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << "Memory address of the string variable:\t" << &brain << std::endl;
    std::cout << "Memory address held by stringPTR:\t" << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF:\t" << &stringREF << std::endl;
    
    std::cout << std::endl << "Value of the string variable:\t" << brain << std::endl;
    std::cout << "Value pointed by stringPTR:\t" << *stringPTR << std::endl;
    std::cout << "Value pointed by stringREF:\t" << stringREF << std::endl;
    return (0);
}