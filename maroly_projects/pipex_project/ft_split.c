/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:20:12 by maroly            #+#    #+#             */
/*   Updated: 2021/12/27 15:08:21 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	create_tab(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (((s[i - 1] == c || i == 0) && s[i] != c) && s[i])
			size++;
		i++;
	}
	return (size);
}

static char	*put_str_in_tab(const char *s, char c)
{
	size_t	i;
	char	*str;

	str = NULL;
	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = (char *) malloc(sizeof(*str) * (i + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**destroy_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	string;
	char	**tab;

	i = 0;
	string = 0;
	if (!s)
		return (NULL);
	tab = (char **) malloc(sizeof(*tab) * (create_tab(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		if (((s[i - 1] == c || i == 0) && s[i] != c) && s[i])
		{
			tab[string] = put_str_in_tab(&s[i], c);
			if (!tab[string])
				return (destroy_tab(tab));
			string++;
		}
		i++;
	}
	tab[string] = NULL;
	return (tab);
}
