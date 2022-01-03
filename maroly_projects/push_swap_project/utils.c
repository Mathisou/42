/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:39:49 by maroly            #+#    #+#             */
/*   Updated: 2022/01/03 18:40:12 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int print_error()
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int ft_strcmp(char *s1, char *s2)
{
	int i;

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