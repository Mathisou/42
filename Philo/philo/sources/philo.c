/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:39:22 by maroly            #+#    #+#             */
/*   Updated: 2022/02/10 02:37:28 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time()
{
	struct timeval  tv;
	gettimeofday(&tv, NULL);

	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

int	eat(t_var *s)
{
	pthread_mutex_lock(&s->tmp->fork);
	pthread_mutex_lock(&s->tmp->next->fork);
	s->tmp->is_hungry = false;
	s->tmp->is_tired = true;
	s->tmp->old_last_time_eat = s->tmp->last_time_eat;
	printf("\033[34;01mPhilo %d has taken a fork.\033[00m🍴 %20lldms\n", s->tmp->digit_philo, get_time() - s->old_time);
	printf("\033[34;01mPhilo %d has taken a fork.\033[00m🍴 %20lldms\n", s->tmp->digit_philo, get_time() - s->old_time);
	if (s->time_to_eat < s->time_to_die)
	{
		printf("\033[31;01mPhilo %d is eating...   😋🍗\033[00m %20lldms\n", s->tmp->digit_philo, get_time() - s->old_time);
		usleep(s->time_to_eat * 1000);
	}
	else
	{
		//printf("\033[31;01mPhilo %d is eating...   😋🍗\033[00m %20lldms\n", s->tmp->digit_philo, get_time() - s->old_time);
		s->tmp->is_philo_dead = true;
		usleep(s->time_to_die * 1000);
		return (1);
	}
	pthread_mutex_unlock(&s->tmp->fork);
	pthread_mutex_unlock(&s->tmp->next->fork);
	return (0);
}

int	sleeep(t_var *s)
{
	if (s->time_to_sleep < s->time_to_die)
	{
		printf("\033[32;01mPhilo %d fell asleep... 😴🛌\033[00m %20lldms\n", s->tmp->digit_philo, get_time() - s->old_time);
		usleep(s->time_to_sleep * 1000);
	}
	else
	{
		printf("\033[32;01mPhilo %d fell asleep... but something went wrong omg😴🛌\033[00m %20lldms\n", s->tmp->digit_philo, get_time() - s->old_time);
		s->tmp->is_philo_dead = true;
		usleep(s->time_to_die * 1000);
		return (1);
	}
	return (0);
}

void	*routine(void *param)
{
	t_var *s;

	s = param;
	while (s->tmp->is_philo_dead == false)
	{
		if (s->tmp->digit_philo % 2 == 0)
			usleep(10000);
		//printf(" in : thread %d et philo mort ? 1 = oui 0 non : %d\n", s->tmp->digit_philo, s->tmp->is_philo_dead);
		s->tmp->last_time_eat = get_time() - s->old_time;
		printf("philo : %d time : %lld\n", s->tmp->digit_philo, s->tmp->last_time_eat - s->tmp->old_last_time_eat);
		if (s->tmp->last_time_eat - s->tmp->old_last_time_eat >= s->time_to_die)
		{
			s->tmp->is_philo_dead = true;
			break;
		}
		if (s->tmp->is_philo_dead == false && s->tmp->is_hungry == true)
			if (eat(s) == 1)
				break;
		if (s->tmp->is_philo_dead == false && s->tmp->is_tired == true && s->tmp->is_hungry == false)
		{
			s->tmp->is_tired = false;
			if (sleeep(s) == 1)
				break;
		}
		if (s->tmp->is_philo_dead == false && s->tmp->is_tired == false && s->tmp->is_hungry == false)
		{
			s->tmp->is_hungry = true;
			printf("\033[33;01mPhilo %d is thinking... ⏳\033[00m %22lldms\n", s->tmp->digit_philo, get_time() - s->old_time);
		}
		usleep(10000);
	}
	return (NULL);
}

void	init_routine(t_var *s)
{
	int i;

	i = -1;
	s->tmp = s->info;

	s->old_time = get_time();
	while (++i < s->number_of_philo)
	{
		pthread_create(&s->tmp->t, NULL, routine, s);
		usleep(10000);
		s->tmp = s->tmp->next;
	}
	//usleep(1000000);
	i = -1;
	while (++i < s->number_of_philo)
	{
		pthread_join(s->tmp->t, NULL);
		pthread_mutex_destroy(&s->tmp->fork);
		//pthread_detach(s->tmp->t);
		s->tmp = s->tmp->next;
	}
	printf("\033[31;01mPhilo %d died\033[00m 😰 %32lldms\n", s->tmp->digit_philo, get_time() - s->old_time);
}

void	init_struct(t_var *s, char **av)
{
	s->number_of_philo = ft_atoi(av[1]);
	s->time_to_die = ft_atoi(av[2]);
	s->time_to_eat = ft_atoi(av[3]);
	s->time_to_sleep = ft_atoi(av[4]);
	s->old_time = 0;
	s->digit = 0;
}

int main(int ac, char **av) // un seul thread qui tourne en rond
{
	t_var *s;
	t_list *tmp2;

	if (ac != 5)
		return (1);
	s = malloc(sizeof(t_var) * 1);
	init_struct(s, av);
	s->info = NULL;
	while (++s->digit <= s->number_of_philo)
		lst_add_back(&s->info, s->digit);
	tmp2 = s->info;
	if (tmp2)
		while (tmp2->next)
			tmp2 = tmp2->next;
	tmp2->next = s->info;
	init_routine(s);
	free(s);
	return (0);
}