/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:36:48 by mochegri          #+#    #+#             */
/*   Updated: 2021/12/14 00:47:04 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*init_table(int ac, char **av, int *a_philo_is_die)
{
	t_table	*table;

	if (ac < 5 || ac > 6)
		return (NULL);
	table = (t_table *)malloc(sizeof(t_table));
	table->nbr_of_philo = ft_atoi(*(av + 1));
	table->time_to.die = ft_atoi(*(av + 2));
	table->time_to.eat = ft_atoi(*(av + 3));
	table->time_to.sleep = ft_atoi(*(av + 4));
	if (*(av + 5))
		table->nbr_of_meals = ft_atoi(*(av + 5));
	if (table->nbr_of_philo < 0 || table->time_to.die < 0
		|| table->time_to.eat < 0 || table->time_to.sleep < 0
		|| (*(av + 5) && table->nbr_of_meals < 0))
		return (NULL);
	if (!*(av + 5))
		table->nbr_of_meals = -1;
	table->thread = (pthread_t *)malloc(sizeof(pthread_t)
			* table->nbr_of_philo);
	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->nbr_of_philo);
	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->nbr_of_philo);
	table->a_philo_is_die = a_philo_is_die;
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
