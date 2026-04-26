/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:11:19 by fcatala-          #+#    #+#             */
/*   Updated: 2026/04/26 09:02:17 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
 * It looks if the chars contained in "set" can be found in the string
 * It checks char by char until getting a difference
 * Probably I could use strchr and strrchr to move the pointer but...
 */
static int	ft_trim_ok(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
 * It gets the size of the trimmed string (if possible)
 * It also checks the trimability of the string backwards.
 * It skips the null terminated
 */

static int	ft_get_size(char const *s1, char const *set)
{
	int		i;
	int		size;

	size = ft_strlen(s1);
	i = 0;
	while (ft_trim_ok(s1[size - i - 1], set))
		i++;
	return (size - i);
}
/*
 * Checks existence of "s1" and existence of "set"
 * If "set" does not exist, returns a full copy of "s1" using "strdup"
 * (everything is trimmed)
 * Checks the size of the trim, if it is = to the length of "s1"
 * it returns an empty string using "strdup"
 * It books the trimable size + 1 for the null ending
 * Malloc preventing allocation error
 * Copy to out the characters of "s1" from occurency of "set"
 * until the end delimited by the possible size.
 * Using "strlcpy" we get the string null terminated 
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		size;
	char	*out;

	i = 0;
	size = 0;
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	while (ft_trim_ok(s1[i], set))
		i++;
	if (i == (int)ft_strlen(s1))
		return (ft_strdup(""));
	size = ft_get_size(s1 + i, set) + 1;
	out = (char *)malloc(sizeof(char) * size);
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1 + i, size);
	return (out);
}
