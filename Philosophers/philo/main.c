/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:11:19 by fcatala-          #+#    #+#             */
/*   Updated: 2024/01/16 15:01:07 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j] >= 48 && argv[i][j] <= 57)
			++j;
		if (argv[i][j])
			return (1);
	}
	if ((argv[5] && ft_atoi(argv[5]) == 0) || ft_atoi(argv[1]) == 0)
		return (1);
	return (0);
}

static int	ft_init_philmut(t_rules *rules)
{
	int	i;

	i = rules->nb_philo;
	while (--i >= 0)
	{
		rules->philos[i].pos = i + 1;
		rules->philos[i].n_eat = 0;
		rules->philos[i].left_id = i;
		rules->philos[i].right_id = (i + 1) % rules->nb_philo;
		rules->philos[i].l_meal = 0;
		rules->philos[i].rules = rules;
		if (pthread_mutex_init(&(rules->mut_forks[i]), NULL))
			return (2);
	}
	if (pthread_mutex_init(&(rules->mut_write), NULL))
		return (2);
	if (pthread_mutex_init(&(rules->mut_end), NULL))
		return (2);
	return (0);
}

static int	ft_init_all(t_rules *rules, char **argv)
{
	rules->nb_philo = ft_atoi(argv[1]);
	rules->to_die = ft_atoi(argv[2]);
	rules->to_eat = ft_atoi(argv[3]);
	rules->to_sleep = ft_atoi(argv[4]);
	rules->all_ate = 0;
	rules->dieded = 0;
	if (rules->nb_philo > 250)
		return (1);
	if (argv[5])
		rules->nb_eat = ft_atoi(argv[5]);
	else
		rules->nb_eat = -1;
	return (ft_init_philmut(rules));
}

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc < 5 || argc > 6 || ft_check(argv))
		return (ft_werror(MSG_0));
	if (ft_init_all(&rules, argv))
		return (ft_error_check(ft_init_all(&rules, argv)));
	if (ft_launch(&rules))
		return (ft_werror(MSG_3));
	return (0);
}
