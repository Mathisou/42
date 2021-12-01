/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:58:42 by maroly            #+#    #+#             */
/*   Updated: 2021/12/01 14:59:07 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

void	ft_putchar(char c);
void	ft_putstr(const char *str);
void	ft_putnbr(long nb);
int		ft_strlen(const char *str);
int		ft_printf(const char *s, ...);
int		check_s(const char *s);
void	flag_check(va_list args, const char *s);
int		parse_s(const char *s, va_list args);
void	dec_to_hex_addr(unsigned long long nb);
void	dec_to_hex_x(long nb);
void	dec_to_hex_upperx(long nb);
int		flag_check_count(char c, va_list args);
void	flag_check(va_list args, const char *s);
int		dec_to_hex_count(long long nb, int *count);
int		dec_to_hex_addr_count(unsigned long long nb, int *count);
int		decomp_number(long long nb);

#endif
