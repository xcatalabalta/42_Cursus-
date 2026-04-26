/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:58:05 by fcatala-          #+#    #+#             */
/*   Updated: 2023/04/10 13:58:53 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_clean(char **str)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(*str))
		*str[i] = 0;
	free(*str);
	*str = NULL;
	return (NULL);
}
