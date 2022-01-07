/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:25:33 by maroly            #+#    #+#             */
/*   Updated: 2022/01/07 22:26:05 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    call_rrx(t_lst **pile_a, t_lst **pile_b, int sign)
{
    if (sign == 1)
    {
        rrx(pile_a);
        ft_putstr_fd("rra\n", 1);
    }
    else if (sign == 2)
    {
        rrx(pile_b);
        ft_putstr_fd("rrb\n", 1);
    }
    else if (sign == 3)
    {
        rrx(pile_a);
        rrx(pile_b);
        ft_putstr_fd("rrr\n", 1);
    }
}

void    call_rx(t_lst **pile_a, t_lst **pile_b, int sign)
{
    if (sign == 1)
    {
        rx(pile_a);
        ft_putstr_fd("ra\n", 1);
    }
    else if (sign == 2)
    {
        rx(pile_b);
        ft_putstr_fd("rb\n", 1);
    }
    else if (sign == 3)
    {
        rx(pile_a);
        rx(pile_b);
        ft_putstr_fd("rr\n", 1);
    }
}