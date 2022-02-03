/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:39:49 by maroly            #+#    #+#             */
/*   Updated: 2022/01/08 16:52:14 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (!(s1[i] == s2[i]))
			return (1);
		i++;
	}
	if (!(s1[i] == s2[i]))
		return (1);
	return (0);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (0);
}

int	is_under_point(t_lst **pile, int point)
{
	t_lst	*tmp;

	tmp = *pile;
	while (tmp != NULL)
	{
		if (point > tmp->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	take_stat(t_var *s, int *check)
{
	if (s->tmp->nb > s->tmp->next->nb)
	{
		s->posmin = s->tmp->next->pos;
		(*check)++;
	}
	if (s->tmp->nb < s->stockmin && check == 0)
		s->stockmin = s->tmp->nb;
	if (*check > 1)
		return (1);
	if (*check >= 1 && s->tmp->next->nb > s->stockmin)
		return (1);
	return (0);
}
