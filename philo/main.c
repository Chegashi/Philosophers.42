/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:09:25 by mochegri          #+#    #+#             */
/*   Updated: 2021/12/14 19:21:33 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  thread 
//  mutex
//  fzombie proces
// deadlock

// memset, printf, malloc, free, write,
// ft_usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

// memset, printf, malloc, free, write,exit
// fork, kill, pthread_create, pthread_detach, pthread_join,
// ft_usleep, gettimeofday, waitpid, sem_open, sem_close,
// sem_post, sem_wait, sem_unlink

#include "philo.h"

int	checker(t_table *table)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < table->nbr_of_philo)
		{
			if (get_time() - table->philo[i].time_of_last_meals
				> table->time_to.die)
			{
				printing(get_time() - table->philo[i].starting_time,
					table->philo[i].id, "died", table->philo[i].printing);
				return (1);
			}
		}
	}
}

int	main(int ac, char **av)
{
	t_table		*table;
	int			i;
	int			a_philo_is_die;

	a_philo_is_die = 0;
	table = init_table(ac, av, &a_philo_is_die);
	if (!table)
		return (ft_perror());
	if (init_fork(table))
		return (ft_perror());
	i = 0;
	while (i < table->nbr_of_philo)
	{
		init_philo(table->philo + i, i, table);
		i += 2;
	}
	ft_usleep (50);
	i = 1;
	while (i < table->nbr_of_philo)
	{
		init_philo(table->philo + i, i, table);
		 i += 2;
	}
	if (checker(table))
	{
		ft_free (table);
		return (0);
	}
	i = -1;
	while (++i < table->nbr_of_philo)
	{
		if (pthread_join(*(table->thread + i), (void *)&a_philo_is_die))
			return (1);
	}
	return (0);
}

void	printing(double time, int id, char *msg, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	printf("%.0lf %d %s\n", time, id + 1, msg);
	if (*msg != 'd')
		pthread_mutex_unlock(mutex);
}

void	ft_free(t_table *table)
{
	free(table->thread);
	free(table->forks);
	free(table->philo);
	free(table);
}

void	ft_usleep(int i)
{
	double	time;

	time = get_time();
	usleep(i * (80 / 100));
	while (get_time() > time + i / 1000)
		;
	return ;
}
