/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigbase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:18:32 by fcatala-          #+#    #+#             */
/*   Updated: 2023/02/07 15:44:13 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putunsigbase(unsigned int input, int base)
{
	long long int	num;
	int				i;
	char			out[32];

	if (input == 0)
	{
		ft_putchar('0');
		return (1);
	}
	num = input;
	i = 0;
	while (num > 0)
	{
		out[i++] = "0123456789abcdef"[num % base];
		num /= base;
	}
	out[i++] = '\0';
	ft_strrev(out);
	i = ft_putstr(out);
	return (i);
}
