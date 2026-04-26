/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:18:42 by fcatala-          #+#    #+#             */
/*   Updated: 2023/10/21 12:32:44 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_char(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

char	*ft_strlow(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isalpha(str[i]))
		{
			if ((str[i] >= 65) && (str[i] <= 90))
				str[i] += 32;
		}
	}
	return (str);
}

double	ft_atod(const char *str)
{
	double	integ;
	double	decim;
	char	*c;
	int		len;

	c = (char *)str;
	integ = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	decim = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		decim /= 10;
	if (integ > 0)
		return (integ + decim);
	else
		return (integ - decim);
}
