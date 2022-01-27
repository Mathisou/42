/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:20:45 by maroly            #+#    #+#             */
/*   Updated: 2022/01/27 17:28:48 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int controls(int keycode, void *param)
{
    if (keycode == ESC)
        destroy_window(param);
    else if (keycode == LEFT || keycode == RIGHT
        || keycode == DOWN || keycode == UP)
        move(keycode, param);
    else if (keycode == PLUS || keycode == PLUS_NUM
        || keycode == MINUS || keycode == MINUS_NUM)
        zoom(keycode, param);
    else if (keycode == Z || keycode == X)
        relief(keycode, param);
    else if (keycode == CARTESIAN || keycode == ISO)
        plan(keycode, param);
    else if (keycode == NUM_1 || keycode == NUM_2 || keycode == NUM_3
        || keycode == NUM_4 || keycode == NUM_5 || keycode == NUM_6)
        rotation(keycode, param);
    return (0);
}

int main(int ac, char **av)
{
    t_data *img;
    t_pos pos;
    t_var s;
    t_mouse is_pressed;

    img = malloc(sizeof(t_data));
    if (ac != 2)
        return (1);
    if (parsing_map(&s, av[1]) == 1)
        return (1);
    if (check_map(&s) == 1)
        return (1);
    /*s.relief = (s.zmax - s.zmin) / 5;
    if (s.relief < 1)
        s.relief = 1;*/
    s.relief = 6;
    s.projection = ISO;
    s.originx = 0;
    s.originy = 0;
    if ((WIDTH - (LEFT * 2)) / s.count_x < (HEIGHT - (Y_MARGIN * 2)) / s.count_y)
        s.zoom = ((WIDTH - (X_MARGIN * 2)) / s.count_x) / 3 * 2;
    else
        s.zoom = ((HEIGHT - (Y_MARGIN * 2)) / s.count_y) / 3 * 2;
    if (s.zoom == 0)
        s.zoom = 1;
    img->mlx = mlx_init();
    img->mlx_win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "FDF");
    img->img = mlx_new_image(img->mlx_win, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    img->pos = &pos;
    img->mouse = &is_pressed;
    img->camera = &s;
    draw(img->camera, img, img->pos);
    add_text(img);
    main_hook(img);
	mlx_loop(img->mlx);
    mlx_clear_window(img->mlx, img->mlx_win);
    mlx_destroy_window(img->mlx, img->mlx_win);
    clear_tab(&s);
    close(s.fd);
    free(img);
    return (0);
}