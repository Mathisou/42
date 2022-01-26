/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:18:54 by maroly            #+#    #+#             */
/*   Updated: 2022/01/26 19:18:37 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z, double alpha)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

int mouse_pressed(int button, int x, int y, t_data *img)
{
    (void)button;
    (void)x;
    (void)y;
    if (button == 1)
        img->mouse->is_pressed = true;
    else if (button == 4)
        zoom(button, img);
    else if (button == 5)
        zoom(button, img);
    return (0);
}

int mouse_unpressed(int button, int x, int y, t_data *img)
{
    (void)button;
    (void)x;
    (void)y;
    if (button == 1)
        img->mouse->is_pressed = false;
    return (0);
}

int mouse_move(int x, int y, t_data *img)
{
    img->mouse->previous_x = img->mouse->x;
	img->mouse->previous_y = img->mouse->y;
	img->mouse->x = x;
	img->mouse->y = y;
	if (img->mouse->is_pressed)
	{
		img->camera->beta += (x - img->mouse->previous_x) * 0.002;
		img->camera->alpha += (y - img->mouse->previous_y) * 0.002;
        img->img = mlx_new_image(img->mlx_win, WIDTH, HEIGHT);
        img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
        draw(img->camera, img, img->pos);
        add_text(img);
    }
    return (0);
}