/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulating_lists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:12:05 by maroly            #+#    #+#             */
/*   Updated: 2022/01/07 22:32:11 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst *new_elem(int nb, int pos)
{
	t_lst *new_elem;

	new_elem = malloc(sizeof(t_lst));
	if (new_elem == NULL)
		return (NULL);
	new_elem->nb = nb;
	new_elem->pos = pos;
	new_elem->next = NULL;
	return (new_elem);
}

void	put_pos(t_lst **pile_a)
{
	t_lst *tmp;
	int i;

	i = 1;
	tmp = *pile_a;
	while (tmp != NULL)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
}

int    initializing_pile(t_lst **pile_a, char **tab, int sign)
{
	int i;

	i = -1;
	if (check_arg(tab) == 1)
	{
		if (sign == 0)
			destroy_tab(tab);
		else
			free(tab);
		return (print_error());
	}
	else
	{
		while (tab[++i])
			lst_add_back(pile_a, ft_atoi(tab[i]), i); // Possible pb de malloc, a free.
	}
	return (0);
}

void	clear_lst(t_lst **pile)
{
	t_lst *tmp;

	tmp = *pile;
	if (pile)
	{
		while (*pile)
		{
			tmp = (*pile)->next;
			free (*pile);
			(*pile) = tmp;
		}
	}
}

int	lst_size(t_lst **pile)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = *pile;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
