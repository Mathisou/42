/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:02:51 by maroly            #+#    #+#             */
/*   Updated: 2021/12/15 17:03:17 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	bonusplus(long nb, va_list args, const char *s, int count)
{
	int	stock;
	int	i;

	i = 0;
	if (*s == 'd' || *s == 'i')
	{
		stock = va_arg(args, int);
		while (++i < nb - 1)
			ft_putchar(' ');
		if (stock >= 0)
			count += ft_putchar('+');
		ft_putnbr(stock, &count, 2);
	}
	return (count);
}

int	bonussharp2(long nb, va_list args, const char *s, int sign)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (*s == 'c')
	{
		while (++i < nb - 1)
			count += zero_or_space(sign);
		count += ft_putchar(va_arg(args, int));
	}
	if (*s == '%')
	{
		while (++i < nb - 1)
			count += zero_or_space(sign);
		count += ft_putchar('%');
	}
	return (count);
}

int	bonussharp(long nb, va_list args, const char *s, int sign)
{
	unsigned int	stock;
	int				size;
	int				count;

	count = 0;
	if (*s == 'x' || *s == 'X')
	{
		stock = va_arg(args, unsigned int);
		size = decomp_number(stock, 16, 1) + 1;
		while (++size < nb && sign != 1)
			count += zero_or_space(sign);
		if (stock != 0 && *s == 'x')
			count += ft_putstr("0x");
		else if (stock != 0 && *s == 'X')
			count += ft_putstr("0X");
		while (++size < nb + 1 && sign == 1)
			count += zero_or_space(sign);
		if (*s == 'x')
			ft_dec_to_hexa(stock, 1, &count);
		else
			ft_dec_to_hexa(stock, 0, &count);
	}
	else
		count += bonussharp2(nb, args, s, sign);
	return (count);
}

int	bonusspace(long nb, va_list args, const char *s, int count)
{
	int	stock;

	if (*s == 's')
	{
		while (nb--)
			count += ft_putchar(' ');
		count += ft_putstr(va_arg(args, char *));
	}
	if (*s == 'd' || *s == 'i')
	{
		stock = va_arg(args, int);
		if (nb == 0 && stock >= 0)
			count += ft_putchar(' ');
		else if (nb > 0)
			while (nb--)
				count += ft_putchar(' ');
		ft_putnbr(stock, &count, 2);
	}
	return (count);
}
