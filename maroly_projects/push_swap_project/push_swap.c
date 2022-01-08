/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:28:00 by maroly            #+#    #+#             */
/*   Updated: 2022/01/08 15:39:56 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos(t_lst **pile_a)
{
	t_var	s;

	s.tmp = *pile_a;
	s.stockmax = s.tmp->nb;
	s.posmax = s.tmp->pos;
	while (s.tmp != NULL)
	{
		if (s.tmp->nb > s.stockmax)
		{
			s.stockmax = s.tmp->nb;
			s.posmax = s.tmp->pos;
		}
		s.tmp = s.tmp->next;
	}
	return (s.posmax);
}

void	launch_algo(t_lst **pile_a, t_lst **pile_b)
{
	if (lst_size(pile_a) < 10)
		while (check_pile(pile_a) == 1)
			algo_10_and_under(pile_a, pile_b);
	else
		algo_above10(pile_a, pile_b);
	while (lst_size(pile_b) > 0)
		end_algo(pile_a, pile_b);
	while (check_pile(pile_a) == 1 && find_max_pos(pile_a) - 1
		<= lst_size(pile_a) - find_max_pos(pile_a) + 1)
		call_rx(pile_a, pile_b, 1);
	while (check_pile(pile_a) == 1 && find_max_pos(pile_a) - 1
		> lst_size(pile_a) - find_max_pos(pile_a) + 1)
		call_rrx(pile_a, pile_b, 1);
}

int	pre_init_pile(t_lst **pile_a, char **av, int ac)
{
	char	**tab;
	int		i;

	i = -1;
	if (ac == 2 && check_first_arg(av[1]) == 0)
	{
		tab = ft_split(av[1], ' ');
		if (initializing_pile(pile_a, tab, 0) == 1)
			return (1);
		destroy_tab(tab);
	}
	else if (ac > 2)
	{
		tab = malloc(sizeof(*tab) * ac);
		if (!tab)
			return (1);
		while (++i < ac - 1)
			tab[i] = av[i + 1];
		tab[i] = NULL;
		if (initializing_pile(pile_a, tab, 1) == 1)
			return (1);
		free(tab);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_lst	*pile_a;
	t_lst	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	if (ac < 2)
		return (print_error());
	else if (pre_init_pile(&pile_a, av, ac) == 1)
		return (1);
	if (pile_a == NULL || pile_a->next == NULL)
		return (0);
	if (check_pile(&pile_a) == 0)
		return (0);
	launch_algo(&pile_a, &pile_b);
	clear_lst(&pile_a);
}
