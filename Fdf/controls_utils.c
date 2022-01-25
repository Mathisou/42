/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:11:08 by maroly            #+#    #+#             */
/*   Updated: 2022/01/26 00:00:36 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int    destroy_window(void *param)
{
    (void)param;
    exit (0);
}

int plan(int keycode, t_data *img)
{
    img->img = mlx_new_image(img->mlx_win, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    img->camera->x_move = 0;
    img->camera->y_move = 0;
    img->camera->zoom = 25;
    img->camera->gamma = 0;
    img->camera->beta = 0;
    img->camera->alpha = 0;
    img->camera->relief = 6;
    if (keycode == ISO)
        img->camera->projection = ISO;
    else if (keycode == CARTESIAN)
        img->camera->projection = CARTESIAN;
    draw(img->camera, img, img->pos);
    return (0);
}

int relief(int keycode, t_data *img)
{
    if (keycode == Z)
        img->camera->relief += 0.1;
    else
        img->camera->relief -= 0.1;
    if (img->camera->relief < 0.1)
		img->camera->relief = 0.1;
	else if (img->camera->relief > 10)
		img->camera->relief = 10;
    img->img = mlx_new_image(img->mlx_win, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    draw(img->camera, img, img->pos);
    return (0);
}

int move(int keycode, t_data *img)
{
    if (keycode == LEFT)
        img->camera->x_move -= 5;
    else if (keycode == RIGHT)
        img->camera->x_move += 5;
    else if (keycode == UP)
        img->camera->y_move -= 5;
    else if (keycode == DOWN)
        img->camera->y_move += 5;
    img->img = mlx_new_image(img->mlx_win, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    draw(img->camera, img, img->pos);
    return (0);
}

int zoom(int keycode, t_data *img)
{
    int size;

    if ((WIDTH - (X_MARGIN * 2)) / img->camera->count_x < (HEIGHT - (Y_MARGIN * 2)) / img->camera->count_y)
        size = ((WIDTH - (X_MARGIN * 2)) / img->camera->count_x) / 5 * 4;
    else
        size = ((HEIGHT - (Y_MARGIN * 2)) / img->camera->count_y) / 5 * 4;
    if (size < 2)
        size = 2;
    if (keycode == PLUS || keycode == PLUS_NUM)
        img->camera->zoom += 2;
    else if ((keycode == MINUS || keycode == MINUS_NUM) && size + (img->camera->zoom - 2) >= 4)
        img->camera->zoom -= 2;
    img->img = mlx_new_image(img->mlx_win, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    draw(img->camera, img, img->pos);
    return (0);

}