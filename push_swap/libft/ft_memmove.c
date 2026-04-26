/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:48:50 by fcatala-          #+#    #+#             */
/*   Updated: 2023/10/04 09:48:02 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src2;
	unsigned char	*dst2;

	if (!len || (dst == src))
		return (dst);
	if (src > dst)
		return (ft_memcpy(dst, src, len));
	src2 = (unsigned char *) src;
	dst2 = (unsigned char *) dst;
	while (len--)
		dst2[len] = src2[len];
	return (dst);
}
