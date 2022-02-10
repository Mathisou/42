/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:25:14 by maroly            #+#    #+#             */
/*   Updated: 2022/02/10 18:42:47 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>

typedef struct s_var
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_philo_must_eat;
	int	eat_count; // 
	bool	is_dead;
	long long first_time;
	pthread_mutex_t print;
}	t_var;

typedef struct s_list
{
	pthread_t		t;
	int				digit_philo;
	bool			is_fork_available;
	bool			is_hungry;
	bool			is_tired;
	long long		last_time_eat;
	long long		old_last_time_eat;
	bool			is_philo_dead;
	t_var	*s;
	pthread_mutex_t	fork;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *nptr);
t_list	*new_elem(int digit);
void	lst_add_back(t_list **lst, int digit);
void	lst_add_front(t_list **lst, t_list *new);
void	clear_lst(t_list **lst);
int		lst_size(t_list **lst);

#endif