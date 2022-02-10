/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:39:22 by maroly            #+#    #+#             */
/*   Updated: 2022/02/10 18:45:43 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time()
{
	struct timeval  tv;
	gettimeofday(&tv, NULL);

	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void	eat(t_list *lst)
{
	pthread_mutex_lock(&lst->fork);
	pthread_mutex_lock(&lst->next->fork);
	//pthread_mutex_lock(&lst->s->print);
	printf("\033[34;01mPhilo %d has taken a fork.\033[00m🍴 %20lldms\n", lst->digit_philo, get_time() - lst->s->first_time);
	printf("\033[34;01mPhilo %d has taken a fork.\033[00m🍴 %20lldms\n", lst->digit_philo, get_time() - lst->s->first_time);
	//pthread_mutex_unlock(&lst->s->print);
	if (lst->s->time_to_eat + (lst->last_time_eat - lst->last_time_eat) < lst->s->time_to_die)
	{
		//pthread_mutex_lock(&lst->s->print);
		lst->is_hungry = false;
		lst->is_tired = true;
		lst->old_last_time_eat = lst->last_time_eat;
		printf("\033[37;01mPhilo %d is eating...   😋🍗\033[00m %20lldms\n", lst->digit_philo, get_time() - lst->s->first_time);
		usleep(lst->s->time_to_eat * 1000);
		//pthread_mutex_unlock(&lst->s->print);
	}
	else
	{
		lst->is_philo_dead = true;
		lst->s->is_dead = true;
		usleep(lst->s->time_to_die * 1000);
		//pthread_mutex_lock(&lst->s->print);
		printf("\033[31;01mPhilo %d died.\033[00m %22lldms\n", lst->digit_philo, get_time() - lst->s->first_time);
		//pthread_mutex_unlock(&lst->s->print);
	}
	pthread_mutex_unlock(&lst->fork);
	pthread_mutex_unlock(&lst->next->fork);
}

int	sleeep(t_list *lst)
{
	if (lst->s->time_to_sleep < lst->s->time_to_die)
	{
		//pthread_mutex_lock(&lst->s->print);
		lst->is_tired = false;
		printf("\033[32;01mPhilo %d fell asleep... 😴🛌\033[00m %20lldms\n", lst->digit_philo, get_time() - lst->s->first_time);
		usleep(lst->s->time_to_sleep * 1000);
		//pthread_mutex_unlock(&lst->s->print);
	}
	else
	{
		//pthread_mutex_lock(&lst->s->print);
		printf("\033[32;01mPhilo %d fell asleep... but something went wrong😴🛌\033[00m %20lldms\n", lst->digit_philo, get_time() - lst->s->first_time);
		lst->is_philo_dead = true;
		lst->s->is_dead = true;
		usleep(lst->s->time_to_die * 1000);
		printf("\033[31;01mPhilo %d died.\033[00m %22lldms\n", lst->digit_philo, get_time() - lst->s->first_time);
		//pthread_mutex_unlock(&lst->s->print);
		return (1);
	}
	return (0);
}

void	*routine(void *param)
{
	t_list *lst;

	lst = param;
	lst->s->first_time = get_time();

	//printf("addr %p\n", lst);
	//printf("entering : %d time %lld\n", lst->digit_philo, lst->last_time_eat);
	while (lst->s->is_dead == false)
	{
		//if (lst->digit_philo % 2 == 0)
		//	usleep(10000);
		//printf("%lld\n", get_time());
		printf("old in %lld\n", lst->s->first_time);
		lst->last_time_eat = get_time() - lst->s->first_time;
		//printf("%lld - %lld\n", lst->last_time_eat ,lst->s->first_time);
		if (lst->s->is_dead == false && lst->last_time_eat - lst->old_last_time_eat >= lst->s->time_to_die)
		{
			//pthread_mutex_lock(&lst->s->print);
			lst->is_philo_dead = true;
			lst->s->is_dead = true;
			printf("\033[31;01mPhilo %d died.\033[00m %22lldms\n", lst->digit_philo, get_time() - lst->s->first_time);
			//pthread_mutex_unlock(&lst->s->print);
			break;
		}
		if (lst->s->is_dead == false && lst->is_hungry == true)
			eat(lst);
		if (lst->s->is_dead == false && lst->is_tired == true && lst->is_hungry == false)
			sleeep(lst);
		if (lst->s->is_dead == false && lst->is_tired == false && lst->is_hungry == false)
		{
			//pthread_mutex_lock(&lst->s->print);
			lst->is_hungry = true;
			printf("\033[33;01mPhilo %d is thinking... ⏳\033[00m %22lldms\n", lst->digit_philo, get_time() - lst->s->first_time);
			//pthread_mutex_unlock(&lst->s->print);
		}
		usleep(5000);
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
	//printf("%lld\n", get_time());
	//printf("old out %lld\n", tmp->s->first_time);
	while (++i <= lst->s->number_of_philo)
	{
		//	printf("old out %lld\n", tmp->s->first_time);

		pthread_mutex_init(&lst->fork, NULL);
		//	printf("old out %lld\n", tmp->s->first_time);

		pthread_create(&tmp->t, NULL, routine, tmp);
		//			printf("old out d%lld\n", lst->s->first_time);

		usleep(5000);
		tmp = tmp->next;
	}
	tmp2 = lst;
	i = -1;
	while (++i < lst->s->number_of_philo)
	{
		pthread_join(tmp2->t, NULL);
		//printf("apres join %d\n", tmp2->digit_philo);
		pthread_mutex_destroy(&tmp2->fork);
		//pthread_detach(tmp2->t);
		tmp2 = tmp2->next;
	}
}

void	init_s(t_var *s, char **av)
{
	s->number_of_philo = ft_atoi(av[1]);
	s->time_to_die = ft_atoi(av[2]);
	s->time_to_eat = ft_atoi(av[3]);
	s->time_to_sleep = ft_atoi(av[4]);
	//s->old_time = 0;
	s->is_dead = false;
	pthread_mutex_init(&s->print, NULL);
	//s->fork = malloc(sizeof(pthread_mutex_t) * s->number_of_philo); // todo: check le retour si erreur
	//if (!s->fork)
	//	return ;
}

int main(int ac, char **av)
{
	t_list *tmp2;
	t_list *lst;
	t_var *s;
	int i;

	if (ac != 5)
		return (1);
	i = 0;
	lst = NULL;
	s = malloc(sizeof(t_var *) * 1);
	init_s(s, av);
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
	free(lst->s);
	pthread_mutex_destroy(&s->print);
	return (0);
}