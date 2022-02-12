/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:53:04 by maroly            #+#    #+#             */
/*   Updated: 2022/02/12 02:55:15 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eat2(t_list *lst)
{
	if (lst->s->time_to_eat < lst->s->time_to_die - lst->s->time_to_eat)
	{
		print(PURPLE"is eating.", lst, false);
		usleep(lst->s->time_to_eat * 1000);
	}
	else
	{
		usleep((lst->s->time_to_die - lst->s->time_to_eat) * 1000);
		print(RED"died.", lst, true);
	}
}

void	eat(t_list *lst)
{
	if (lst->last_has_eaten == false)
	{
		if (lst->s->time_to_eat < lst->s->time_to_die)
		{
			print(PURPLE"is eating.", lst, false);
			usleep(lst->s->time_to_eat * 1000);
			lst->next->last_has_eaten = true;
		}
		else
		{
			usleep(lst->s->time_to_die * 1000);
			print(RED"died.", lst, true);
		}
	}
	else
		eat2(lst);
}

void	sleeep(t_list *lst)
{
	if (lst->s->time_to_sleep < lst->s->time_to_die)
	{
		print(GREEN"is sleeping.", lst, false);
		usleep(lst->s->time_to_sleep * 1000);
	}
	else
	{
		usleep(lst->s->time_to_die * 1000);
		print(RED"died.", lst, true);
	}
}
