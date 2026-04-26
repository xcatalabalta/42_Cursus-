/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:28:48 by fcatala-          #+#    #+#             */
/*   Updated: 2022/11/10 18:06:21 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)

{
	int				len;
	unsigned char	uc;
	char			*aux;

	len = ft_strlen(s);
	uc = (unsigned char) c;
	aux = (char *)s;
	if (uc == 0)
	{
		aux = aux + len;
		return (aux);
	}
	while (*aux && (*aux != uc))
		aux++;
	if (*aux == uc)
		return (aux);
	return (NULL);
}
