/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:25:28 by maroly            #+#    #+#             */
/*   Updated: 2021/10/19 13:26:08 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	i = 0;
	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str[i] && str2[i] && i < n)
	{
		if (str[i] < str2[i])
			return (-1);
		else if (str[i] > str2[i] && i < n)
			return (1);
		i++;
	}
	if (str[i] < str2[i] && i < n)
		return (-1);
	else if (str[i] > str2[i] && i < n)
		return (1);
	return (0);
}