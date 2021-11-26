/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:54:24 by maroly            #+#    #+#             */
/*   Updated: 2021/11/26 15:52:59 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printflib.h"

void	dec_to_hex(long long nb)
{
	char *hexa;

	hexa = "0123456789abcdef";
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 16)
	{
		dec_to_hex(nb / 16);
		ft_putchar(hexa[nb % 16]);
	}
	if (nb < 16)
		ft_putchar(hexa[nb % 16]);
}
