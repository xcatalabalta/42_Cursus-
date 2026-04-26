/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:42:26 by fcatala-          #+#    #+#             */
/*   Updated: 2023/10/05 11:23:26 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Basic checks
 * ft_chck_sorted: condition inside 'if' acts recursevely
*/
#include "libpush_swap.h"

static int	ft_chck_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		++i;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while ((*str == 32) || ((*str >= 9) && (*str <= 13)))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		num = 10 * num + (*str - 48);
		str++;
	}
	return (sign * num);
}

static int	ft_chck_rep(int aux, char **tmp, int i)
{
	i++;
	while (tmp[i])
	{
		if (ft_atoi(tmp[i]) == aux)
			return (1);
		++i;
	}
	return (0);
}

void	ft_chck_args(int argc, char **argv)
{
	int		i;
	long	aux;
	char	**tmp;

	i = 0;
	if (argc == 2)
		tmp = ft_split(argv[1], 32);
	else
	{
		i++;
		tmp = argv;
	}
	while (tmp[i])
	{
		aux = ft_atol(tmp[i]);
		if (!ft_chck_num(tmp[i]) || aux < -2147483648 || aux > 2147483647)
			ft_error(ERR);
		if (ft_chck_rep (aux, tmp, i))
			ft_error(ERR);
		i++;
	}
}

int	ft_chck_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
