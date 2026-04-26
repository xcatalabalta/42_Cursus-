/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:06:43 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/16 18:04:52 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug()
{
    std::cout   << "I love having extra sauce for my " 
                << "papas-bravas. I really do!" << std::endl;
    return ;
}

void Harl::info()
{
    std::cout   << "I cannot believe adding extra sauce costs more money. "
                << "You didn’t put enough sauce! "
                << "If you did, I wouldn’t be asking for more!" << std::endl;
    return ;
}

void Harl::warning()
{
    std::cout   << "I think I deserve to have some extra sauce for free. "
                << "I’ve been coming for years, you bloody newbie." << std::endl;
    return ;
}

void Harl::error()
{
    std::cout   << "This is unacceptable! "
                << "I want to speak to the manager now." << std::endl;
    return ;
}

void Harl::complain(std::string level)
{
    const std::string   levels[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    void (Harl::*action[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    int a = 0;

    for (;a < 4; a++)
    {
        if (level == levels[a])
        {
            (this->*action[a])();
            return ;
        }
    }
    std::cout << "\033[1;31mI don't have anything to say to you\033[0m" << std::endl;
    return ;
}