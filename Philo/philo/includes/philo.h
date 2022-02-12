/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:25:14 by maroly            #+#    #+#             */
/*   Updated: 2022/02/12 02:53:56 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

# define BLACK      "\033[30;01m"
# define RED        "\033[31;01m"
# define GREEN      "\033[32;01m"
# define YELLOW     "\033[33;01m"
# define BLUE       "\033[34;01m"
# define PURPLE     "\033[35;01m"
# define D_GREEN    "\033[6;01m"
# define WHITE      "\033[7;01m"
# define CYAN       "\x1b[36m"
# define NONE        "\033[0m"

typedef struct s_var
{
	int				number_of_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		time_philo_must_eat;
	bool			is_dead;
	long long		first_time;
	pthread_mutex_t	print;
}	t_var;

typedef struct s_list
{
	pthread_t		t;
	int				digit_philo;
	bool			is_fork_available;
	bool			last_has_eaten;
	t_var			*s;
	pthread_mutex_t	fork;
	struct s_list	*next;
}	t_list;

long long	ft_atoi(const char *nptr);
t_list		*new_elem(int digit);
void		lst_add_back(t_list **lst, int digit);
void		lst_add_front(t_list **lst, t_list *new);
void		clear_lst(t_list **lst);
int			lst_size(t_list **lst);
size_t		ft_strlen(const char *s);
long long	get_time(void);
void		init_s(t_var *s, char **av, int ac);
int			check_args(char **av);
int			ft_putstr_fd(char *s, int fd);
void		print(char *s, t_list *lst, bool will_die);
void		create_lst(t_list **lst, t_var *s);
void		eat(t_list *lst);
void		sleeep(t_list *lst);

#endif