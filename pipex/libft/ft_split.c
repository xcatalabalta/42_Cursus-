/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:22:28 by fcatala-          #+#    #+#             */
/*   Updated: 2023/10/04 09:48:58 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s1, char set)
{
	int	words;

	words = 0;
	while (*s1)
	{
		if ((*s1 != set) && *s1)
		{
			while ((*s1 != set) && *s1)
			{
				s1++;
			}
			words++;
			s1--;
		}
		s1++;
	}
	return (words);
}

static void	*clean(char **list, size_t len)
{
	while (len--)
		free(list[len]);
	free(list);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		w;
	int		i;
	int		ini;

	if (!s)
		return (NULL);
	out = malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	w = -1;
	i = 0;
	while (++w < ft_words(s, c) && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		ini = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		out[w] = ft_substr(s, ini, i - ini);
		if (out[w] == NULL)
			return (clean(out, w));
	}
	out[w] = NULL;
	return (out);
}
