/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:13:19 by fcatala-          #+#    #+#             */
/*   Updated: 2023/10/04 09:50:39 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s1)
		s1 = "\0";
	if (!s2)
		s2 = "\0";
	out = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!out)
		return (NULL);
	while (s1[++i])
		out[i] = s1[i];
	while (s2[++j])
		out[i++] = s2[j];
	out[i] = '\0';
	return (out);
}
/*The oldie one
{
	char	*out;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	out = malloc(sizeof(char) * (ft_strlen(s1) + (ft_strlen(s2) + 1)));
	if (!out || (!s1 && !s2))
		return (NULL);
	if (!s1)
		ft_strlcpy(out, s2, ft_strlen(s2));
	else if (!s2)
		ft_strlcpy(out, s1, ft_strlen(s1));
	else
	{
		while (++i < ft_strlen(s1))
			out[i] = s1[i];
		while (++j < ft_strlen(s2))
		{
			out[i] = s2[j];
			i++;
		}
		out[i] = '\0';
	}
	return (out);
}
*/
