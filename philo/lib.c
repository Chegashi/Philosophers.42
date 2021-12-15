/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:13:52 by mochegri          #+#    #+#             */
/*   Updated: 2021/12/15 19:34:09 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *s)
{
	long	nbr;
	int		signe;

	signe = 1;
	nbr = 0;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			signe = -1;
	while (*s)
	{
		nbr = nbr * 10 + (*s - '0');
		if (*s < '0' || *s > '9' || (signe == 1 && nbr > 2147483647)
			|| (signe == -1 && nbr > 2147483648))
			return (-1);
		s++;
	}
	return ((int)(nbr * signe));
}

int	ft_perror(void)
{
	printf("error\n");
	return (1);
}

double	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

double	get_time_u(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000000 + current_time.tv_usec);
}

void	ft_usleep(double i)
{
	double	time;

	time = get_time_u();
	usleep(i - 20000);
	while ((get_time_u() - time) < i)
		;
}
