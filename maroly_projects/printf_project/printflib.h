/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:19:56 by maroly            #+#    #+#             */
/*   Updated: 2021/11/26 15:51:57 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFLIB_H
# define PRINTFLIB_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	dec_to_hex(long long nb);
void	ft_putchar(char c);
void	ft_putstr(const char *str);
void	ft_putnbr(long long nb);
int		ft_strlen(const char *str);

#endif
