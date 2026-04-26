/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:45:27 by fcatala-          #+#    #+#             */
/*   Updated: 2023/02/06 15:43:02 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(char c);
size_t	ft_strlen(const char *str);
char	*ft_strrev(char *str);
int		ft_putstr(char *s);
int		ft_puthexa(long long int input, const char format);
int		ft_putptr(void *ptr);
int		ft_putsigbase(int input, int base);
int		ft_putunsigbase(unsigned int input, int base);
int		ft_printf(const char *fmt, ...);
#endif
