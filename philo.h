/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:03:46 by mochegri          #+#    #+#             */
/*   Updated: 2021/12/05 17:50:03 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct  s_philo
{
    int nbr_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nbr_of_meals;
}               t_philo;

t_philo	*init_philosophers(int ac, char **av);
int		ft_perror(void);
int		ft_atoi(char *s);

# endif