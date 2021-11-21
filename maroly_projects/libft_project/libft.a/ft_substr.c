/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:24:12 by maroly            #+#    #+#             */
/*   Updated: 2021/10/19 18:01:34 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = NULL;
	while (s[i] && s[i] != start)
		i++;
	if (ft_strlen(&s[i]) >= len)
		new = (char *) malloc(sizeof(*new) * len);
	else
		new = (char *) malloc(sizeof(*new) * ft_strlen(&s[i]));
	if (new == NULL)
		return (NULL);
	len += i;
	while (s[i] && i < len)
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
