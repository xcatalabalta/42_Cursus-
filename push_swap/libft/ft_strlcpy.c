/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:15:11 by fcatala-          #+#    #+#             */
/*   Updated: 2023/10/04 09:52:40 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstlen)
{
	size_t	i;

	i = -1;
	if (src)
	{
		if (dstlen != 0)
		{
			while ((++i < ft_strlen(src)) && i < (dstlen - 1))
				dst[i] = src[i];
			dst[i] = '\0';
		}
	}
	return (ft_strlen(src));
}
