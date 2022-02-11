/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:39:22 by maroly            #+#    #+#             */
/*   Updated: 2022/02/11 16:29:38 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long long	get_time()
{
	struct timeval  tv;
	gettimeofday(&tv, NULL);

	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void	print(char *s, t_list *lst)
{
	pthread_mutex_lock(&lst->s->print);
	if (lst->s->is_dead == false)
		printf("%.5lld	%.3d %s\n"NONE, get_time() - lst->s->first_time, lst->digit_philo, s);
	pthread_mutex_unlock(&lst->s->print);
}

void	eat(t_list *lst)
{
	if (lst->s->time_to_eat < lst->s->time_to_die)
	{
		if (lst->s->is_dead == false)
		{
			/*lst->is_hungry = false;
			lst->is_tired = true;
			lst->old_last_time_eat = get_time() - lst->s->first_time;*/
			print(PURPLE"is eating.", lst);
			usleep(lst->s->time_to_eat * 1000);
		}
	}
	else
	{
		lst->is_philo_dead = true;
		usleep(lst->s->time_to_die * 1000);
		print(RED"died.", lst);
		lst->s->is_dead = true;
	}
}

void	sleeep(t_list *lst)
{
	if (lst->s->time_to_sleep < lst->s->time_to_die)
	{
		//lst->is_tired = false;
		print(GREEN"is sleeping.", lst);
		usleep(lst->s->time_to_sleep * 1000);
	}
	else
	{
		print(GREEN"is sleeping.", lst);
		lst->is_philo_dead = true;
		usleep(lst->s->time_to_die * 1000);
		print(RED"died.", lst);
		lst->s->is_dead = true;
	}
}

void	*routine(void *param)
{
	t_list *lst;
	int i;

	lst = param;
	i = -1;
	while (lst->s->is_dead == false && ++i != lst->s->time_philo_must_eat)
	{
		if (lst->digit_philo % 2 == 0)
			usleep(50);
		pthread_mutex_lock(&lst->fork);
		print(BLUE"has taken a fork.", lst);
		pthread_mutex_lock(&lst->next->fork);
		print(BLUE"has taken a fork.", lst);
		eat(lst);
		pthread_mutex_unlock(&lst->next->fork);
		pthread_mutex_unlock(&lst->fork);
		sleeep(lst);
		print(CYAN"is thinking.", lst);
	}
	return (NULL);
}

void	init_routine(t_list *lst)
{
	int i;
	t_list *tmp;
	t_list *tmp2;

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
	i = -1;
	while (++i < lst->s->number_of_philo)
	{
		pthread_join(tmp2->t, NULL);
		//pthread_mutex_destroy(&tmp2->fork);
		//pthread_detach(tmp2->t);
		tmp2 = tmp2->next;
	}
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
	pthread_mutex_init(&s->print, NULL);
}

int	check_args(char **av)
{
	int i;
	int j;
	int len;

	i = 1;
	while (av[i])
	{
		j = 0;
		len = ft_strlen(av[i]);
		while(av[i][j] || len == 0)
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				printf(RED"Invalid argument!\n"NONE);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	t_list *tmp2;
	t_list *lst;
	t_var *s;
	int i;

	if (ac < 5 || ac > 6)
		return (1);
	if (check_args(av) == 1)
		return (2);
	i = 0;
	lst = NULL;
	s = malloc(sizeof(t_var *) * 1);
	init_s(s, av, ac);
	if (!s)
		return (1);
	while (++i <= ft_atoi(av[1]))
		lst_add_back(&lst, i);
	tmp2 = lst;
	if (tmp2)
		while (tmp2->next)
		{
			tmp2->s = s;
			tmp2 = tmp2->next;
		}
	tmp2->s = s;
	tmp2->next = lst;
	init_routine(lst);
	tmp2->next = NULL;
	free(lst->s);
	clear_lst(&lst);
	pthread_mutex_destroy(&s->print);
	return (0);
}