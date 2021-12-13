/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:09:25 by mochegri          #+#    #+#             */
/*   Updated: 2021/12/14 00:52:46 by mochegri         ###   ########.fr       */
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
	int			a_philo_is_die;

	a_philo_is_die = 0;
	table = init_table(ac, av, &a_philo_is_die);
	if (!table)
		return (ft_perror());
	if (init_fork(table))
		return (ft_perror());
	return (start_philo(table));
}

void	printing(double time, int id, char *msg, pthread_mutex_t *mutex)
{
	pthread_mutex_unlock(mutex);
	printf("%.0lf %d %s\n", time, id + 1, msg);
	// if (*msg != 'd')
	// 	pthread_mutex_unlock(mutex);
}

void	ft_free(t_table *table)
{
	free(table->thread);
	free(table->forks);
	free(table->philo);
	free(table);
}
