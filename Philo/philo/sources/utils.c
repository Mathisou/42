/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:37:49 by maroly            #+#    #+#             */
/*   Updated: 2022/02/07 15:39:39 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int     ft_atoi(const char *nptr)
{
        size_t          i;
        int                     sign;
        long long       result;

        i = 0;
        sign = 1;
        result = 0;
        while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
                i++;
        if (nptr[i] == '+' || nptr[i] == '-')
        {
                if (nptr[i] == '-')
                        sign *= -1;
                i++;
        }
        while (nptr[i] >= '0' && nptr[i] <= '9')
        {
                result = result * 10 + nptr[i] - 48;
                if (result * sign > 2147483647)
                        return (-1);
                else if (result * sign < -2147483648)
                        return (0);
                i++;
        }
        return (result * sign);
}