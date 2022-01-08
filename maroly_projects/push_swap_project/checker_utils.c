/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:16:29 by maroly            #+#    #+#             */
/*   Updated: 2022/01/08 01:18:16 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char    *ft_strcat(char *dest, const char *src)
	{
 	int    i;
 	int    size;

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

int	pre_init_pile(t_lst **pile_a, char **av, int ac)
{
	char **tab;
	int i;

	i = -1;
	if (ac == 2 && check_first_arg(av[1]) == 0)
	{
		tab = ft_split(av[1], ' ');
		if (initializing_pile(pile_a, tab, 0) == 1)
			return (1);
		destroy_tab(tab);
	}
	else if (ac > 2)
	{
		tab = malloc(sizeof(*tab) * ac);
		if (!tab)
			return (1);
		while (++i < ac - 1)
			tab[i] = av[i + 1];
		tab[i] = NULL;
		if (initializing_pile(pile_a, tab, 1) == 1)
			return (1);
		free(tab);
	}
	return (0);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
 	char   *new;

 	if (!s2)
        return (NULL);
 	if (!s1)
        return (ft_strdup((char *)s2));
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

int	check_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (!(ft_strcmp(tab[i], "sa") == 0 || ft_strcmp(tab[i], "sb") == 0
			|| ft_strcmp(tab[i], "ss") == 0 || ft_strcmp(tab[i], "pa") == 0
			|| ft_strcmp(tab[i], "pb") == 0 || ft_strcmp(tab[i], "ra") == 0
			|| ft_strcmp(tab[i], "rb") == 0 || ft_strcmp(tab[i], "rr") == 0
			|| ft_strcmp(tab[i], "rra") == 0 || ft_strcmp(tab[i], "rrb") == 0 
			|| ft_strcmp(tab[i], "rrr") == 0))
			return (1);
		i++;
	}
	return (0);
}

char **init_tab(t_varbns *s)
{
	s->buffer = malloc(sizeof(*s->buffer) * 2);
	while (s->count > 0)
	{
		s->count = read(0, s->buffer, 1);
		s->buffer[1] = '\0';
		s->new = ft_strjoin(s->new, s->buffer);
	}
	free(s->buffer);
	s->tab = ft_split(s->new, '\n');
	free(s->new);
	if (check_tab(s->tab) == 1)
	{
		print_error();
		return(NULL);
	}
	return (s->tab);
}