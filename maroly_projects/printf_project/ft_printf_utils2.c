/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:43:19 by maroly            #+#    #+#             */
/*   Updated: 2021/12/15 16:43:32 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	decomp_number(long nb, int base, int sign)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		if (sign != 0)
			ft_putchar('-');
		else
			i++;
		nb = -nb;
	}
	while (nb >= base)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

int	destroy_tab(int count, long *tab)
{
	free(tab);
	return (count);
}

int	is_flag(char c, int sign)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if (sign == 1)
		str = " #-+.0123456789";
	else if (sign == 2)
		str = "pcsdiuxX%0123456789";
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
