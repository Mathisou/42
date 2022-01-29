/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:49:50 by maroly            #+#    #+#             */
/*   Updated: 2022/01/28 19:39:04 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	find_origin(t_var *s)
{
	t_pos	tmp;
	t_pos	tmp2;

	tmp.x = s->count_x - 1;
	tmp.y = 0;
	tmp2.x = 0;
	tmp2.y = s->count_y - 1;
	iso(&tmp.x, &tmp.y, ft_atoi(s->tab[tmp.y][tmp.x]));
	iso(&tmp2.x, &tmp2.y, ft_atoi(s->tab[tmp2.y][tmp2.x]));
	s->originx = (WIDTH - tmp.x + abs(tmp2.x)) / 5 * 2;
	tmp2.x = s->count_x - 1;
	tmp2.y = s->count_y - 1;
	iso(&tmp2.x, &tmp2.y, ft_atoi(s->tab[tmp2.y][tmp2.x]));
	s->originy = (HEIGHT - tmp2.y) / 5;
}

int	count_lines(t_var *s, char *map)
{
	char	*str;

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

int	count_elem(t_var *s)
{
	s->count_x = 0;
	while (s->tab[0][s->count_x] && ft_strcmp(s->tab[0][s->count_x], "\n") == 1)
		s->count_x++;
	return (s->count_x);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	clear_tab(t_data *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < img->camera->count_y)
	{
		j = -1;
		while (++j < img->camera->count_x)
			free(img->camera->tab[i][j]);
		free(img->camera->tab[i]);
	}
	free(img->camera->tab);
	img->camera->tab = NULL;
}
