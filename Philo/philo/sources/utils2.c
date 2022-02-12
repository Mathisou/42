/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:21:48 by maroly            #+#    #+#             */
/*   Updated: 2022/02/12 14:02:24 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	return (1);
}

void	print(char *s, t_list *lst, bool will_die)
{
	pthread_mutex_lock(&lst->s->print);
	if (is_dead(lst, 0))
		printf("%.5lld	%.3d %s\n"NONE, get_time() - lst->s->first_time,
			lst->digit_philo, s);
	if (will_die == true && is_dead(lst, 0))
		lst->s->is_dead = true;
	pthread_mutex_unlock(&lst->s->print);
}

bool	last_has_eaten(t_list *lst)
{
	bool	val;

	pthread_mutex_lock(&lst->s->has_eaten);
	val = lst->last_has_eaten == false;
	pthread_mutex_unlock(&lst->s->has_eaten);
	return (val);
}

bool	is_dead(t_list *lst, int i)
{
	bool	val;

	pthread_mutex_lock(&lst->s->dead);
	val = (lst->s->is_dead == false && i != lst->s->time_philo_must_eat);
	pthread_mutex_unlock(&lst->s->dead);
	return (val);
}
