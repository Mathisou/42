/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:14:43 by maroly            #+#    #+#             */
/*   Updated: 2021/12/15 16:39:34 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long nb, int *count, int sign)
{
	long long	result;

	result = 0;
	if (nb < 0)
	{
		(*count)++;
		if (sign == 2)
			write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		(*count)++;
		ft_putnbr(nb / 10, count, sign);
		result = nb % 10 + 48;
		write(1, &result, 1);
	}
	if (nb < 10)
	{
		(*count)++;
		result = nb + 48;
		write(1, &result, 1);
	}
	return (*count);
}

int	ft_dec_to_hexa(unsigned long nb, int sign, int *count)
{
	char	*str;
	char	c;

	if (sign == 1)
		str = "0123456789abcdef";
	else if (sign == 0)
		str = "0123456789ABCDEF";
	if (nb >= 16)
	{
		(*count)++;
		ft_dec_to_hexa(nb / 16, sign, count);
		c = str[nb % 16];
		write(1, &c, 1);
	}
	if (nb < 16)
	{
		(*count)++;
		c = str[nb % 16];
		write(1, &c, 1);
	}
	return (*count);
}

int	flag_check2(const char *s, va_list args, int count)
{
	int	i;

	i = 0;
	if (is_flag(s[i], 1) == 1)
	{
		while (is_flag(s[i], 1) == 1)
			i++;
		if (*s == '.')
			count += precision(ft_atoi(s + 1), args, &s[i], 0);
		else if (*s == '0')
			count += bonuswidths(ft_atoi(s), args, s, 1);
		else if (*s >= '1' && *s <= '9')
			count += bonuswidths(ft_atoi(s), args, s, 2);
		else if (*s == '+')
			count += bonusplus(ft_atoi(s + 1), args, &s[i], count);
		else if (*s == '-')
			count += bonusminus(ft_atoi(s + 1), args, s, count);
		else if (*s == '#')
			count += bonussharp(ft_atoi(s + 1), args, &s[i], 2);
		else if (*s == ' ')
			count += bonusspace(ft_atoi(s + 1), args, &s[i], count);
	}
	return (count);
}

int	flag_check(const char *s, va_list args)
{
	int	count;

	count = 0;
	if (*s == 'c')
		count += ft_putchar(va_arg(args, int));
	if (*s == 's')
		count += ft_putstr(va_arg(args, char *));
	if (*s == 'p')
	{
		count += write(1, "0x", 2);
		ft_dec_to_hexa(va_arg(args, long), 1, &count);
	}
	if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(args, int), &count, 2);
	if (*s == 'u')
		ft_putnbr(va_arg(args, unsigned int), &count, 2);
	if (*s == 'x')
		ft_dec_to_hexa(va_arg(args, unsigned int), 1, &count);
	if (*s == 'X')
		ft_dec_to_hexa(va_arg(args, unsigned int), 0, &count);
	if (*s == '%')
		count += write(1, "%", 1);
	return (flag_check2(s, args, count));
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += flag_check(&s[++i], args);
			if (is_flag(s[i], 1) == 1)
				while (is_flag(s[i], 1) == 1)
					i++;
			if (s[i] && is_flag(s[i], 2) == 1)
				i++;
		}
		else
			count += write(1, &s[i++], 1);
	}
	va_end(args);
	return (count);
}
