/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:29:57 by fcatala-          #+#    #+#             */
/*   Updated: 2026/04/26 09:07:53 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (n && j == 0)
	{
		j = j + ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		n--;
		i++;
	}
	return (j);
}
