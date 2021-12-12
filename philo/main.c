/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:09:25 by mochegri          #+#    #+#             */
/*   Updated: 2021/12/12 19:23:21 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  thread 
//  mutex
//  fzombie proces
// deadlock

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

// memset, printf, malloc, free, write,exit
// fork, kill, pthread_create, pthread_detach, pthread_join,
// usleep, gettimeofday, waitpid, sem_open, sem_close,
// sem_post, sem_wait, sem_unlink

#include "philo.h"

int	main(int ac, char **av)
{
	t_table		*table;

	table = init_table(ac, av);
	if (!table)
		return (ft_perror());
	if (init_fork(table))
		return (ft_perror());
	if (start_philo(table))
		return (1);
	ft_free(table);
	return (0);
}

t_table	*init_table(int ac, char **av)
{
	t_table	*table;

	if (ac < 5 || ac > 6)
		return (NULL);
	table = (t_table *)malloc(sizeof(t_table));
	table->nbr_of_philo = ft_atoi(*(av + 1));
	table->time_to.die = ft_atoi(*(av + 2)) * 1000;
	table->time_to.eat = ft_atoi(*(av + 3)) * 1000;
	table->time_to.sleep = ft_atoi(*(av + 4)) * 1000;
	if (*(av + 5))
		table->nbr_of_meals = ft_atoi(*(av + 5));
	else
		table->nbr_of_meals = 0;
	if (table->nbr_of_philo < 0 || table->time_to.die < 0
		|| table->time_to.eat < 0 || table->time_to.sleep < 0
		|| table->nbr_of_meals < 0)
		return (NULL);
	table->thread = (pthread_t *)malloc(sizeof(pthread_t)
			* table->nbr_of_philo);
	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->nbr_of_philo);
	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->nbr_of_philo);
	return (table);
}

int	init_fork(t_table *table)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&(table->printing), NULL))
		return (1);
	while (++i < table->nbr_of_philo)
		if (pthread_mutex_init(table->forks + i, NULL))
			return (1);
	return (0);
}

void	printing(int time, int id, char *msg, pthread_mutex_t *mutex)
{
	pthread_mutex_unlock(mutex);
	printf("%d %d %s\n", time, id, msg);
	pthread_mutex_unlock(mutex);
}

void	ft_free(t_table *table)
{
	free(table->thread);
	free(table->forks);
	free(table->philo);
	free(table);
}
