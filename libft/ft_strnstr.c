/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:19:17 by fcatala-          #+#    #+#             */
/*   Updated: 2026/04/26 09:03:20 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t n)
{
	char	*auxh;
	size_t	i;
	int		j;

	i = ft_strlen(hay);
	auxh = (char *)hay;
	if (ft_strlen(need) == 0)
		return (auxh);
	if ((n == 0) || (n < ft_strlen(need)))
		return (NULL);
	auxh = ft_strchr(auxh, need[0]);
	while (auxh)
	{
		if (n < (i - ft_strlen(auxh) + ft_strlen(need)))
			return (NULL);
		j = ft_strncmp(auxh, need, ft_strlen(need));
		if (j == 0)
			return (auxh);
		auxh++;
		auxh = ft_strchr(auxh, need[0]);
	}
	return (NULL);
}
