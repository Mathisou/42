/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:22:25 by maroly            #+#    #+#             */
/*   Updated: 2021/11/07 13:23:49 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_string(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static char	*count_size(char const *s1, char const *set)
{
	size_t	i;
	size_t	size;
	char	*new;

	i = 0;
	size = 0;
	new = NULL;
	while (s1[i])
	{
		if (check_string(s1[i], set) == 1)
			size++;
		i++;
	}
	new = (char *) malloc(sizeof(*new) * size);
	if (new == NULL)
		return (NULL);
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	new = count_size(s1, set);
	while (s1[i])
	{
		if (check_string(s1[i], set) == 1)
		{
			new[j] = s1[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (new);
}
