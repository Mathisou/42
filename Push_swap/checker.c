/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:00:52 by maroly            #+#    #+#             */
/*   Updated: 2022/01/10 13:17:42 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_moves2(char **tab, t_lst **pile_a, t_lst **pile_b, int i)
{
	if (ft_strcmp(tab[i], "rb") == 0)
		rx(pile_b);
	else if (ft_strcmp(tab[i], "rr") == 0)
	{
		rx(pile_a);
		rx(pile_b);
	}
	else if (ft_strcmp(tab[i], "rra") == 0)
		rrx(pile_a);
	else if (ft_strcmp(tab[i], "rrb") == 0)
		rrx(pile_b);
	else if (ft_strcmp(tab[i], "rrr") == 0)
	{
		rrx(pile_a);
		rrx(pile_b);
	}
}

void	exec_moves(char **tab, t_lst **pile_a, t_lst **pile_b)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "sa") == 0)
			sx(pile_a, 0);
		else if (ft_strcmp(tab[i], "sb") == 0)
			sx(pile_b, 0);
		else if (ft_strcmp(tab[i], "ss") == 0)
		{
			sx(pile_a, 0);
			sx(pile_b, 0);
		}
		else if (ft_strcmp(tab[i], "pa") == 0)
			px(pile_b, pile_a, 0);
		else if (ft_strcmp(tab[i], "pb") == 0)
			px(pile_a, pile_b, 0);
		else if (ft_strcmp(tab[i], "ra") == 0)
			rx(pile_a);
		else
			exec_moves2(tab, pile_a, pile_b, i);
		i++;
	}
}

int	split_main(t_lst **pile_a, t_varbns *s)
{
	s->tab = init_tab(s);
	if (!s->tab)
	{
		clear_lst(pile_a);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_lst		*pile_a;
	t_lst		*pile_b;
	t_varbns	s;

	pile_a = NULL;
	pile_b = NULL;
	s.new = NULL;
	s.buffer = NULL;
	s.count = 1;
	if (ac < 2)
		return (1);
	if (pre_init_pile(&pile_a, av, ac) == 1)
		return (1);
	if (pile_a == NULL || pile_a->next == NULL)
		return (ft_putstr("OK\n"));
	if (split_main(&pile_a, &s) == 1)
		return (1);
	exec_moves(s.tab, &pile_a, &pile_b);
	if (check_pile(&pile_a) == 1 || lst_size(&pile_b) > 0)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	destroy_tab(s.tab);
	clear_lst(&pile_a);
	return (0);
}
