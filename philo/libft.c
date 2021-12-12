/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:13:52 by mochegri          #+#    #+#             */
/*   Updated: 2021/12/12 17:42:02 by mochegri         ###   ########.fr       */
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
