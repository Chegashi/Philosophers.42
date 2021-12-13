/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:11:10 by mochegri          #+#    #+#             */
/*   Updated: 2021/12/14 00:50:15 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_philo(t_table *table)
{
	int			i;
	int			some_1_is_died;

	i = -1;
	while (++i < table->nbr_of_philo)
		init_philo(table->philo + i, i, table);
	i = -1;
	while (++i < table->nbr_of_philo)
	{
		if (pthread_join(*(table->thread + i), (void *)&some_1_is_died))
			return (1);
	}
	i = -1;
	if (some_1_is_died)
	{
		while (++i < table->nbr_of_philo)
		{
			pthread_detach(table->thread[i]);
			pthread_mutex_destroy(table->forks + i);
			ft_free(table);
		}
		return (0);
	}
	return (0);
}

void	*philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->time_of_last_meals = get_time();
	while (1)
	{
		// printf("id:%dnbr:%d\n", philo->id, philo->nbr_of_meals);
		printing(get_time() - philo->starting_time, philo->id, "is thinking",
			philo->printing);
		if (philo->nbr_of_meals  && eating(philo))
			break ;
		if (sleeping(philo))
			break ;
	}
	*(philo->a_philo_is_die) = 1;
	printing(get_time() - philo->starting_time, philo->id, "died",
		philo->printing);
	return (NULL);
}

void	init_philo(t_philo *a_philo, int i, t_table *table)
{
	a_philo->id = i;
	a_philo->n = table->nbr_of_philo;
	a_philo->right_fork = *(table->forks + i);
	a_philo->leeft_fork = *(table->forks + ((i + 1) % table->nbr_of_philo));
	a_philo->time_to = table->time_to;
	a_philo->printing = &(table->printing);
	a_philo->a_philo_is_die = table->a_philo_is_die;
	a_philo->starting_time = get_time();
	a_philo->nbr_of_meals = table->nbr_of_meals;
	pthread_create(table->thread + i, 0, philo, table->philo + i);
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork));
	if (get_time() - philo->time_of_last_meals > philo->time_to.die
		|| philo->id == (philo->id + 1 % philo->n))
	{
		pthread_mutex_unlock(&(philo->right_fork));
		return (1);
	}
	printing(get_time() - philo->starting_time, philo->id, "has taken a fork",
		philo->printing);
	pthread_mutex_lock(&(philo->leeft_fork));
	if (get_time() - philo->time_of_last_meals > philo->time_to.die)
	{
		pthread_mutex_unlock(&(philo->right_fork));
		pthread_mutex_unlock(&(philo->leeft_fork));
		return (1);
	}
	printing(get_time() - philo->starting_time, philo->id, "has taken a fork",
		philo->printing);
	printing(get_time() - philo->starting_time, philo->id, "is eating",
		philo->printing);
	usleep(philo->time_to.eat * 1000);
	philo->time_of_last_meals = get_time();
	pthread_mutex_unlock(&(philo->right_fork));
	pthread_mutex_unlock(&(philo->leeft_fork));
	if (philo->nbr_of_meals > 0)
		philo->nbr_of_meals--;
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (get_time() - philo->time_of_last_meals > philo->time_to.die)
		return (1);
	printing(get_time() - philo->starting_time, philo->id, "is sleeping",
		philo->printing);
	usleep(philo->time_to.sleep * 1000);
	return (0);
}

// int	meal_exists(t_philo *philo)
// {
// 	if (!philo->nbr_of_meals || philo->nbr_of_meals > 0)
// 		return (1);
// 	return (0);
// }
