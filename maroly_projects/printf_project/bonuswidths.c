/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuswidths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:04:16 by maroly            #+#    #+#             */
/*   Updated: 2021/12/15 17:06:34 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	bonuswidths5(long *tab, va_list args, const char *s, int sign)
{
	unsigned int	stock;
	int				count;
	int				size;

	count = 0;
	if (*s == 'x' || *s == 'X')
	{
		stock = va_arg(args, unsigned int);
		size = decomp_number(stock, 16, 1);
		if (tab[1] == 0 && stock == 0)
			tab[0]++;
		while (--tab[0] > tab[1] - 1 && tab[0] > size - 1)
			count += ft_putchar(' ');
		if (size > tab[1])
			size = tab[1];
		while (size++ < tab[1])
			count += ft_putchar('0');
		if (*s == 'x' && !(tab[1] == 0 && stock == 0))
			ft_dec_to_hexa(stock, 1, &count);
		else if (*s == 'X' && !(tab[1] == 0 && stock == 0))
			ft_dec_to_hexa(stock, 0, &count);
	}
	else
		count += bonuswidths6(tab, args, s, sign);
	return (count);
}

int	bonuswidths4(long *tab, va_list args, const char *s, int sign)
{
	unsigned int	stock;
	int				count;
	int				size;

	count = 0;
	if (*s == 'u')
	{
		stock = va_arg(args, unsigned int);
		size = decomp_number(stock, 10, 1);
		if (tab[1] == 0 && stock == 0)
			tab[0]++;
		while (--tab[0] > tab[1] - 1 && tab[0] > size - 1)
			count += ft_putchar(' ');
		if (size > tab[1])
			size = tab[1];
		while (size++ < tab[1])
			count += ft_putchar('0');
		if (!(tab[1] == 0 && stock == 0))
			ft_putnbr(stock, &count, 2);
	}
	else
		count += bonuswidths5(tab, args, s, sign);
	return (count);
}

int	bonuswidths3(long *tab, va_list args, const char *s, int sign)
{
	int	count;
	int	stock;
	int	size;

	count = 0;
	if (*s == 'd' || *s == 'i')
	{
		stock = va_arg(args, int);
		size = decomp_number(stock, 10, 0);
		if (size < tab[1])
			size = tab[1];
		if (stock == 0 && tab[1] == 0)
			tab[0]++;
		while ((tab[0]-- > size && tab[0] > tab[1] && stock < 0)
			|| (tab[0] > size - 1 && stock >= 0))
			count += ft_putchar(' ');
		size = decomp_number(stock, 10, 1);
		while (size++ < tab[1])
			count += ft_putchar('0');
		if (!(stock == 0 && tab[1] == 0))
			ft_putnbr(stock, &count, 0);
	}
	else
		count += bonuswidths4(tab, args, s, sign);
	return (count);
}

int	bonuswidths2(long *tab, va_list args, const char *s, int sign)
{
	int	stock;
	int	count;
	int	size;

	count = 0;
	if (*s == 'p')
	{
		stock = va_arg(args, long);
		size = decomp_number(stock, 16, 1);
		while (--tab[0] > tab[1] + 1 && tab[0] > size + 1)
			count += ft_putchar(' ');
		count += write(1, "0x", 2);
		if (size > tab[1])
			size = tab[1];
		while (size++ < tab[1] && tab[0] > size + 1)
			count += ft_putchar('0');
		ft_dec_to_hexa(stock, 1, &count);
	}
	else
		count += bonuswidths3(tab, args, s, sign);
	return (count);
}

int	bonuswidths(long nb, va_list args, const char *s, int sign)
{
	int		count;
	long	*tab;

	count = 0;
	tab = malloc(sizeof(*tab) * 3);
	if (!tab)
		return (0);
	tab[0] = nb;
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s == '.')
		tab[1] = ft_atoi(++s);
	else
		return (destroy_tab(precision(nb, args, s, sign), tab));
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s == 'c')
	{
		while (--tab[0])
			count += zero_or_space(sign);
		count += ft_putchar(va_arg(args, int));
	}
	else
		count += bonuswidths2(tab, args, s, sign);
	return (destroy_tab(count, tab));
}
