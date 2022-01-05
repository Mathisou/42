/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_power_of_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:16:41 by maroly            #+#    #+#             */
/*   Updated: 2021/10/18 18:17:00 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_power_of_2(int nb)
{
	int	i;
	int	b;

	i = 2;
	b = 2;
	while (i <= nb)
	{
		if (i == nb)
			return (1);
		i = i * b;
	}
	return (0);
}
