/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:38:15 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/23 13:42:06 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>

static void ft_strtoupper(std::string *str)
{
	for (size_t i = 0; i < str->size(); i++)
	{
		(*str)[i] = static_cast<char>(std::toupper((*str)[i]));
	}
	return ;
}

static int ft_findLevel(const std::string *list, const std::string tocheck, bool check)
{
    std::string level;

    level = tocheck;
    if (check)
        ft_strtoupper(&level);
    for (int a = 0;a < 4; a++)
    {
        if (level == list[a])
        {
            return (a +1);
        }
    }
    return (0);
}

int main (int argc, char **argv)
{
    Harl    roboto;
    int     level = 0;
    const std::string   levels[4] = 
    {
        LVL_1,
        LVL_2,
        LVL_3,
        LVL_4
    };

    if (argc != 2)
    {
        std::cout   << "You know? TOO MUCH NOISE GIVES MIGRAINE. But, " 
                    << "silence is sooo boring." 
                    << std::endl;
        return (0);
    }
    level = ft_findLevel(levels, argv[1], false);
    switch (level)
    {
    case 1 :
        roboto.cry(LVL_1);
    case 2 :
        roboto.cry(LVL_2);
    case 3 :
        roboto.cry(LVL_3);
    case 4 :
        roboto.cry(LVL_4);
        break;
    default :
        roboto.cry(NO_LVL);
        break;
    }
    if (level == 0 && ft_findLevel(levels, argv[1], true))
    {
        std::cout   << "Try entering '" << argv[1] <<"' in CAPITAL LETTERS:" 
                    << std::endl;
    }
 /*
    std::cout   << std::endl 
                << "\033[1;32mInteraction with \"for\" loop\033[0m" 
                << std::endl;
    roboto.complain(argv[1]);
 */
    return (0);
}