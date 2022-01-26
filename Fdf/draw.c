/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:48:14 by maroly            #+#    #+#             */
/*   Updated: 2022/01/26 18:57:29 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_data *img, int x, int y, int color)
{
	int		i;

	if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
	{
		i = (x * img->bits_per_pixel / 8) + (y * img->line_length);
		img->addr[i] = color;
		img->addr[++i] = color >> 8;
		img->addr[++i] = color >> 16;
	}
}

void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_pos		project(t_pos p, t_data *img) //pb avec loriginev et commandes inverse avc la souris
{
    int relief;

    relief = img->camera->zoom / img->camera->relief;
    if (relief < 1)
        relief = 1;
    if (img->camera->zoom < 3)
        img->camera->zoom = 3;
	p.x *= img->camera->zoom;
	p.y *= img->camera->zoom;
	p.z *= relief;
	p.x -= (img->camera->count_x * img->camera->zoom) / 2;
	p.y -= (img->camera->count_y * img->camera->zoom) / 2;
	rotate_x(&p.y, &p.z, img->camera->alpha);
	rotate_y(&p.x, &p.z, img->camera->beta);
	rotate_z(&p.x, &p.y, img->camera->gamma);
	if (img->camera->projection == ISO)
		iso(&p.x, &p.y, p.z);
    p.x += WIDTH / 2 + img->camera->x_move;
	p.y += (HEIGHT + img->camera->count_y * img->camera->zoom) / 3 + img->camera->y_move;
	return (p);
}

t_pos	new_point(int x, int y, int z, t_var *s)
{
	t_pos	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = get_default_color(point.z, s);
	return (point);
}


int	ter_dw(int f, int s)
{
	if (f < s)
		return (1);
	return (-1);
}

void	bersenham(t_pos beg, t_pos end, t_data *mlx, int sgn)
{
	t_pos	delta;
	t_pos   sign;
    t_pos   start;
	int		error[2];

	delta.dx = abs(end.x - beg.x);
	delta.dy = abs(end.y - beg.y);
	sign.signx = ter_dw(beg.x, end.x);
	sign.signy = ter_dw(beg.y, end.y);
	error[0] = delta.dx - delta.dy;
    start.x = beg.x;
    start.y = beg.y;
    while (beg.x != end.x || beg.y != end.y)
	{
        if (sgn == 0)
            put_pixel(mlx, beg.x, beg.y, get_color(beg, start, end, delta));
        else if (sgn == 1)
            put_pixel(mlx, beg.x, beg.y, 0x222222);
        error[1] = error[0] * 2;
        if (error[1] > -delta.dy)
		{
			error[0] -= delta.dy;
			beg.x += sign.signx;
		}
		if (error[1] < delta.dx)
		{
			error[0] += delta.dx;
			beg.y += sign.signy;
		}
	}
}

void draw(t_var *s, t_data *img, t_pos *pos)
{
    background(img);
    pos->y = -1;
    while (++pos->y < s->count_y)
    {
        pos->x = -1;
        while (++pos->x < s->count_x)
        {
            if (pos->x < s->count_x - 1)
                bersenham(project(new_point(pos->x, pos->y, ft_atoi(s->tab[pos->y][pos->x]), s), img),
                project(new_point(pos->x + 1, pos->y, ft_atoi(s->tab[pos->y][pos->x + 1]), s), img), img, 0);
            if (pos->y < s->count_y - 1)
                bersenham(project(new_point(pos->x, pos->y, ft_atoi(s->tab[pos->y][pos->x]), s), img),
                project(new_point(pos->x, pos->y + 1, ft_atoi(s->tab[pos->y + 1][pos->x]), s), img), img, 0);
        }
    }
    mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, X_MARGIN, Y_MARGIN);
}

void    background(t_data *img)
{
    t_pos   beg;
    t_pos   end;

    beg.x = -1;
    while (++beg.x <= WIDTH)
    {
        beg.y = 0;
        end.x = beg.x;
        end.y = HEIGHT;
        bersenham(beg, end, img, 1);
    }
}