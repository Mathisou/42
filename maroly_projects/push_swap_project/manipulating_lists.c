/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulating_lists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:12:05 by maroly            #+#    #+#             */
/*   Updated: 2022/01/04 12:31:26 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

nb_list *new_elem(int nb)
{
	nb_list *new_elem;

	new_elem = malloc(sizeof(nb_list));
	if (new_elem == NULL)
		return (NULL);
	new_elem->nb = nb;
	new_elem->next = NULL;
	return (new_elem);
}

void    lst_add_back(nb_list **pile_a, int nb)
{
	nb_list *tmp;

	tmp = *pile_a;
	if (*pile_a == NULL)
		*pile_a = new_elem(nb);
	else
	{
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_elem(nb);
	}
}

int    initializing_l(nb_list **pile_a, char **tab, int sign)
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
			lst_add_back(pile_a, ft_atoi(tab[i])); // Possible pb de malloc, a free.
	}
	return (0);
}

void	clear_lst(nb_list **pile)
{
	nb_list *tmp;

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

void    lst_add_front(nb_list **pile, nb_list *new)
{
    if (new)
    {
        new->next = *pile;
        *pile = new; 
    }
}

int	lst_size(nb_list **pile)
{
	int		i;
	nb_list	*tmp;

	i = 0;
	tmp = *pile;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
