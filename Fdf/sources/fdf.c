/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:20:45 by maroly            #+#    #+#             */
/*   Updated: 2022/01/29 03:27:37 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_data	*img;
	t_pos	pos;
	t_var	s;
	t_mouse	is_pressed;

	img = malloc(sizeof(t_data));
	if (ac != 2)
		return (1);
	img->pos = &pos;
	img->mouse = &is_pressed;
	img->camera = &s;
	if (parsing_map(&s, av[1]) == 1)
		return (print_error(img, av, 1));
	if (check_map(&s) == 1)
		return (print_error(img, av, 2));
	init_struct(img, &s);
	draw(img->camera, img, img->pos);
	add_text(img);
	main_hook(img);
	mlx_loop(img->mlx);
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_window(img->mlx, img->mlx_win);
	return (0);
}
