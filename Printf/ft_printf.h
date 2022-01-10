/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:58:42 by maroly            #+#    #+#             */
/*   Updated: 2021/12/15 17:09:14 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int	ft_printf(const char *s, ...);
int	precision(long nb, va_list args, const char *s, int sign);
int	ft_putchar(char c);
int	ft_putnbr(long long nb, int *count, int sign);
int	ft_atoi(const char *nptr);
int	ft_dec_to_hexa(unsigned long nb, int sign, int *count);
int	ft_strlen(char *s);
int	ft_putstr(char *s);
int	bonusplus(long nb, va_list args, const char *s, int count);
int	decomp_number(long nb, int base, int sign);
int	bonusminus(long nb, va_list args, const char *s, int count);
int	bonussharp(long nb, va_list args, const char *s, int sign);
int	bonusspace(long nb, va_list args, const char *s, int count);
int	zero_or_space(int sign);
int	bonusminus(long nb, va_list args, const char *s, int count);
int	bonuswidths(long nb, va_list args, const char *s, int sign);
int	bonuswidthsminus(long nb, long nbdot, va_list args, const char *s);
int	precision6(long nb, va_list args, const char *s, int sign);
int	destroy_tab(int count, long *tab);
int	bonuswidths6(long *tab, va_list args, const char *s, int sign);
int	bonuswidthsminus6(long nb, va_list args, const char *s);
int	is_flag(char c, int sign);

#endif
