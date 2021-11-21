/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:20:12 by maroly            #+#    #+#             */
/*   Updated: 2021/10/31 23:02:42 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	create_tab(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if ((s[i - 1] == c || i == 0) && s[i] != c)
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
	str = (char *) malloc(sizeof(*str) * i);
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

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	string;
	char	**tab;

	i = 0;
	string = 0;
	tab = NULL;
	tab = (char **) malloc(sizeof(*tab) * create_tab(s, c));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (((s[i - 1] == c || i == 0) && s[i] != c) && s[i])
		{
			tab[string] = put_str_in_tab(&s[i], c);
			string++;
		}
		if (s[i])
			i++;
	}
	tab[string] = NULL;
	return (tab);
}
