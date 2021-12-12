/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:11:10 by mochegri          #+#    #+#             */
/*   Updated: 2021/12/12 23:52:15 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		a_philo->printing = &(table->printing);
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
	t_philo			philo;

	philo = *(t_philo *)arg;
	philo.time_of_last_meals = get_time();
	printing(philo.time_of_last_meals, philo.id,
		"is thinking", philo.printing);
	while (1)
	{
		if (eating(&philo))
			break ;
		if (sleeping(&philo))
			break ;
	}
	printing(philo.time_of_last_meals, philo.id,
		"died", philo.printing);
	return (NULL);
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork));
	// printf("diff e : %d , %d, %d\n", current_time_ms, philo->time_of_last_meals, philo->time_to.die);
	if (get_time() - philo->time_of_last_meals > philo->time_to.die)
	{
		pthread_mutex_unlock(&(philo->right_fork));
		return (1);
	}
	printing(get_time(), philo->id, "has taken a fork", philo->printing);
	pthread_mutex_lock(&(philo->leeft_fork));
	if (get_time() - philo->time_of_last_meals > philo->time_to.die)
	{
		pthread_mutex_unlock(&(philo->leeft_fork));
		return (1);
	}
	printing(get_time(), philo->id, "has taken a fork", philo->printing);
	printing(get_time(), philo->id, "is eating", philo->printing);
	usleep(philo->time_to.eat * 1000);
	philo->time_of_last_meals = get_time();
	pthread_mutex_unlock(&(philo->right_fork));
	pthread_mutex_unlock(&(philo->leeft_fork));
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (get_time() - philo->time_of_last_meals > philo->time_to.die)
	{
		printf("current_time_ms: %f\tphilo->time_of_last_meals: %f\n", get_time(), philo->time_of_last_meals);
		return (1);
	}
	printing(get_time(), philo->id, "is sleeping", philo->printing);
	usleep(philo->time_to.sleep * 1000);
	// printf("diff s: %d\n", current_time_ms - philo->time_of_last_meals > philo->time_to.die);

	return (0);
}
