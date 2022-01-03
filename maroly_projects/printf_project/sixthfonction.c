/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sixthfonction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:30:48 by maroly            #+#    #+#             */
/*   Updated: 2021/12/15 16:41:31 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	bonuswidthsminus6(long nb, va_list args, const char *s)
{
	int	count;

	count = 0;
	if (*s == '%')
	{
		count += ft_putchar('%');
		while (--nb)
			count += zero_or_space(2);
	}
	else if (*s == 'c')
	{
		count += ft_putchar(va_arg(args, int));
		while (nb-- > 1)
			count += zero_or_space(2);
	}
	return (count);
}

int	bonuswidths6(long *tab, va_list args, const char *s, int sign)
{
	int		count;
	char	*str;
	int		size;

	count = 0;
	if (*s == '%')
	{
		while (--tab[0])
			count += zero_or_space(sign);
		count += ft_putchar('%');
	}
	else if (*s == 's')
	{
		str = va_arg(args, char *);
		size = ft_strlen(str);
		if (size > tab[1])
			size = tab[1];
		while (size++ < tab[0])
			count += zero_or_space(sign);
		while (*str && tab[1]--)
			count += ft_putchar(*(str++));
	}
	return (count);
}

int	precision6(long nb, va_list args, const char *s, int sign)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (*s == 'c')
	{
		while (++i < nb - 1)
			count += zero_or_space(sign);
		count += ft_putchar(va_arg(args, int));
	}
	else if (*s == '%')
	{
		while (++i < nb - 1)
			count += zero_or_space(sign);
		count += ft_putchar('%');
	}
	return (count);
}
