/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:53:17 by maroly            #+#    #+#             */
/*   Updated: 2022/01/22 18:53:58 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int parsing_map(t_var *s, char *map)
{
    int i;

    i = 0;
    if (count_lines(s, map) == 1)
        return (1);
    s->fd = open(map, O_RDONLY);
    if (s->fd == -1)
        return (1);
    s->tab = malloc(sizeof(char **) * (s->count_y + 1));
    if (!s->tab)
        return (1);
    s->tab[i] = ft_split(get_next_line(s->fd), ' ');
    count_elem(s);
    while (s->tab[i++])
        s->tab[i] = ft_split(get_next_line(s->fd), ' ');
    close(s->fd);
    return (0);
}

int    check_map(t_var *s)
{
    int i;
    int j;
    int ret;

    i = -1;
    s->zmin = ft_atoi(s->tab[0][0]);
    s->zmax = s->zmin;
    while (s->tab[++i])
    {
        j = -1;
        while (s->tab[i][++j] && ft_strcmp(s->tab[i][j], "\n") == 1)
        {
            ret = ft_atoi(s->tab[i][j]);
            if (ret > s->zmax)
                s->zmax = ret;
            if (ret < s->zmin)
                s->zmin = ret;
        }
        if (s->count_x != j)
            return (1);
    }
    return (0);
}