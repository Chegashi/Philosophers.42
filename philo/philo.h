/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:03:46 by mochegri          #+#    #+#             */
/*   Updated: 2021/12/11 23:11:44 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_time_to
{
	int				eat;
	int				sleep;
	int				die;
}				t_time_to;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	leeft_fork;
	pthread_mutex_t	right_fork;
	t_time_to		time_to;
	int				nbr_of_meals;
}				t_philo;

typedef struct s_table
{
	int					nbr_of_philo;
	int					nbr_of_meals;
	t_philo				*philo;
	pthread_mutex_t		*forks;
	pthread_t			*thread;
	t_time_to			time_to;
}				t_table;

t_table		*init_table(int ac, char **av);
int			ft_perror(void);
int			ft_atoi(char *s);
int			init_fork(t_table *table);
int			start_philo(t_table *table);
int			*philoeat(void *arg);
void		*philo(void *arg);
#endif