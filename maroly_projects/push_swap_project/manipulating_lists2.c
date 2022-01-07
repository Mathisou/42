/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulating_lists2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:31:50 by maroly            #+#    #+#             */
/*   Updated: 2022/01/07 22:32:29 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    lst_add_back(t_lst **pile_a, int nb, int pos)
{
	t_lst *tmp;

	tmp = *pile_a;
	if (*pile_a == NULL)
		*pile_a = new_elem(nb, pos);
	else
	{
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_elem(nb, pos);
	}
}

void    lst_add_front(t_lst **pile, t_lst *new)
{
    if (new)
    {
        new->next = *pile;
        *pile = new; 
    }
}