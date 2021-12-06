/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:09:25 by mochegri          #+#    #+#             */
/*   Updated: 2021/12/05 18:24:08 by mochegri         ###   ########.fr       */
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

int main (int ac, char **av)
{
	t_philo *philosophers;

	philosophers = init_philosophers(ac, av);
	if (!philosophers)
		return (ft_perror());
	
	return (0);
}

t_philo	*init_philosophers(int ac, char **av)
{
	t_philo *philosophers;

	if (ac < 4 || ac > 5)
		return (NULL);
	philosophers->nbr_of_philo = ft_atoi(*(av + 1));
	philosophers->time_to_die = ft_atoi(*(av + 2));
	philosophers->time_to_eat =  ft_atoi(*(av + 3));
	philosophers->time_to_sleep =  ft_atoi(*(av + 4));
	if (av + 5)
		philosophers->nbr_of_meals = ft_atoi(*(av + 5));
	else
		philosophers->nbr_of_meals = 0;
	if (philosophers->nbr_of_philo < 0 || philosophers->time_to_die < 0 ||
		philosophers->time_to_eat < 0 || philosophers->time_to_sleep < 0||
		philosophers->nbr_of_meals < 0)
		return (NULL);
	return (philosophers);
}

int ft_perror(void)
{
	printf("error\n");
	return (1);
}

int	ft_atoi(char *s)
{
	long	nbr;
	int		signe;

	signe = 1;
	nbr = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			signe = -1;
		s++;
	}
	while (*s)
	{
		nbr = nbr * 10 + (*s - '0');
		if (*s < '0' || *s > '9' || (signe == 1 && nbr > 2147483647)
			|| (signe == -1 && nbr > 2147483648))
			return (-1);
		s++;
	}
	nbr *= signe;
	return ((int)nbr);
}

