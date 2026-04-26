/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:27:33 by fcatala-          #+#    #+#             */
/*   Updated: 2023/04/10 12:49:41 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		while (*s && (*s != (unsigned char)(c)))
			s++;
		if (*s == (unsigned char)(c))
			return ((char *)s);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		ptr = malloc(sizeof(char) * 1);
	else
		ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	if (start >= ft_strlen(s))
		ptr[0] = '\0';
	else
	{
		while ((start < ft_strlen(s)) && (i < len) && s[start])
			ptr[i++] = s[start++];
		ptr[len] = '\0';
	}
	return (ptr);
}

char	*ft_strjoin(const char *s1, const char *s2)
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
