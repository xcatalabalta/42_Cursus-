/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:28:48 by fcatala-          #+#    #+#             */
/*   Updated: 2023/06/06 07:26:04 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		while (*s && (*s != (unsigned char)c))
			s++;
		if (*s == (unsigned char)c)
			return ((char *)s);
	}
	return (NULL);
}
