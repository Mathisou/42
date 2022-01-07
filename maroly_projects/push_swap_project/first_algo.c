/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:37:57 by maroly            #+#    #+#             */
/*   Updated: 2022/01/07 22:42:23 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra_or_rra(t_lst **pile_a, t_lst **pile_b, t_var s)
{
	if (s.posfirst - 1 <= s.size - s.poslast + 1)
	{
		while ((*pile_a)->pos != s.posfirst)
			call_rx(pile_a, pile_b, 1);
		px(pile_a, pile_b, 2);
	}
	else
	{
		while ((*pile_a)->pos != s.poslast)
			call_rrx(pile_a, pile_b, 1);
		px(pile_a, pile_b, 2);
	}
}

void	search_pos(t_lst **pile_a, t_var *s)
{
	put_pos(pile_a);
	s->posfirst = 0;
	s->poslast = 0;
	s->tmp = *pile_a;
	s->stockmax = s->tmp->nb;
	while (s->tmp != NULL)
	{
		if (s->tmp->nb < s->point && s->posfirst == 0)
			s->posfirst = s->tmp->pos;
		if (s->tmp->nb < s->point)
			s->poslast = s->tmp->pos;
		if (s->tmp->nb > s->stockmax)
			s->stockmax = s->tmp->nb;
		s->tmp = s->tmp->next;
	}
}

void	algo_above10(t_lst **pile_a, t_lst **pile_b)
{
	t_var s;

	s.size = lst_size(pile_a);
	s.point = find_point(s.size, pile_a, 2);
	while (is_under_point(pile_a, s.point) == 0)
	{
		search_pos(pile_a, &s);
		ra_or_rra(pile_a, pile_b, s);
	}
	while (lst_size(pile_a) > 1)
	{
		if ((*pile_a)->nb != s.stockmax)
			px(pile_a, pile_b, 2);
		else
			call_rx(pile_a, pile_b, 1);
	}
}

void	algo_10_and_under(t_lst **pile_a, t_lst **pile_b)
{
	t_var s;
	
	put_pos(pile_a);
	s.tmp = *pile_a;
	s.stockmin = s.tmp->nb;
	s.posmin = s.tmp->pos;
	s.size = lst_size(pile_a);
	while (s.tmp != NULL)
	{
		if (s.tmp->nb < s.stockmin)
		{
			s.stockmin = s.tmp->nb;
			s.posmin = s.tmp->pos;
		}
		s.tmp = s.tmp->next;
	}
	if (s.posmin == 1)
		px(pile_a, pile_b, 2);
	else if ((*pile_a)->nb > (*pile_a)->next->nb)
		sa(pile_a);
	else
		call_rrx(pile_a, pile_b, 1);
}