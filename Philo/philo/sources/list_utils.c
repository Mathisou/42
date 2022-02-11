/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:42:16 by maroly            #+#    #+#             */
/*   Updated: 2022/02/11 16:16:14 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_list	*new_elem(int digit)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	new_elem->digit_philo = digit;
	new_elem->is_hungry = true;
	new_elem->is_tired = false;
	new_elem->last_time_eat = 0;
	new_elem->old_last_time_eat = 0;
	new_elem->is_fork_available = true;
	new_elem->is_philo_dead = false;
	new_elem->next = NULL;
	return (new_elem);
}

void	lst_add_back(t_list **lst, int digit)
{
	t_list	*tmp;

	tmp = *lst;
	if (*lst == NULL)
		*lst = new_elem(digit);
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_elem(digit);
	}
}

void	lst_add_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	clear_lst(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (lst)
	{
		while ((*lst)->next->digit_philo != 1)
		{
			tmp = (*lst)->next;
			free (*lst);
			(*lst) = tmp;
		}
	}
}

int	lst_size(t_list **lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}