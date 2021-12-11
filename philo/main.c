/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:09:25 by mochegri          #+#    #+#             */
/*   Updated: 2021/12/11 23:37:34 by mochegri         ###   ########.fr       */
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

// memset, printf, malloc, free, write, fork, kill,
// exit, pthread_create, pthread_detach, pthread_join,
// usleep, gettimeofday, waitpid, sem_open, sem_close,
// sem_post, sem_wait, sem_unlink

#include "philo.h"

int	main (int ac, char **av)
{
	t_table		*table;

	table = init_table(ac, av);
	if (!table)
		return (ft_perror());
	if (init_fork(table))
		return (ft_perror());
	if (start_philo(table))
		return (1);
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
	while (++i < table->nbr_of_philo)
		if (pthread_mutex_init(table->forks + i, NULL))
			return (1);
	return (0);
}

int	start_philo(t_table *table)
{
	int			i;
	t_philo		*a_philo;

	i = -1;
	while (++i < table->nbr_of_philo)
	{
		a_philo = table->philo + i;
		a_philo->id = i;
		a_philo->right_fork = *(table->forks + i);
		a_philo->leeft_fork = *(table->forks
				+ ((i + 1) % table->nbr_of_philo));
		a_philo->time_to = table->time_to;
		if (pthread_create(table->thread + i, NULL, &philo, table->philo + i))
			return (1);
	}
	i = -1;
	while (++i < table->nbr_of_philo)
	{
		if (pthread_join(*(table->thread + i), NULL))
			return (1);
	}
	return (0);
}

void	*philo(void *arg)
{
	t_philo	philo;

	philo = *(t_philo *)arg;
	// printf("%d: time_to_eat:%d time_to_sleep:%d\n", ÷philo.id, philo->time_to.eat, philo.time_to_sleep);
	while (1)
	{
		printf("the philo %d sleep\n", philo.id);
		usleep(philo.time_to.sleep);
		pthread_mutex_lock(&philo.right_fork);
		pthread_mutex_lock(&philo.leeft_fork);
		printf("the philo %d eat\n", philo.id);
		usleep(philo.time_to.eat);
		pthread_mutex_unlock(&philo.right_fork);
		pthread_mutex_unlock(&philo.leeft_fork);
	}
	return (NULL);
}
