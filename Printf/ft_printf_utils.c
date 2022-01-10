/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:40:18 by maroly            #+#    #+#             */
/*   Updated: 2021/12/15 17:01:36 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (6);
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	size_t			i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	if (result > 2147483647)
		return (2147483647);
	else if (result * sign < -2147483648)
		return (-2147483648);
	return (result * sign);
}

int	zero_or_space(int sign)
{
	if (sign != 2)
		return (ft_putchar('0'));
	else
		return (ft_putchar(' '));
}
