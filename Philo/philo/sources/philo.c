/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:39:22 by maroly            #+#    #+#             */
/*   Updated: 2022/02/12 02:56:46 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*only_one_philo(t_list *lst)
{
	print(BLUE"has taken a fork.", lst, false);
	usleep(lst->s->time_to_die * 1000);
	print(RED"died.", lst, true);
	return (NULL);
}

void	*routine(void *param)
{
	t_list	*lst;
	int		i;

	lst = param;
	i = -1;
	if (lst->s->number_of_philo == 1 && lst->s->time_philo_must_eat != 0)
		return (only_one_philo(lst));
	if (lst->digit_philo % 2 == 0
		|| lst->digit_philo == lst->s->number_of_philo)
		usleep(50);
	while (lst->s->is_dead == false && ++i != lst->s->time_philo_must_eat)
	{
		pthread_mutex_lock(&lst->fork);
		print(BLUE"has taken a fork.", lst, false);
		pthread_mutex_lock(&lst->next->fork);
		print(BLUE"has taken a fork.", lst, false);
		eat(lst);
		pthread_mutex_unlock(&lst->next->fork);
		pthread_mutex_unlock(&lst->fork);
		sleeep(lst);
		print(CYAN"is thinking.", lst, false);
	}
	return (NULL);
}

void	init_routine(t_list *lst)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp2;

	i = 0;
	lst->s->first_time = get_time();
	tmp = lst;
	while (++i <= lst->s->number_of_philo)
	{
		pthread_mutex_init(&tmp->fork, NULL);
		pthread_create(&tmp->t, NULL, routine, tmp);
		tmp = tmp->next;
	}
	tmp2 = lst;
	i = 0;
	while (++i <= lst->s->number_of_philo)
	{
		pthread_join(tmp2->t, NULL);
		tmp2 = tmp2->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*lst;
	t_var	*s;

	if (ac < 5 || ac > 6)
		return (ft_putstr_fd("Wrong number of arguments!\n", 2));
	if (check_args(av) == 1)
		return (2);
	lst = NULL;
	s = malloc(sizeof(t_var *) * 1);
	if (!s)
		return (3);
	init_s(s, av, ac);
	create_lst(&lst, s);
	init_routine(lst);
	clear_lst(&lst);
	pthread_mutex_destroy(&s->print);
	return (0);
}
