/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:38:36 by maroly            #+#    #+#             */
/*   Updated: 2022/01/07 22:38:46 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **sort_tab(char **tab)
{
	int i;
	int j;
	char *swap;
	
	i = 0;
	j = i + 1;
	while (tab[i] && tab[j])
	{
		while (tab[j])
		{
			if (ft_atoi(tab[i]) > ft_atoi(tab[j]))
			{
				swap = tab[i];
				tab[i] = tab[j];
				tab[j] = swap;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (tab);
}

int	find_point(int size, t_lst **pile, int sign)
{
	int i;
	t_lst *tmp;
	char **tab;
	int mid;
	
	i = -1;
	tab = malloc(sizeof(*tab) * (size + 1));
	if (!tab)
		return (0);
	tmp = *pile;
	while (tmp != NULL)
	{
		tab[++i] = ft_itoa(tmp->nb);
		tmp = tmp->next;
	}
	tab[++i] = NULL;
	sort_tab(tab);
	mid = ft_atoi(tab[size / sign]);
	free(tab);
	return (mid);
}