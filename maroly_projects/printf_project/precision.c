/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:51:25 by maroly            #+#    #+#             */
/*   Updated: 2021/12/15 16:43:07 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	precision5(long nb, va_list args, const char *s, int sign)
{
	int	stock;
	int	size;
	int	count;

	count = 0;
	if (*s == 'd' || *s == 'i')
	{
		stock = va_arg(args, int);
		if (nb == 0 && stock == 0)
			return (count);
		if (sign != 2)
			size = decomp_number(stock, 10, 1);
		else
			size = decomp_number(stock, 10, 0);
		if (stock < 0 && sign == 1)
			size++;
		while (size++ < nb)
			count += zero_or_space(sign);
		ft_putnbr(stock, &count, sign);
	}
	else
		return (count += precision6(nb, args, s, sign));
	return (count);
}

int	precision4(long nb, va_list args, const char *s, int sign)
{
	unsigned int	stock;
	int				size;
	int				count;

	count = 0;
	if (*s == 'u')
	{
		stock = va_arg(args, unsigned int);
		if (nb == 0 && stock == 0)
			return (count);
		size = decomp_number(stock, 10, 0);
		while (size++ < nb)
			count += zero_or_space(sign);
		ft_putnbr(stock, &count, 1);
	}
	else
		return (count += precision5(nb, args, s, sign));
	return (count);
}

int	precision3(long nb, va_list args, const char *s, int sign)
{
	char	*str;
	int		i;
	int		size;
	int		count;

	count = 0;
	i = -1;
	if (*s == 's')
	{
		str = va_arg(args, char *);
		size = ft_strlen(str);
		while (size++ < nb && sign != 0)
			count += zero_or_space(sign);
		if (str == NULL)
			str = "(null)";
		while ((str[++i] && sign != 0) || (str[i] && (i < nb && sign == 0)))
			count += ft_putchar(str[i]);
	}
	else
		return (count += precision4(nb, args, s, sign));
	return (count);
}

int	precision2(long nb, va_list args, const char *s, int sign)
{
	int				size;
	unsigned int	stock;
	int				count;

	count = 0;
	if (*s == 'x' || *s == 'X')
	{
		stock = va_arg(args, unsigned int);
		if (nb == 0 && stock == 0)
			return (count);
		size = decomp_number(stock, 16, 1);
		while (size++ < nb)
			count += zero_or_space(sign);
		if (*s == 'x')
			ft_dec_to_hexa(stock, 1, &count);
		else
			ft_dec_to_hexa(stock, 0, &count);
	}
	else
		return (count += precision3(nb, args, s, sign));
	return (count);
}

int	precision(long nb, va_list args, const char *s, int sign)
{
	int				size;
	unsigned long	ulstock;
	int				count;

	count = 0;
	if (*s == 'p')
	{
		ulstock = va_arg(args, long);
		size = decomp_number(ulstock, 16, 0);
		while (size++ < nb - 2 && sign == 2)
			count += zero_or_space(sign);
		count += ft_putstr("0x");
		while (size++ < nb + 1 && sign == 0)
			count += zero_or_space(sign);
		while (size++ < nb && sign == 1)
			count += zero_or_space(sign);
		ft_dec_to_hexa(ulstock, 1, &count);
	}
	else
		return (count += precision2(nb, args, s, sign));
	return (count);
}
