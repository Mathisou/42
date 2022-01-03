/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:28:00 by maroly            #+#    #+#             */
/*   Updated: 2022/01/03 19:53:07 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	char **tab;
	nb_list *pile_a;
	//nb_list *pile_b;
	int i;

	i = -1;
	pile_a = NULL;
	//pile_b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2 && check_first_arg(av[1]) == 0)
	{
		tab = ft_split(av[1], ' ');
		if (initializing_l(&pile_a, tab, 0) == 1)
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
		if (initializing_l(&pile_a, tab, 1) == 1)
			return (1);
		free(tab);
	}
	//pb(&pile_a, &pile_b);
	//pb(&pile_a, &pile_b);
	//pa(&pile_a, &pile_b);
	//sa(&pile_a);
	rra(&pile_a);
	/*while (pile_b != NULL)
	{
		printf("%d\n", pile_b->nb);
		pile_b = pile_b->next;
	}*/
	printf("|||\n");
	while (pile_a != NULL)
	{
		printf("%d\n", pile_a->nb);
		pile_a = pile_a->next;
	}
	clear_lst(&pile_a);
}