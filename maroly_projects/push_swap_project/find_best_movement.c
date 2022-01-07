/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:28:49 by maroly            #+#    #+#             */
/*   Updated: 2022/01/07 22:29:03 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_best_movement2(t_lst **pile_a, t_lst **pile_b, t_var *s)
{
	if (s->posmin - 1 <= lst_size(pile_b) - s->posmin + 1
		&& s->posfirst - 1 > lst_size(pile_a) - s->posfirst + 1)
	{
        while ((*pile_b)->pos != s->posmin)
            call_rx(pile_a, pile_b, 2);
	    while ((*pile_a)->pos != s->posfirst)
			call_rrx(pile_a, pile_b, 1);
		px(pile_b, pile_a, 1);
	}
	else if (s->posmin - 1 > lst_size(pile_b) - s->posmin + 1
		&& s->posfirst - 1 <= lst_size(pile_a) - s->posfirst + 1)
	{
		while ((*pile_b)->pos != s->posmin)
            call_rrx(pile_a, pile_b, 2);
		while ((*pile_a)->pos != s->posfirst)
			call_rx(pile_a, pile_b, 1);
		px(pile_b, pile_a, 1);
    }
}

void	find_best_movement(t_lst **pile_a, t_lst **pile_b, t_var *s)
{
	if (s->posmin - 1 <= lst_size(pile_b) - s->posmin + 1
		&& s->posfirst - 1 <= lst_size(pile_a) - s->posfirst + 1)
	{
		while ((*pile_b)->pos != s->posmin && (*pile_a)->pos != s->posfirst)
			call_rx(pile_a, pile_b, 3);
        while ((*pile_b)->pos != s->posmin)
            call_rx(pile_a, pile_b, 2);
        while ((*pile_a)->pos != s->posfirst)
            call_rx(pile_a, pile_b, 1);
		px(pile_b, pile_a, 1);
	}
	else if (s->posmin - 1 > lst_size(pile_b) - s->posmin + 1
		&& s->posfirst - 1 > lst_size(pile_a) - s->posfirst + 1)
	{
		while ((*pile_b)->pos != s->posmin && (*pile_a)->pos != s->posfirst)
			call_rrx(pile_a, pile_b, 3);
        while ((*pile_b)->pos != s->posmin)
            call_rrx(pile_a, pile_b, 2);
        while ((*pile_a)->pos != s->posfirst)
            call_rrx(pile_a, pile_b, 1);
		px(pile_b, pile_a, 1);
	}
    else
		find_best_movement2(pile_a, pile_b, s);
}