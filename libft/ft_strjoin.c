/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:13:19 by fcatala-          #+#    #+#             */
/*   Updated: 2026/04/26 09:17:11 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*o;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	o = malloc(sizeof(*s1) * ft_strlen(s1) + sizeof(*s2) * (ft_strlen(s2) + 1));
	if (!o)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		o[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		o[i] = s2[j];
		i++;
		j++;
	}
	o[i] = '\0';
	return (o);
}
