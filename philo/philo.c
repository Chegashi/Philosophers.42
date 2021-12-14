/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:11:10 by mochegri          #+#    #+#             */
/*   Updated: 2021/12/14 19:19:04 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *a_philo, int i, t_table *table)
{
	a_philo->id = i;
	a_philo->n = table->nbr_of_philo;
	a_philo->right_fork = table->forks + i;
	a_philo->leeft_fork = table->forks + ((i + 1) % table->nbr_of_philo);
	a_philo->time_to = table->time_to;
	a_philo->printing = table->printing;
	a_philo->a_philo_is_die = table->a_philo_is_die;
	a_philo->nbr_of_meals = table->nbr_of_meals;
	a_philo->starting_time = get_time();
	a_philo->time_of_last_meals = get_time();
	pthread_create(table->thread + i, 0, philo, table->philo + i);
}

void	*philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_usleep (10);
	// printf("init: %÷lf\n", philo->time_of_last_meals);

	while (philo->nbr_of_meals)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

int	thinking(t_philo *philo)
{
	printing(get_time() - philo->starting_time, philo->id, "is thinking",
		philo->printing);
	return (0);
}

int	sleeping(t_philo *philo)
{
	printing(get_time() - philo->starting_time, philo->id, "is sleeping",
		philo->printing);
	ft_usleep(philo->time_to.sleep * 1000);
	return (0);
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	printing(get_time() - philo->starting_time, philo->id, "has taken a fork",
		philo->printing);
	pthread_mutex_lock(philo->leeft_fork);
	printing(get_time() - philo->starting_time, philo->id, "has taken a fork",
		philo->printing);
	printing(get_time() - philo->starting_time, philo->id, "is eating",
		philo->printing);
	ft_usleep(philo->time_to.eat * 1000);
	philo->time_of_last_meals = get_time();
	// printf("meals %d: %lf\n" , philo->id + 1, philo->time_of_last_meals);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->leeft_fork);
	if (philo->nbr_of_meals > 0)
		philo->nbr_of_meals--;
	return (0);
}
