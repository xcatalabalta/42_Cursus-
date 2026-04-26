/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:24:11 by fcatala-          #+#    #+#             */
/*   Updated: 2023/02/06 17:53:20 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_prformat(va_list args, const char format)
{
	int	wout;

	wout = 0;
	if (format == 'c')
		wout += ft_putchar(va_arg(args, int));
	else if (format == 's')
		wout += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		wout += ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		wout += ft_putsigbase(va_arg(args, int), 10);
	else if (format == 'u')
		wout += ft_putunsigbase(va_arg(args, unsigned int), 10);
	else if (format == 'x' || format == 'X')
		wout += ft_puthexa(va_arg(args, int), format);
	else if (format == '%')
		wout += write(1, "%", 1);
	return (wout);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = -1;
	len = 0;
	va_start(args, fmt);
	while (fmt[++i])
	{
		if (fmt[i] == '%')
			len += ft_prformat(args, fmt[++i]);
		else
			len += ft_putchar(fmt[i]);
	}
	va_end(args);
	return (len);
}
