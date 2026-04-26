/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:31:47 by fcatala-          #+#    #+#             */
/*   Updated: 2023/04/10 14:04:34 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexa(long long int input, const char format)
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
	if (num < 0)
		num = 0xffffffff + input + 1;
	while (num > 0)
	{
		if (format == 'X')
			out[i++] = "0123456789ABCDEF"[num % 16];
		else
			out[i++] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	out[i++] = '\0';
	ft_strrev(out);
	i = ft_putstr(out);
	return (i);
}
