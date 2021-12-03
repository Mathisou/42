/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:56:38 by maroly            #+#    #+#             */
/*   Updated: 2021/12/03 12:50:40 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *value_to_return(char *new_line, char *stock, char *buffer)
{
    free(buffer);
	if (*new_line == '\0')
	{
		if (stock)
			free(stock);
		if (new_line)
			free(new_line);
        //if (buffer)
        //    free(buffer);
		return (NULL);
	}
	return (new_line);
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
    //free(s);
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
