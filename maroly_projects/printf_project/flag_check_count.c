/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:04:24 by maroly            #+#    #+#             */
/*   Updated: 2021/12/01 16:22:19 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	flag_check_count3(char c, va_list args)
{
	int					count;
	unsigned long long	ullmax;
	long long			nb;

	count = 0;
	ullmax = 18446744073709551615U;
	if (c == 'p')
	{
		nb = va_arg(args, long long);
		if (nb > -2147483648 && nb < -1)
			return (dec_to_hex_addr_count(ullmax + nb, &count) + 3);
		else if (nb == -1)
			return (dec_to_hex_addr_count(ullmax, &count) + 3);
		else
			return (dec_to_hex_addr_count(nb, &count) + 3);
	}
	return (0);
}

int	flag_check_count2(char c, va_list args)
{
	int	nb;
	int	count;

	count = 0;
	if (c == 'X' || c == 'x')
	{
		nb = va_arg(args, int);
		if (nb >= -2147483648 && nb < 0)
			return (dec_to_hex_count(4294967295 + nb, &count));
		else
			return (dec_to_hex_count(nb, &count));
	}
	else if (c == 'u')
	{
		nb = va_arg(args, int);
		if (nb >= -2147483648 && nb < 0)
			return (decomp_number(4294967295 + nb));
		else
			return (decomp_number(nb));
	}
	else
		return (flag_check_count3(c, args));
	return (0);
}

int	flag_check_count(char c, va_list args)
{
	int			count;

	count = 0;
	if (c == 'c')
	{
		va_arg(args, int);
		return (1);
	}
	else if (c == 's')
		return (ft_strlen(va_arg(args, const char *)));
	else if (c == 'd' || c == 'i')
		return (decomp_number(va_arg(args, int)));
	else if (c == '%')
		return (1);
	else
		return (flag_check_count2(c, args));
	return (0);
}
