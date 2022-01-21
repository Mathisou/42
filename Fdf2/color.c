/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:40:54 by maroly            #+#    #+#             */
/*   Updated: 2022/01/21 17:27:33 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int is_hexa(char c)
{
    char *hexa;
    int i;

    hexa = "0123456789ABCDEF";
    i = -1;
    while (hexa[++i])
        if (hexa[i] == c)
            return (0);
    return (1);
}

int is_color_correct(char *str)
{
    int i;

    i = 1;
    if (str[0] == '0' && str[1] == 'x')
        while (str[++i] && str[i] != '\n')
            if (is_hexa(str[i]) == 1)
                return (1);
    return (0);
}

unsigned int get_color(char *str)
{
    int i;

    i = 0; 
    while (str[i] && str[i] >= '0' && str[i] <= '9')
        i++;
    //printf("%s\n", str);
    if (str[i] != '\0' && (ft_strlen(&str[i]) == 8 || ft_strlen(&str[i]) == 9) && is_color_correct(&str[i]) == 0)
        return (0x0000FF00);
        //return (ft_atoi_base(&str[i], "0123456789ABCDEF"));
    return (0x00FFFFFF);
}