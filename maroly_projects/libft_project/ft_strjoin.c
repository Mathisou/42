/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:17:20 by maroly            #+#    #+#             */
/*   Updated: 2022/01/10 15:20:09 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcats(char *dest, const char *src)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(dest);
	while (src[i])
	{
		dest[size + i] = (char)src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	else
	{
		new = malloc(sizeof(*new) * (ft_strlen(s2) + ft_strlen(s1) + 1));
		if (!new)
			return (NULL);
		new[0] = '\0';
		new = ft_strcat(new, (char *)s1);
		free((char *)s1);
		return (ft_strcat(new, (char *)s2));
	}
}
