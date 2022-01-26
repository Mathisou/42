/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cartesian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:58:57 by maroly            #+#    #+#             */
/*   Updated: 2022/01/25 20:27:11 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos cartesian(int x, int y, int z, t_var s)
{
    int prev_x;
    int prev_y;
    t_pos pos;

    (void)z;
    if ((WIDTH - (X_MARGIN * 2)) / s.count_x < (HEIGHT - (Y_MARGIN * 2)) / s.count_y)
        s.size = ((WIDTH - (X_MARGIN * 2)) / s.count_x) / 5 * 4;
    else
        s.size = ((HEIGHT - (Y_MARGIN * 2)) / s.count_y) / 5 * 4;
    if (s.size < 2)
        s.size = 2;
    s.originx = (WIDTH - (s.size * s.count_x)) / 2;
    s.size += s.zoom;
    prev_x = x * s.size;
    prev_y = y * s.size;
    pos.x = prev_x + (s.originx + s.x_move);
    pos.y = prev_y + (s.originy + s.y_move);
    return (pos);
}

t_pos		project(t_pos p, t_data *img)
{
	p.x *= img->camera->zoom;
	p.y *= img->camera->zoom;
	p.z *= img->camera->zoom;
	p.x -= (img->camera->count_x * img->camera->zoom) / 2;
	p.y -= (img->camera->count_y * img->camera->zoom) / 2;
	rotate_x(&p.y, &p.z, img->camera->alpha);
	rotate_y(&p.x, &p.z, img->camera->beta);
	rotate_z(&p.x, &p.y, img->camera->gamma);
	//if (img->camera->projection == ISO)
	//	iso2(&p.x, &p.y, p.z);
	p.x += WIDTH / 2 + img->camera->originx;
	p.y += (HEIGHT + img->camera->count_y * img->camera->zoom) / 2 + img->camera->originy;
	return (p);
}

t_pos	new_point(int x, int y, int z)
{
	t_pos	point;

	point.x = x;
	point.y = y;
	point.z = z;
	/*point.color = (map->colors_arr[index] == -1) ?
			get_default_color(point.z, map) : map->colors_arr[index];*/
	return (point);
}

void draw_cartesian(t_var *s, t_data *img, t_pos *pos)
{
    background(img);
    pos->y = -1;
    while (++pos->y < s->count_y)
    {
        pos->x = -1;
        while (++pos->x < s->count_x)
        {
            if (pos->x < s->count_x - 1)
                bersenham(project(new_point(pos->x, pos->y, ft_atoi(s->tab[pos->y][pos->x])), img),
                project(new_point(pos->x + 1, pos->y, ft_atoi(s->tab[pos->y][pos->x + 1])), img), img, 0x9A1F6A);
            if (pos->y != s->count_y - 1)
bersenham(project(new_point(pos->x, pos->y, ft_atoi(s->tab[pos->y][pos->x])), img),
                project(new_point(pos->x, pos->y + 1, ft_atoi(s->tab[pos->y + 1][pos->x])), img), img, 0x9A1F6A);        }
    }
    mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, X_MARGIN, Y_MARGIN);
}