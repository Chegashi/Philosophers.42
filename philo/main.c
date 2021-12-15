/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:09:25 by mochegri          #+#    #+#             */
/*   Updated: 2021/12/15 19:33:01 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table		*table;
	int			i;

	table = init_table(ac, av);
	if (!table)
		return (ft_perror());
	if (init_fork(table))
		return (ft_perror());
	i = -1;
	while (++i < table->nbr_of_philo)
	{
		init_philo(table->philo + i, i, table);
		usleep(100);
	}
	if (checker(table))
		return (ft_free (table));
	i = -1;
	return (0);
}

void	printing(double time, int id, char *msg, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	printf("%.0lf %d %s\n", time, id + 1, msg);
	if (*msg != 'd')
		pthread_mutex_unlock(mutex);
}

int	ft_free(t_table *table)
{
	int i;

	i = -1;
	while (++i < table->nbr_of_philo)
		pthread_detach(table->thread[i]);
	free(table->thread);
	i = -1;
	while (++i < table->nbr_of_philo)
		pthread_mutex_destroy(table->forks + i);
	free(table->forks);
	pthread_mutex_destroy(table->printing);
	free(table->printing);
	free(table);
	return (0);
}

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
			if (table->philo[i].nbr_of_meals == 0)
				return (1);
		}
	}
}
