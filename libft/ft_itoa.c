/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:33:23 by fcatala-          #+#    #+#             */
/*   Updated: 2022/12/11 13:08:03 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits(long int n)
{
	int			digit;
	long int	c;

	c = n;
	digit = 0;
	if (c < 0)
		c = -c;
	if (c == 0)
		return (1);
	while (c >= 1)
	{
		c = c / 10;
		digit++;
	}
	if (n < 0)
		digit++;
	return (digit);
}

char	*ft_itoa(int n)
{
	char		*out;
	long int	c;
	int			i;
	int			end;

	c = n;
	i = ft_digits(c);
	out = (char *)malloc((i + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = ft_digits(n);
	end = -1;
	if (c < 0)
	{
		out[0] = '-';
		c = -c;
		end++;
	}
	while (--i > end)
	{
		out[i] = (c % 10) + '0';
		c = c / 10;
	}
	out[ft_digits(n)] = '\0';
	return (out);
}
