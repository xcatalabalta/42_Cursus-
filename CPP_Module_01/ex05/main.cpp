/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:38:15 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/16 17:51:18 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (void)
{
    Harl    roboto;

    roboto.complain("fin");
    roboto.complain("DEBUG");
    roboto.complain("INFO");
    roboto.complain("WARNING");
    roboto.complain("ERROR");
    roboto.complain("random");
    return (0);
}