/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:00:20 by fcatala-          #+#    #+#             */
/*   Updated: 2023/02/05 17:54:36 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strrev(char *str)
{
	size_t	len;
	size_t	i;
	char	temp;

	len = ft_strlen(str);
	if (len == 0)
		return (NULL);
	i = -1;
	len -= 1;
	while (++i <= len / 2)
	{
		temp = str[len - i];
		str[len - i] = str[i];
		str[i] = temp;
	}
	return (str);
}
