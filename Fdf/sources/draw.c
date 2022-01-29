/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:48:14 by maroly            #+#    #+#             */
/*   Updated: 2022/01/29 02:59:45 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pixel(t_data *img, int x, int y, int color)
{
	int	i;

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
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	bersenham(t_pos beg, t_pos end, t_data *mlx)
{
	t_pos	delta;
	t_pos	sign;
	t_pos	cur;

	delta.dx = abs(end.x - beg.x);
	delta.dy = abs(end.y - beg.y);
	sign.signx = ter_dw(beg.x, end.x);
	sign.signy = ter_dw(beg.y, end.y);
	mlx->error[0] = delta.dx - delta.dy;
	cur = beg;
	while (cur.x != end.x || cur.y != end.y)
	{
		put_pixel(mlx, cur.x, cur.y, get_color(cur, beg, end, delta));
		mlx->error[1] = mlx->error[0] * 2;
		if (mlx->error[1] > -delta.dy)
		{
			mlx->error[0] -= delta.dy;
			cur.x += sign.signx;
		}
		if (mlx->error[1] < delta.dx)
		{
			mlx->error[0] += delta.dx;
			cur.y += sign.signy;
		}
	}
}

void	draw(t_var *s, t_data *img, t_pos *pos)
{
	background(img);
	pos->y = -1;
	while (++pos->y < s->count_y)
	{
		pos->x = -1;
		while (++pos->x < s->count_x)
		{
			if (pos->x < s->count_x - 1)
				bersenham(project(new_point(pos->x, pos->y,
							ft_atoi(s->tab[pos->y][pos->x]), s), img),
					project(new_point(pos->x + 1, pos->y,
							ft_atoi(s->tab[pos->y][pos->x + 1]), s), img), img);
			if (pos->y < s->count_y - 1)
				bersenham(project(new_point(pos->x, pos->y,
							ft_atoi(s->tab[pos->y][pos->x]), s), img),
					project(new_point(pos->x, pos->y + 1,
							ft_atoi(s->tab[pos->y + 1][pos->x]), s), img), img);
		}
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
		X_MARGIN, Y_MARGIN);
}

void	background(t_data *img)
{
	t_pos	beg;
	t_pos	end;

	beg.x = -1;
	while (++beg.x <= WIDTH)
	{
		beg.y = -1;
		end.x = beg.x;
		end.y = HEIGHT;
		while (++beg.y != end.y)
			put_pixel(img, beg.x, beg.y, 0x222222);
	}
}
