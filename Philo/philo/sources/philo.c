/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:39:22 by maroly            #+#    #+#             */
/*   Updated: 2022/02/08 19:55:44 by maroly           ###   ########.fr       */
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
	s->tmp->is_hungry = false;
	s->tmp->is_tired = true;
	if (s->old_time == 0)
	{
		s->time = get_time();
		s->old_time = s->time;
	}
	else
		s->time = get_time();
	printf("\033[32;01mPhilo %d has taken a fork.\033[00m🍴 %20lldms\n", s->tmp->digit_philo, s->time - s->old_time);
	printf("\033[32;01mPhilo %d has taken a fork.\033[00m🍴 %20lldms\n", s->tmp->digit_philo, s->time - s->old_time);
	if (s->time_to_eat < s->time_to_die)
	{
		s->tmp->time_of_eat = s->time - s->old_time;
		printf("\033[32;01mPhilo %d is eating...   😋🍗\033[00m %20lldms\n", s->tmp->digit_philo, s->tmp->time_of_eat);
		usleep(s->time_to_eat * 1000);
	}
	else
	{
		s->tmp->time_of_eat = s->time - s->old_time;
		printf("\033[32;01mPhilo %d is eating...   😋🍗\033[00m %20lldms\n", s->tmp->digit_philo, s->tmp->time_of_eat);
		usleep(s->time_to_die * 1000);
		s->is_dead = true;
		return (1);
	}
	return (0);
}

int	sleeep(t_var *s)
{
	s->tmp->is_tired = false;
	s->time = get_time();
	if (s->time_to_sleep + s->time_to_eat < s->time_to_die)
	{
		printf("\033[32;01mPhilo %d fell asleep... 😴🛌\033[00m %20lldms\n", s->tmp->digit_philo, s->time - s->old_time);
		usleep(s->time_to_sleep * 1000);
	}
	else
	{
		printf("\033[32;01mPhilo %d fell asleep... 😴🛌\033[00m %20lldms\n", s->tmp->digit_philo, s->time - s->old_time);
		usleep((s->time_to_die - s->time_to_eat) * 1000);
		s->is_dead = true;
		return (1);
	}
	return (0);
}

void	*routine(void *param)
{
	t_var *s;

	s = param;
	pthread_mutex_lock(&s->tmp->fork);
	pthread_mutex_lock(&s->tmp->next->fork);
	if (s->tmp->is_fork_available == true && s->tmp->next->is_fork_available == true)
	{
		if (s->tmp->time_of_eat >= s->time_to_die)
		{
			s->is_dead = true;
			return (NULL);
		}
		s->tmp->next->is_fork_available = false;
		s->tmp->is_fork_available = false;
		if (s->tmp->is_hungry == true)
			if (eat(s) == 1)
				return (NULL);
		s->tmp->next->is_fork_available = true;
		s->tmp->is_fork_available = true;
		if (s->tmp->is_tired == true && s->tmp->is_hungry == false)
			if (sleeep(s) == 1)
				return (NULL);
		if (s->tmp->is_hungry == false && s->tmp->is_tired == false)
		{
			printf("\033[32;01mPhilo %d is thinking... ⏳\033[00m %22lldms\n", s->tmp->digit_philo, s->time - s->old_time);
			s->tmp->is_hungry = true;
		}
	}
	pthread_mutex_unlock(&s->tmp->fork);
	pthread_mutex_unlock(&s->tmp->next->fork);
	return (NULL);
}

void	init_struct(t_var *s, char **av)
{
	s->number_of_philo = ft_atoi(av[1]);
	s->time_to_die = ft_atoi(av[2]);
	s->time_to_eat = ft_atoi(av[3]);
	s->time_to_sleep = ft_atoi(av[4]);
	s->is_dead = false;
	s->old_time = 0;
	s->digit = 0;
}

void	init_routine(t_var *s)
{
	t_list *tmp2;
	
	s->tmp = s->info;
	tmp2 = s->info;
	s->digit = 0;
	while (s->is_dead == false && ++s->digit <= s->number_of_philo)
	{
		pthread_mutex_init(&s->tmp->fork, NULL);
		pthread_mutex_init(&s->tmp->next->fork, NULL);
		pthread_create(&s->tmp->t, NULL, routine, s);
		s->tmp = s->tmp->next;
		if (s->digit + 1 > s->number_of_philo && s->is_dead == false)
			s->digit = 0;
		//usleep(6000);
	}
	while (tmp2 && s->is_dead == false)
	{
		pthread_join(tmp2->t, NULL);
		pthread_mutex_destroy(&s->tmp->fork);
		pthread_mutex_destroy(&s->tmp->next->fork);
		//pthread_detach(tmp2->t);
		tmp2 = tmp2->next;
	}
}

int main(int ac, char **av) // mort annonce + de 10 ms apres sa mort et bug avc 1 philo et bug mort quand ca doit pas
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
	if (tmp2 != NULL)
		while (tmp2->next)
			tmp2 = tmp2->next;
	tmp2->next = s->info;
	s->info = tmp2;
	init_routine(s);
	s->time = get_time();
	printf("\033[31;01mPhilo %d died\033[00m 😰 %32lldms\n", s->tmp->digit_philo, s->time - s->old_time);
	free(s);
	return (0);
}