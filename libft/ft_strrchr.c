/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:22:00 by fcatala-          #+#    #+#             */
/*   Updated: 2022/11/10 18:07:21 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stddio.h>

char	*ft_strrchr(const char *s, int c)

{
	int				len;
	unsigned char	uc;
	char			*aux;

	len = ft_strlen(s);
	uc = (unsigned char) c;
	aux = (char *)s + len - 1;
	if (uc == 0)
	{
		aux++;
		return (aux);
	}
	while (len != 0)
	{
		if (*aux == uc)
			return (aux);
		aux--;
		len--;
	}
	return (NULL);
}
