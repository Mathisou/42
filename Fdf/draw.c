/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:48:14 by maroly            #+#    #+#             */
/*   Updated: 2022/01/22 18:51:26 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_data *fdf, int x, int y, int color)
{
	int		i;

	if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->line_length);
		fdf->addr[i] = color;
		fdf->addr[++i] = color >> 8;
		fdf->addr[++i] = color >> 16;
	}
}

t_pos iso(int x, int y, int z, t_var s)
{
    int previous_x;
    int previous_y;
    t_pos pos;

    (void)s;
    if ((WIDTH - (LEFT * 2)) / s.count_x < (HEIGHT - (TOP * 2)) / s.count_y)
        s.size = ((WIDTH - (LEFT * 2)) / s.count_x) / 5 * 4;
    else
        s.size = ((HEIGHT - (TOP * 2)) / s.count_y) / 5 * 4;
    if (s.size == 0)
        s.size = 1;
    previous_x = x * (s.size * 86 / 100);
    previous_y = y * s.size;
    pos.x = (previous_x - previous_y) * cos(0.523599) + s.originx;
    pos.y = -(z * 6) + (previous_x + previous_y) * sin(0.523599) + s.originy;
    return (pos);
}

int	ter_dw(int f, int s)
{
	if (f < s)
		return (1);
	return (-1);
}

void	bersenham(t_pos beg, t_pos end, t_data *mlx, unsigned int color)
{
	t_pos	delta;
	t_pos   sign;
	int		error[2];

    //(void)color;
	delta.dx = abs(end.x - beg.x);
	delta.dy = abs(end.y - beg.y);
	sign.signx = ter_dw(beg.x, end.x);
	sign.signy = ter_dw(beg.y, end.y);
	error[0] = delta.dx - delta.dy;
    while (beg.x != end.x || beg.y != end.y)
	{
        put_pixel(mlx, beg.x, beg.y, color);
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

void    background(t_data *img)
{
    t_pos   beg;
    t_pos   end;

    beg.x = -1;
    while (++beg.x < WIDTH)
    {
        beg.y = 0;
        end.x = beg.x;
        end.y = HEIGHT;
        bersenham(beg, end, img, 0x222222);
    }
}