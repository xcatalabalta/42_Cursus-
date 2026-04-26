/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:59:29 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/23 10:57:04 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

# define LVL_1  "DEBUG"
# define LVL_2  "INFO"
# define LVL_3  "WARNING"
# define LVL_4  "ERROR"
# define NO_LVL "some random 203xWer18***g"

class Harl
{
private:
    void debug();
    void info();
    void warning();
    void error();
public:
    Harl();
    ~Harl();
    int complain(const std::string& level);
    void cry(const std::string& level);
};

#endif