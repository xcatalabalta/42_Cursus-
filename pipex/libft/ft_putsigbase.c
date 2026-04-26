/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsigbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:03:15 by fcatala-          #+#    #+#             */
/*   Updated: 2023/04/10 14:05:49 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putsigbase(int input, int base)
{
	long int	num;
	int			i;
	char		out[32];

	if (input == 0)
	{
		ft_putchar('0');
		return (1);
	}
	num = input;
	i = 0;
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		out[i++] = "0123456789abcdef"[num % base];
		num /= base;
	}
	if (input < 0)
		out[i++] = '-';
	out[i++] = '\0';
	ft_strrev(out);
	i = ft_putstr(out);
	return (i);
}
