/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusminus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:03:26 by maroly            #+#    #+#             */
/*   Updated: 2021/12/15 17:04:05 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	bonusminus2(va_list args, const char *s)
{
	int	count;

	count = 0;
	if (*s == 'p')
	{
		count += write(1, "0x", 2);
		ft_dec_to_hexa(va_arg(args, unsigned long), 1, &count);
	}
	else if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(args, int), &count, 2);
	else if (*s == 'u')
		ft_putnbr(va_arg(args, unsigned int), &count, 0);
	else if (*s == 'x')
		ft_dec_to_hexa(va_arg(args, unsigned int), 1, &count);
	else if (*s == 'X')
		ft_dec_to_hexa(va_arg(args, unsigned int), 0, &count);
	else if (*s == '%')
		count += ft_putchar('%');
	else if (*s == 's')
		count += ft_putstr(va_arg(args, char *));
	return (count);
}

int	bonusminus(long nb, va_list args, const char *s, int count)
{
	int		tmp_count;
	int		diff;
	long	nbdot;

	tmp_count = count;
	nbdot = -1;
	if (nb < 0)
		nb = -nb;
	while ((*s >= '0' && *s <= '9') || *s == '-')
		s++;
	if (*s == '.')
		nbdot = ft_atoi(++s);
	while (*s >= '0' && *s <= '9')
		s++;
	if (nbdot >= 0)
		return (count += bonuswidthsminus(nb, nbdot, args, s));
	else if (*s == 'c')
		count += ft_putchar(va_arg(args, int));
	else
		count += bonusminus2(args, s);
	diff = count - tmp_count;
	while (diff++ < nb)
		count += ft_putchar(' ');
	return (count);
}
