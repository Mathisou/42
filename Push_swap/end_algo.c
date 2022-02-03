/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:19:33 by maroly            #+#    #+#             */
/*   Updated: 2022/01/08 13:35:12 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_mvt(t_lst **pile_b, t_var *s)
{
	s->tmp = *pile_b;
	s->stockmin = (*pile_b)->nb_mvt;
	s->posmin = (*pile_b)->pos;
	s->posfirst = (*pile_b)->link_pos;
	while (s->tmp != NULL)
	{
		if (s->tmp->nb_mvt < s->stockmin)
		{
			s->stockmin = s->tmp->nb_mvt;
			s->posmin = s->tmp->pos;
			s->posfirst = s->tmp->link_pos;
		}
		s->tmp = s->tmp->next;
	}
}

void	find_smallest_above_nb(t_lst **pile_a, t_lst **pile_b, t_var *s)
{
	s->stockmax = (*pile_a)->nb;
	s->stockmin = s->tmp2->nb;
	s->tmp = *pile_a;
	if (s->tmp2->pos - 1 <= lst_size(pile_b) - s->tmp2->pos + 1)
		s->tmp2->to_top_here = s->tmp2->pos - 1;
	else
		s->tmp2->to_top_here = lst_size(pile_b) - s->tmp2->pos + 1;
	while (s->tmp != NULL)
	{
		if (s->tmp->nb > s->stockmax)
			s->stockmax = s->tmp->nb;
		s->tmp = s->tmp->next;
	}
	s->tmp = *pile_a;
	while (s->tmp != NULL)
	{
		if (s->tmp->nb > s->stockmin && s->tmp->nb <= s->stockmax)
		{
			s->stockmax = s->tmp->nb;
			s->posfirst = s->tmp->pos;
		}
		s->tmp = s->tmp->next;
	}
}

void	find_nb_mvt(t_lst **pile_a, t_var *s)
{
	s->tmp2->nb_link = s->stockmax;
	s->tmp2->link_pos = s->posfirst;
	if (s->posfirst - 1 <= lst_size(pile_a) - s->posfirst + 1)
		s->tmp2->to_top_link = s->posfirst - 1;
	else
		s->tmp2->to_top_link = lst_size(pile_a) - s->posfirst + 1;
	s->tmp2->nb_mvt = s->tmp2->to_top_here + s->tmp2->to_top_link;
}

void	end_algo(t_lst **pile_a, t_lst **pile_b)
{
	t_var	s;

	put_pos(pile_a);
	put_pos(pile_b);
	s.tmp2 = *pile_b;
	while (s.tmp2 != NULL)
	{
		find_smallest_above_nb(pile_a, pile_b, &s);
		find_nb_mvt(pile_a, &s);
		s.tmp2 = s.tmp2->next;
	}
	find_min_mvt(pile_b, &s);
	find_best_movement(pile_a, pile_b, &s);
}
