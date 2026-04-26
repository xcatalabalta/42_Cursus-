/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:10:18 by fcatala-          #+#    #+#             */
/*   Updated: 2024/01/16 15:37:10 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_wlog(t_rules *rules, int id, char *msg)
{
	pthread_mutex_lock(&(rules->mut_write));
	if (!(rules->dieded))
	{
		printf("%lli\t", ft_timestamp() - rules->start);
		printf("%i", id);
		printf("%s", msg);
	}
	pthread_mutex_unlock(&(rules->mut_write));
	return ;
}

static int	ft_eat(t_philos *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->mut_forks[philo->left_id]));
	ft_wlog(rules, philo->pos, FORKS);
	if (philo->left_id == philo->right_id)
		return (1);
	pthread_mutex_lock(&(rules->mut_forks[philo->right_id]));
	ft_wlog(rules, philo->pos, FORKS);
	pthread_mutex_lock(&(rules->mut_end));
	philo->l_meal = ft_timestamp();
	ft_wlog(rules, philo->pos, EATS);
	pthread_mutex_unlock(&(rules->mut_end));
	ft_usleep(rules->to_eat, rules);
	(philo->n_eat)++;
	pthread_mutex_unlock(&(rules->mut_forks[philo->left_id]));
	pthread_mutex_unlock(&(rules->mut_forks[philo->right_id]));
	return (0);
}

static void	*ft_actions(void *void_philo)
{
	int			i;
	t_philos	*philo;
	t_rules		*rules;

	i = 0;
	philo = (t_philos *)void_philo;
	rules = philo->rules;
	if ((philo->pos - 1) % 2)
		usleep(15000);
	while (!(rules->dieded))
	{
		if (ft_eat(philo))
			break ;
		if (rules->all_ate || philo->n_eat == rules->nb_eat)
			break ;
		ft_wlog(rules, philo->pos, SLEEP);
		ft_usleep(rules->to_sleep, rules);
		ft_wlog(rules, philo->pos, THINK);
		i++;
	}
	return (NULL);
}

static void	ft_monitor(t_rules *r, t_philos *p)
{
	int	i;

	while (!(r->all_ate))
	{
		i = -1;
		while (++i < r->nb_philo && !(r->dieded))
		{
			pthread_mutex_lock(&(r->mut_end));
			if (ft_timediff(p[i].l_meal, ft_timestamp()) > r->to_die)
			{
				ft_wlog(r, i + 1, DIED);
				r->dieded = 1;
			}
			pthread_mutex_unlock(&(r->mut_end));
			usleep(100);
		}
		if (r->dieded)
			break ;
		i = 0;
		while (r->nb_eat != -1 && i < r->nb_philo && p[i].n_eat == r->nb_eat)
			i++;
		if (i == r->nb_philo)
			r->all_ate = 1;
	}
}

int	ft_launch(t_rules *rules)
{
	int			i;
	t_philos	*phi;

	i = 0;
	phi = rules->philos;
	rules->start = ft_timestamp();
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(phi[i].thread_id), NULL, ft_actions, &(phi[i])))
			return (1);
		phi[i].l_meal = ft_timestamp();
		i++;
	}
	ft_monitor(rules, rules->philos);
	i = -1;
	while (++i < rules->nb_philo)
		pthread_join(phi[i].thread_id, NULL);
	i = -1;
	while (++i < rules->nb_philo)
		pthread_mutex_destroy(&(rules->mut_forks[i]));
	pthread_mutex_destroy(&(rules->mut_write));
	return (0);
}
