/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:56:38 by maroly            #+#    #+#             */
/*   Updated: 2021/12/02 20:03:26 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *value_to_return(char *new_line, char *stock)
{
	if (new_line[0] == '\0')
	{
		if (stock)
			free(stock);
		if (new_line)
			free(new_line);
		return (NULL);
	}
	return (new_line);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	size;
	size_t	i;

	i = 0;
	new = NULL;
	size = ft_strlen(s);
	new = (char *) malloc(sizeof(*new) * (size + 1));
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char *split(char *str, char *new)
{
	int i;

	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
