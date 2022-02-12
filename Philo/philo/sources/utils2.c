/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:21:48 by maroly            #+#    #+#             */
/*   Updated: 2022/02/12 02:56:36 by maroly           ###   ########.fr       */
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
	if (lst->s->is_dead == false)
		printf("%.5lld	%.3d %s\n"NONE, get_time() - lst->s->first_time,
			lst->digit_philo, s);
	if (will_die == true && lst->s->is_dead == false)
		lst->s->is_dead = true;
	pthread_mutex_unlock(&lst->s->print);
}
