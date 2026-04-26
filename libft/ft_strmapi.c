/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:20:09 by fcatala-          #+#    #+#             */
/*   Updated: 2022/12/18 17:22:42 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
Definition: Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc) resulting
from successive applications of ’f’.

Variables created:
	unsigned int index
		unsigned int to be compatible with the first argument of char(*f)
	char *out
		string to be returnedi

How it works:
	Check the existance of the string 's' and the function 'f';
		if 's' or 'f' is null, ends the function returning NULL;
	Create an empty string alocating the length of 's' + 1 (\0)
	If the allocation fails, returns NULL
	Initialize the index to -1 because I will use preincrement in the loop
	While the input string exists (preincremented index)
		the character of the output string indicated by index =
		the result of the function to be applied where
			The index of the character is de first argument
			The character of the string is the second argument
	Terminate the output string with \0
	Return output string
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*out;

	if (!s || !f)
		return (NULL);
	out = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!out)
		return (NULL);
	index = -1;
	while (s[++index])
		out[index] = f(index, s[index]);
	out[index] = '\0';
	return (out);
}
