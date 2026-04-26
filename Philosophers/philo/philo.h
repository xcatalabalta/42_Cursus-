/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:47:16 by fcatala-          #+#    #+#             */
/*   Updated: 2024/01/16 15:53:29 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

# define MSG_0 "Error: Provide valid arguments\n"
# define MSG_1 "Error: Allocation of mutex forks failed\n"
# define MSG_2 "Error: Allocation failed creating philos or forks\n"
# define MSG_3 "Error: Create / join failed\n"
# define MSG_4 "Error: Maximum number of philosohers is 250\n"
# define FORKS "\thas taken a fork\n"
# define EATS "\tis eating\n"
# define SLEEP "\tis sleeping\n"
# define THINK "\tis thinking\n"
# define DIED "\tdied\n"

struct	s_rules;

typedef struct s_philos
{
	int					pos;
	int					n_eat;
	int					left_id;
	int					right_id;
	long long			l_meal;
	struct s_rules		*rules;
	pthread_t			thread_id;
}						t_philos;

typedef struct s_rules
{
	int					nb_philo;
	int					to_die;
	int					to_eat;
	int					to_sleep;
	int					nb_eat;
	int					dieded;
	int					all_ate;
	long long			start;
	pthread_mutex_t		mut_end;
	pthread_mutex_t		mut_forks[250];
	pthread_mutex_t		mut_write;
	t_philos			philos[250];
}						t_rules;

int						ft_werror(char *str);
int						ft_error_check(int error);
int						ft_atoi(char *str);
long long				ft_timestamp(void);
long long				ft_timediff(long long past, long long pres);
void					ft_usleep(long long time, t_rules *rules);
int						ft_launch(t_rules *rules);
#endif
