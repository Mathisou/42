/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:38:56 by maroly            #+#    #+#             */
/*   Updated: 2022/01/08 16:52:32 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_first_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9')))
		i++;
	if (str[i] != '\0')
		return (0);
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	check_arg(char **tab)
{
	int			i;
	int			j;
	long long	check;

	i = 0;
	j = i + 1;
	check = ft_atoi(tab[i]);
	if (check_only_number(tab) == 1 || check < -2147483648
		|| check > 2147483647)
		return (1);
	while (tab[i] && tab[j])
	{
		while (tab[j])
		{
			check = ft_atoi(tab[j]);
			if (ft_strcmp(tab[i], tab[j]) == 0 || check < -2147483648
				|| check > 2147483647)
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	check_only_number(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (((((tab[i][j] == '-' || tab[i][j] == '+') && j == 0)
				&& tab[i][j + 1] >= '0' && tab[i][j + 1] <= '9'))
					|| (tab[i][j] >= '0' && tab[i][j] <= '9'))
				j++;
			else
				return (1);
		}
		i++;
		j = 0;
	}
	return (0);
}

int	check_pile(t_lst **pile_a)
{
	t_lst	*tmp;

	tmp = *pile_a;
	if (tmp == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		if (tmp->nb > tmp->next->nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_pile2(t_lst **pile_a)
{
	t_var	s;
	int		check;

	check = 0;
	s.tmp = *pile_a;
	s.posmin = s.tmp->pos;
	s.stockmin = s.tmp->nb;
	while (s.tmp->next != NULL)
	{
		if (take_stat(&s, &check) == 1)
			return (1);
		s.tmp = s.tmp->next;
	}
	if (s.posmin - 1 < lst_size(pile_a) - s.posmin + 1)
		while ((*pile_a)->pos != s.posmin)
			call_rx(pile_a, NULL, 1);
	else if (s.posmin - 1 >= lst_size(pile_a) - s.posmin + 1)
		while ((*pile_a)->pos != s.posmin)
			call_rrx(pile_a, NULL, 1);
	return (0);
}
