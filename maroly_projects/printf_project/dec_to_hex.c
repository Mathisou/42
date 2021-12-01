/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:54:24 by maroly            #+#    #+#             */
/*   Updated: 2021/12/01 18:47:34 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	dec_to_hex_addr(unsigned long long nb)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nb >= 16)
	{
		dec_to_hex_addr(nb / 16);
		ft_putchar(hexa[nb % 16]);
	}
	if (nb < 16)
		ft_putchar(hexa[nb % 16]);
}

void	dec_to_hex_upperx(long nb)
{
	char				*hexa;
	unsigned long long	n;

	n = nb;
	if (nb <= -2147483648)
	{
		ft_putchar('0');
		return ;
	}
	hexa = "0123456789ABCDEF";
	if (n >= 16)
	{
		dec_to_hex_upperx(n / 16);
		ft_putchar(hexa[n % 16]);
	}
	if (n < 16)
		ft_putchar(hexa[n % 16]);
}

void	dec_to_hex_x(long nb)
{
	char				*hexa;
	unsigned long long	n;

	n = (unsigned long long)nb;
	if (nb < -2147483648)
	{
		ft_putchar('0');
		return ;
	}
	if (n > 4294967295)
		n = 4294967295;
	hexa = "0123456789abcdef";
	if (n >= 16)
	{
		dec_to_hex_x(n / 16);
		ft_putchar(hexa[n % 16]);
	}
	if (n < 16)
		ft_putchar(hexa[n % 16]);
}
