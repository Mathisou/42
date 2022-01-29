/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:21:10 by maroly            #+#    #+#             */
/*   Updated: 2022/01/28 15:27:32 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pos	project(t_pos p, t_data *img)
{
	if (img->camera->relief < 1)
		img->camera->relief = 1;
	if (img->camera->zoom < 3)
		img->camera->zoom = 3;
	p.x *= img->camera->zoom;
	p.y *= img->camera->zoom;
	p.z *= img->camera->zoom / img->camera->relief;
	p.x -= (img->camera->count_x * img->camera->zoom) / 2;
	p.y -= (img->camera->count_y * img->camera->zoom) / 2;
	rotate_x(&p.y, &p.z, img->camera->alpha);
	rotate_y(&p.x, &p.z, img->camera->beta);
	rotate_z(&p.x, &p.y, img->camera->gamma);
	if (img->camera->projection == ISO)
		iso(&p.x, &p.y, p.z);
	p.x += WIDTH / 2 + img->camera->x_move;
	p.y += (HEIGHT + img->camera->count_y * img->camera->zoom) / 3
		+ img->camera->y_move;
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
