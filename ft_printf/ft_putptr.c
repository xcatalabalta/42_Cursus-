/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:39:44 by fcatala-          #+#    #+#             */
/*   Updated: 2023/02/07 15:52:17 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putptr(void	*ptr)
{
	unsigned long long int	num;
	int						i;
	char					out[32];

	if (!ptr)
	{
		i = ft_putstr("0x0");
		return (i);
	}
	num = (unsigned long long)ptr;
	i = 0;
	while (num > 0)
	{
		out[i++] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	out[i++] = 'x';
	out[i++] = '0';
	out[i++] = '\0';
	ft_strrev(out);
	i = ft_putstr(out);
	return (i);
}
