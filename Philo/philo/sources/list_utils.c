/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:42:16 by maroly            #+#    #+#             */
/*   Updated: 2022/02/12 02:55:07 by maroly           ###   ########.fr       */
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
	new_elem->last_has_eaten = false;
	new_elem->is_fork_available = true;
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

void	create_lst(t_list **lst, t_var *s)
{
	int		i;
	t_list	*tmp2;

	i = 0;
	tmp2 = NULL;
	while (++i <= s->number_of_philo)
		lst_add_back(lst, i);
	tmp2 = *lst;
	if (tmp2)
	{
		while (tmp2->next)
		{
			tmp2->s = s;
			tmp2 = tmp2->next;
		}
	}
	tmp2->s = s;
	tmp2->next = *lst;
}

void	clear_lst(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = *lst;
	while (tmp2->digit_philo != tmp2->s->number_of_philo)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp = *lst;
	free((*lst)->s);
	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free (*lst);
			(*lst) = tmp;
		}
	}
}
