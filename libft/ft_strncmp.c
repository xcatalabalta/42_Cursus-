/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:13:54 by fcatala-          #+#    #+#             */
/*   Updated: 2022/11/15 20:25:41 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*aux1;
	unsigned char	*aux2;
	int				i;
	size_t			k;

	aux1 = (unsigned char *) s1;
	aux2 = (unsigned char *) s2;
	i = 0;
	k = 0;
	while ((k < n) && (i == 0) && (aux1[k] || aux2[k]))
	{
		i = aux1[k] - aux2[k];
		k++;
	}
	return (i);
}
