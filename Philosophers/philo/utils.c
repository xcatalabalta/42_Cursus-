/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:07:35 by fcatala-          #+#    #+#             */
/*   Updated: 2024/01/03 12:31:12 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	out;

	sign = 1;
	out = 0;
	if (!str)
		return (0);
	while (*str <= 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		out = out * 10 + (*str - '0');
		str++;
	}
	return (out * sign);
}

int	ft_werror(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, str, len);
	return (1);
}

int	ft_error_check(int error)
{
	if (error == 1)
		return (ft_werror(MSG_4));
	if (error == 2)
		return (ft_werror(MSG_1));
	return (1);
}
