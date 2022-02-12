/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:37:49 by maroly            #+#    #+#             */
/*   Updated: 2022/02/12 14:01:54 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	ft_atoi(const char *nptr)
{
	size_t		i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	return (result * sign);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void	init_s(t_var *s, char **av, int ac)
{
	s->number_of_philo = ft_atoi(av[1]);
	s->time_to_die = ft_atoi(av[2]);
	s->time_to_eat = ft_atoi(av[3]);
	s->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		s->time_philo_must_eat = ft_atoi(av[5]);
	else
		s->time_philo_must_eat = -1;
	s->first_time = 0;
	s->is_dead = false;
	pthread_mutex_init(&s->dead, NULL);
	pthread_mutex_init(&s->has_eaten, NULL);
	pthread_mutex_init(&s->print, NULL);
}

int	check_args(char **av)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (av[i])
	{
		j = 0;
		len = ft_strlen(av[i]);
		while (av[i][j] || len == 0)
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9')
				|| (ft_atoi(av[i]) == 0 && i != 5))
				return (ft_putstr_fd("Invalid argument(s)!\n", 2));
			j++;
		}
		i++;
	}
	return (0);
}
