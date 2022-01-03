/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuswidthsminus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:01:51 by maroly            #+#    #+#             */
/*   Updated: 2021/12/15 17:02:32 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	bonuswidthsminus5(long nb, va_list args, const char *s, int nbdot)
{
	unsigned int	stock;
	int				count;
	int				size;

	count = 0;
	size = 0;
	if (*s == 'x' || *s == 'X')
	{
		stock = va_arg(args, unsigned int);
		size = decomp_number(stock, 16, 1);
		while (size++ < nbdot)
			count += ft_putchar('0');
		if (*s == 'x' && !(nbdot == 0 && stock == 0))
			ft_dec_to_hexa(stock, 1, &count);
		else if (*s == 'X' && !(nbdot == 0 && stock == 0))
			ft_dec_to_hexa(stock, 0, &count);
		size = decomp_number(stock, 16, 1);
		if (nbdot == 0 && stock == 0)
			nb++;
		while (--nb > nbdot - 1 && nb > size - 1)
			count += ft_putchar(' ');
	}
	else
		count += bonuswidthsminus6(nb, args, s);
	return (count);
}

int	bonuswidthsminus4(long nb, va_list args, const char *s, int nbdot)
{
	unsigned int	stock;
	int				count;
	int				size;

	count = 0;
	size = 0;
	if (*s == 'u')
	{
		stock = va_arg(args, unsigned int);
		size = decomp_number(stock, 10, 1);
		while (size++ < nbdot)
			count += ft_putchar('0');
		if (!(nbdot == 0 && stock == 0))
			ft_putnbr(stock, &count, 2);
		size = decomp_number(stock, 10, 1);
		if (nbdot == 0 && stock == 0)
			nb++;
		while (--nb > nbdot - 1 && nb > size - 1)
			count += ft_putchar(' ');
	}
	else
		count += bonuswidthsminus5(nb, args, s, nbdot);
	return (count);
}

int	bonuswidthsminus3(long nb, va_list args, const char *s, int nbdot)
{
	int	count;
	int	stock;
	int	size;

	count = 0;
	if (*s == 'd' || *s == 'i')
	{
		stock = va_arg(args, int);
		size = decomp_number(stock, 10, 1);
		while (size++ < nbdot)
			count += ft_putchar('0');
		if (!(nbdot == 0 && stock == 0))
			ft_putnbr(stock, &count, 0);
		size = decomp_number(stock, 10, 0);
		if (nbdot == 0 && stock == 0)
			nb++;
		if (nbdot >= size && stock < 0)
			nb--;
		while (--nb > nbdot - 1 && nb > size - 1)
			count += ft_putchar(' ');
	}
	else
		count += bonuswidthsminus4(nb, args, s, nbdot);
	return (count);
}

int	bonuswidthsminus2(long nb, va_list args, const char *s, long nbdot)
{
	int	stock;
	int	count;
	int	size;

	count = 0;
	if (*s == 'p')
	{
		stock = va_arg(args, long);
		size = decomp_number(stock, 16, 1);
		count += write(1, "0x", 2);
		while (size++ < nbdot)
			count += ft_putchar('0');
		ft_dec_to_hexa(stock, 1, &count);
		size = decomp_number(stock, 16, 1);
		while (--nb > nbdot + 1)
			count += ft_putchar(' ');
	}
	else
		return (count += bonuswidthsminus3(nb, args, s, nbdot));
	return (count);
}

int	bonuswidthsminus(long nb, long nbdot, va_list args, const char *s)
{
	char	*str;
	int		size;
	int		count;

	count = 0;
	if (*s == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		size = ft_strlen(str);
		if (size > nbdot)
			size = nbdot;
		while (nbdot-- && *str)
			count += ft_putchar(*str++);
		while (size++ < nb)
			count += zero_or_space(2);
	}
	else
		return (count += bonuswidthsminus2(nb, args, s, nbdot));
	return (count);
}
