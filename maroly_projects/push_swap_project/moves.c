/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:37:16 by maroly            #+#    #+#             */
/*   Updated: 2022/01/04 12:37:16 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(nb_list **pile_a)
{
    nb_list *tmp;
    int swap1;
    int swap2;

    tmp = *pile_a;
    if (lst_size(pile_a) < 2)
		return ;
    swap1 = tmp->nb;
    swap2 = tmp->next->nb;
    tmp->nb = swap2;
    tmp->next->nb = swap1;
    ft_putstr_fd("sa\n", 1);
}

void    sb(nb_list **pile_b)
{
    nb_list *tmp;
    int swap1;
    int swap2;

    tmp = *pile_b;
    if (lst_size(pile_b) < 2)
		return ;
    swap1 = tmp->nb;
    swap2 = tmp->next->nb;
    tmp->nb = swap2;
    tmp->next->nb = swap1;
    ft_putstr_fd("sb\n", 1);
}

void    ss(nb_list **pile_a, nb_list **pile_b)
{
    nb_list *tmp;
    int swap1;
    int swap2;

    tmp = *pile_a;
    if (lst_size(pile_a) < 2)
		return ;
    swap1 = tmp->nb;
    swap2 = tmp->next->nb;
    tmp->nb = swap2;
    tmp->next->nb = swap1;
    tmp = *pile_b;
    if (lst_size(pile_b) < 2)
		return ;
    swap1 = tmp->nb;
    swap2 = tmp->next->nb;
    tmp->nb = swap2;
    tmp->next->nb = swap1;
    ft_putstr_fd("ss\n", 1);
}

void    pa(nb_list **pile_a, nb_list **pile_b)
{
    nb_list *tmp;

	if (lst_size(pile_b) < 1)
		return ;
    tmp = (*pile_b)->next;
    lst_add_front(pile_a, *pile_b);
    *pile_b = tmp;    
    ft_putstr_fd("pa\n", 1);
}

void    pb(nb_list **pile_a, nb_list **pile_b)
{
    nb_list *tmp;

	if (lst_size(pile_a) < 1)
		return ;
    tmp = (*pile_a)->next;
    lst_add_front(pile_b, *pile_a);
    *pile_a = tmp;
    ft_putstr_fd("pb\n", 1);
}

void    ra(nb_list **pile_a)
{
    nb_list *tmp;
    int swap;

	if (lst_size(pile_a) < 2)
		return ;
    tmp = (*pile_a)->next;
    swap = (*pile_a)->nb;
    free(*pile_a);
    *pile_a = tmp;
    lst_add_back(pile_a, swap);
    ft_putstr_fd("ra\n", 1);
}

void    rb(nb_list **pile_b)
{
    nb_list *tmp;
    int swap;

	if (lst_size(pile_b) < 2)
		return ;
    tmp = (*pile_b)->next;
    swap = (*pile_b)->nb;
    free(*pile_b);
    *pile_b = tmp;
    lst_add_back(pile_b, swap);
    ft_putstr_fd("rn\n", 1);
}

void    rr(nb_list **pile_a, nb_list **pile_b)
{
    nb_list *tmp;
    int swap;

	if (lst_size(pile_a) < 2)
		return ;
    tmp = (*pile_a)->next;
    swap = (*pile_a)->nb;
    free(*pile_a);
    *pile_a = tmp;
    lst_add_back(pile_a, swap);
	if (lst_size(pile_b) < 2)
		return ;
    tmp = (*pile_b)->next;
    swap = (*pile_b)->nb;
    free(*pile_b);
    *pile_b = tmp;
    lst_add_back(pile_b, swap);
    ft_putstr_fd("rr\n", 1);
}

void    rra(nb_list **pile_a)
{
    nb_list *tmp;
	nb_list *tmp2;

    tmp = *pile_a;
	if (lst_size(pile_a) < 2)
		return ;
    while (tmp->next->next != NULL)
        tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *pile_a;
	*pile_a = tmp2;
    ft_putstr_fd("rra\n", 1);
}

void    rrb(nb_list **pile_b)
{
    nb_list *tmp;
	nb_list *tmp2;

    tmp = *pile_b;
	if (lst_size(pile_b) < 2)
		return ;
    while (tmp->next->next != NULL)
        tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *pile_b;
	*pile_b = tmp2;
    ft_putstr_fd("rrb\n", 1);
}

void    rrr(nb_list **pile_a, nb_list **pile_b)
{
    nb_list *tmp;
	nb_list *tmp2;

	tmp = *pile_a;
	if (lst_size(pile_a) < 2)
		return ;
    while (tmp->next->next != NULL)
        tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *pile_a;
	*pile_a = tmp2;
    tmp = *pile_b;
	if (lst_size(pile_b) < 2)
		return ;
    while (tmp->next->next != NULL)
        tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *pile_b;
	*pile_b = tmp2;
    ft_putstr_fd("rrr\n", 1);
}