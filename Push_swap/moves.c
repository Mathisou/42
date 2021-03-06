/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:37:16 by maroly            #+#    #+#             */
/*   Updated: 2022/01/08 13:30:51 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_lst **pile, int sign)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	if (lst_size(pile) < 2)
		return ;
	tmp = *pile;
	tmp2 = (*pile)->next;
	tmp->next = tmp->next->next;
	tmp2->next = tmp;
	*pile = tmp2;
	if (sign == 1)
		ft_putstr_fd("sa\n", 1);
	if (sign == 2)
		ft_putstr_fd("sb\n", 1);
	if (sign == 3)
		ft_putstr_fd("ss\n", 1);
}

void	px(t_lst **pile_from, t_lst **pile_to, int sign)
{
	t_lst	*tmp;

	if (lst_size(pile_from) < 1)
		return ;
	tmp = (*pile_from)->next;
	lst_add_front(pile_to, *pile_from);
	*pile_from = tmp;
	if (sign == 1)
		ft_putstr_fd("pa\n", 1);
	else if (sign == 2)
		ft_putstr_fd("pb\n", 1);
}

void	rx(t_lst **pile)
{
	t_lst	*tmp;
	int		swapnb;
	int		swappos;

	if (lst_size(pile) < 2)
		return ;
	tmp = (*pile)->next;
	swapnb = (*pile)->nb;
	swappos = (*pile)->pos;
	free(*pile);
	*pile = tmp;
	lst_add_back(pile, swapnb, swappos);
}

void	rrx(t_lst **pile)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	tmp = *pile;
	if (lst_size(pile) < 2)
		return ;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *pile;
	*pile = tmp2;
}
