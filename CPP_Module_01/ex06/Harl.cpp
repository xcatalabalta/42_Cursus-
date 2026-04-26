/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:06:43 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/23 10:09:18 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug()
{
    std::cout   << "[ " << LVL_1 << " ]" << std::endl 
                << "I love having extra sauce for my " 
                << "papas-bravas. I really do!" << std::endl;
    return ;
}

void Harl::info()
{
    std::cout   << "[ " << LVL_2 << " ]" << std::endl 
                << "I cannot believe adding extra sauce costs more money. "
                << "You didn’t put enough sauce! "
                << "If you did, I wouldn’t be asking for more!" << std::endl;
    return ;
}

void Harl::warning()
{
    std::cout   << "[ " << LVL_3 << " ]" << std::endl
                << "I think I deserve to have some extra sauce for free. "
                << "I’ve been coming for years, you bloody newbie." << std::endl;
    return ;
}

void Harl::error()
{
    std::cout   << "[ " << LVL_4 << " ]"<< std::endl
                << "This is unacceptable! "
                << "I want to speak to the manager now." << std::endl;
    return ;
}

int Harl::complain(const std::string& level)
{
    const std::string   levels[4] = {
        LVL_1,
        LVL_2,
        LVL_3,
        LVL_4
    };
    void (Harl::*action[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    int     a = 0;
    int     output = 0;
    bool    found = false;

    for (;a < 4; a++)
    {
        if (level == levels[a])
        {
            output = a + 1;
            for (;a < 4; a++)
            {
                (this->*action[a])();
            }
            found = true;
        }
    }
    if (!found)
    {
        std::cout   << "\033[1;31m[BLAH BLAH]" << std::endl
                    << "I don't have anything to say to you.\033[0m" << std::endl;
    }
    return (output);
}

void Harl::cry(const std::string& level)
{
    const std::string   levels[4] = 
    {
        LVL_1,
        LVL_2,
        LVL_3,
        LVL_4
    };
    void (Harl::*action[4])() = 
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    int     a = 0;

    for (;a < 4; a++)
    {
        if (level == levels[a])
        {
            (this->*action[a])();
            return ;
        }
    }
    std::cout   << "\033[1;31m[BLAH BLAH]" << std::endl
                << "I don't have anything to say to you.\033[0m" << std::endl;
    return ;
}