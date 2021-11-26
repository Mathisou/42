/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:33:23 by maroly            #+#    #+#             */
/*   Updated: 2021/11/26 16:35:49 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printflib.h"

void	flag_check(va_list args, const char *s)
{
	long long nb;

	if (*s == 'c')
		ft_putchar(va_arg(args, int));
	if (*s == 's')
		ft_putstr(va_arg(args, char *));
	//if (*s == 'p')

	if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(args, long long));
	if (*s == 'u')
	{
		nb = va_arg(args, long long);
		if (nb < 0)
			ft_putnbr(4294967295 + nb);
		else
			ft_putnbr(nb);		
	}
	if (*s == 'x')
		dec_to_hex(va_arg(args, long long));
	//if (*s == '%')
}

int	check_s(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && (!(s[i + 1] == 'c' || s[i + 1] == 's' || s[i + 1] == 'p'
						|| s[i + 1] == 'd' || s[i + 1] == 'i' || s[i + 1] == 'u'
						|| s[i + 1] == 'x' || s[i + 1] == '%')))
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list args;
	int i;

	i = 0;
	va_start(args, s);
	if (check_s(s) == 1)
		return (1);
	while (s[i])
	{
		if (s[i] == '%' && (s[i + 1] == 'c' || s[i + 1] == 's' || s[i + 1] == 'p'
					|| s[i + 1] == 'd' || s[i + 1] == 'i' || s[i + 1] == 'u'
					|| s[i + 1] == 'x' || s[i + 1] == '%'))
		{
			flag_check(args, &s[++i]);
			i++;
		}
		else
			ft_putchar(s[i++]);
	}
	va_end(args);
	return (0);
}

int main()
{
	ft_printf("d = %d et i = %i et str = %s\nLa conversion de 45 en hexa : %x\nUn truc non signe : %u\n", 45, 58, "Hello", 45, -2147483647);
}
