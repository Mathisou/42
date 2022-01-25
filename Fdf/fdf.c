/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:20:45 by maroly            #+#    #+#             */
/*   Updated: 2022/01/25 23:43:14 by maroly           ###   ########.fr       */
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
    s.relief = 6;
    s.originx = 0;
    s.originy = 0;
    s.zoom = 25;
    s.projection = ISO;
    img->mlx = mlx_init();
    img->mlx_win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "FDF");
    img->img = mlx_new_image(img->mlx_win, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    find_origin(&s);
    img->pos = &pos;
    img->mouse = &is_pressed;
    img->camera = &s;
    draw(img->camera, img, img->pos);
    //mlx_string_put(img->mlx, img->mlx_win, 50, 50, 0x00FFFFFF, "DGAUYGDKJAHDJKNAJKBDNJKHABHSVSAKH");
    mlx_hook(img->mlx_win, 2, 0, controls, img);
    mlx_hook(img->mlx_win, 4, 0, mouse_pressed, img);
    mlx_hook(img->mlx_win, 5, 0, mouse_unpressed, img);
    mlx_hook(img->mlx_win, 6, 0, mouse_move, img);
	mlx_loop(img->mlx);
    clear_tab(&s);
    close(s.fd);
    free(img);
    return (0);
}