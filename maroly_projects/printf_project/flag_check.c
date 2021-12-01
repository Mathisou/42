/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:04:32 by maroly            #+#    #+#             */
/*   Updated: 2021/12/01 14:59:49 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	flag_check3(va_list args, const char *s)
{
	int	nb;

	if (*s == 'x')
	{
		nb = va_arg(args, int);
		if (nb >= -2147483648 && nb < 0)
			dec_to_hex_x(4294967296 + nb);
		else
			dec_to_hex_x(nb);
	}
	else if (*s == 'X')
	{	
		nb = va_arg(args, int);
		if (nb >= -2147483648 && nb < 0)
			dec_to_hex_upperx(4294967296 + nb);
		else
			dec_to_hex_upperx(nb);
	}
}

void	flag_check2(va_list args, const char *s)
{
	int	nb;

	if (*s == 'u')
	{
		nb = va_arg(args, int);
		if (nb >= -2147483648 && nb < 0)
			ft_putnbr(4294967296 + nb);
		else if (nb < -2147483648)
			ft_putchar('0');
		else
			ft_putnbr(nb);
	}
	else if (*s == '%')
		ft_putchar(37);
	else
		flag_check3(args, s);
}

void	flag_check(va_list args, const char *s)
{
	long	nb;

	if (*s == 'c')
		ft_putchar(va_arg(args, int));
	else if (*s == 's')
		ft_putstr(va_arg(args, char *));
	else if (*s == 'p')
	{
		nb = va_arg(args, long);
		ft_putstr("0x");
		if (nb >= -2147483648 && nb < -1)
			dec_to_hex_addr(18446744073709551615U + nb);
		else if (nb == -1)
			dec_to_hex_addr(18446744073709551615U);
		else
			dec_to_hex_addr(nb);
	}
	else if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(args, int));
	else
		flag_check2(args, s);
}
