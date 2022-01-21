/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:56:38 by maroly            #+#    #+#             */
/*   Updated: 2021/12/07 17:33:03 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*value_to_return(char *new_line, char *stock, char *buffer, int check)
{
	if (buffer)
		free(buffer);
	if (!new_line || check == -1)
	{
		if (stock)
			free(stock);
		return (NULL);
	}
	return (new_line);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	else
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*ft_strdup(char *s)
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

char	*split(char *str, char *new)
{
	int	i;

	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
