/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_mgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:12:32 by fcatala-          #+#    #+#             */
/*   Updated: 2024/01/16 16:18:05 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	ft_timediff(long long past, long long pres)
{
	return (pres - past);
}

void	ft_usleep(long long time, t_rules *rules)
{
	long long	i;

	i = ft_timestamp();
	while (!(rules->dieded))
	{
		if (ft_timediff(i, ft_timestamp()) > time)
			break ;
		usleep(10);
	}
}
