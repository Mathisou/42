/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:20:45 by maroly            #+#    #+#             */
/*   Updated: 2022/01/22 21:16:28 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int    destroy_window(t_data *img)
{
    mlx_clear_window(img->mlx, img->mlx_win);
    mlx_destroy_window(img->mlx, img->mlx_win);
    return (0);
}

int main(int ac, char **av)
{
    t_data img;
    t_pos pos;
    t_var s;

    if (ac != 2)
        return (1);
    if (parsing_map(&s, av[1]) == 1)
        return (1);
    if (check_map(&s) == 1)
        return (1);
    img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "FDF");
    img.img = mlx_new_image(img.mlx_win, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    background(&img);
    find_origin(&s);
    pos.y = -1;
    while (++pos.y < s.count_y)
    {
        pos.x = -1;
        while (++pos.x < s.count_x)
        {
            if (pos.x < s.count_x - 1)
                bersenham(iso(pos.x, pos.y, ft_atoi(s.tab[pos.y][pos.x]), s),
                iso(pos.x + 1, pos.y, ft_atoi(s.tab[pos.y][pos.x + 1]), s),
                &img, 0x9A1F6A);
            if (pos.y != s.count_y - 1)
                bersenham(iso(pos.x, pos.y, ft_atoi(s.tab[pos.y][pos.x]), s),
                iso(pos.x, pos.y + 1, ft_atoi(s.tab[pos.y + 1][pos.x]), s),
                &img, 0x9A1F6A);
        }
    }
    //mlx_hook(img.mlx_win, 17, 0, destroy_window, &img);
    //mlx_hook(img.mlx_win, 2, 1L<<2, destroy_window, &img);
    mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, LEFT, TOP);
    //mlx_key_hook(img.mlx_win, destroy_window, &img);
	mlx_loop(img.mlx);
    clear_tab(&s);
    close(s.fd);
    return (0);
}