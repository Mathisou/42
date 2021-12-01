/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:33:23 by maroly            #+#    #+#             */
/*   Updated: 2021/12/01 14:56:34 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	va_list	args2;
	int		i;

	i = 0;
	va_start(args, s);
	va_copy(args2, args);
	while (s[i])
	{
		if (s[i] == '%' && (s[i + 1] == 'c' || s[i + 1] == 's'
				|| s[i + 1] == 'p' || s[i + 1] == 'd' || s[i + 1] == 'i'
				|| s[i + 1] == 'u' || s[i + 1] == 'x' || s[i + 1] == 'X'
				|| s[i + 1] == '%'))
		{
			flag_check(args, &s[++i]);
			i++;
		}
		else
			ft_putchar(s[i++]);
	}
	va_end(args);
	return (parse_s(s, args2));
}
