/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:49:50 by maroly            #+#    #+#             */
/*   Updated: 2022/01/22 18:54:13 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void    find_origin(t_var *s)
{
    t_pos tmp;
    t_pos tmp2;

    tmp.x = s->count_x - 1;
    tmp.y = 0;
    tmp2.x = 0;
    tmp2.y = s->count_y - 1;
    tmp = iso(tmp.x, tmp.y, ft_atoi(s->tab[tmp.y][tmp.x]), *s);
    tmp2 = iso(tmp2.x, tmp2.y, ft_atoi(s->tab[tmp2.y][tmp2.x]), *s);
    s->originx = (WIDTH - tmp.x + abs(tmp2.x)) / 2;
    tmp.x = 0;
    tmp.y = 0;
    tmp2.x = s->count_x - 1;
    tmp2.y = s->count_y - 1;
    tmp = iso(tmp.x, tmp.y, ft_atoi(s->tab[tmp.y][tmp.x]), *s);
    tmp2 = iso(tmp2.x, tmp2.y, ft_atoi(s->tab[tmp2.y][tmp2.x]), *s);
    s->originy = (HEIGHT - tmp2.y) / 3 * 2;
}

int    count_lines(t_var *s, char *map)
{
    char *str;

    s->count_y = 0;
    s->fd = open(map, O_RDONLY);
    if (s->fd == -1)
        return (1);
    str = get_next_line(s->fd);
    while (str != NULL)
    {
        str = get_next_line(s->fd);
        s->count_y++;
    }
    free(str);
    return (0); 
}

int    count_elem(t_var *s)
{
    s->count_x = 0;
    while (s->tab[0][s->count_x] && ft_strcmp(s->tab[0][s->count_x], "\n") == 1)
        s->count_x++;
    return (s->count_x);
}

int ft_strcmp(char *s1, char *s2)
{
    int i;
    
    i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    return (0);
}

void    clear_tab(t_var *s)
{
    int i;
    int j;

    i = -1;
    while (s->tab[++i])
    {
        j = -1;
        while (s->tab[i][++j])
            free(s->tab[i][j]);
        free(s->tab[i]);
    }
    free(s->tab);
}