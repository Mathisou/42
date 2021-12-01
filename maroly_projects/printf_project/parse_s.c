/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:18:36 by maroly            #+#    #+#             */
/*   Updated: 2021/12/01 14:50:21 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	decomp_number(long long nb)
{
	int	count;

	count = 1;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int	dec_to_hex_addr_count(unsigned long long nb, int *count)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nb >= 16)
	{
		(*count)++;
		dec_to_hex_addr_count(nb / 16, count);
	}
	return (*count);
}

int	dec_to_hex_count(long long nb, int *count)
{
	char				*hexa;
	unsigned long long	n;

	n = (unsigned long long)nb;
	if (nb < -2147483648)
		return (1);
	if (n > 4294967295)
		n = 4294967295;
	hexa = "0123456789abcdef";
	if (n >= 16)
	{
		(*count)++;
		dec_to_hex_count(n / 16, count);
	}
	if (n < 16)
		(*count)++;
	return (*count);
}

int	parse_s(const char *s, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && (s[i + 1] == 'c' || s[i + 1] == 's'
				|| s[i + 1] == 'p' || s[i + 1] == 'd'
				|| s[i + 1] == 'i' || s[i + 1] == 'u'
				|| s[i + 1] == 'x' || s[i + 1] == 'X' || s[i + 1] == '%'))
		{
			count += flag_check_count(s[++i], args);
			i++;
		}
		else
		{
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
