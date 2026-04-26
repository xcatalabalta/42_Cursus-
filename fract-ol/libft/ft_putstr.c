/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:03:26 by fcatala-          #+#    #+#             */
/*   Updated: 2023/04/10 14:06:12 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	out;

	out = 0;
	if (!s)
	{
		out = write(1, "(null)", 6);
		return (out);
	}
	out = write(1, s, ft_strlen(s) * sizeof(*s));
	return (out);
}
