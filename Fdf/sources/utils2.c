/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:17:49 by maroly            #+#    #+#             */
/*   Updated: 2022/01/28 19:54:11 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	add_text(t_data *img)
{
	mlx_string_put(img->mlx, img->mlx_win, 10, 10, 0x00FFFFFF,
		"Zoom : '+' '-' / scroll");
	mlx_string_put(img->mlx, img->mlx_win, 10, 30, 0x00FFFFFF,
		"Relief : 'z' 'x'");
	mlx_string_put(img->mlx, img->mlx_win, 10, 50, 0x00FFFFFF,
		"Plan : 'c' 'i'");
	mlx_string_put(img->mlx, img->mlx_win, 10, 70, 0x00FFFFFF,
		"Move : 'left' 'right'");
	mlx_string_put(img->mlx, img->mlx_win, 10, 90, 0x00FFFFFF,
		"        'top' 'down'");
	mlx_string_put(img->mlx, img->mlx_win, 10, 110, 0x00FFFFFF,
		"Rot : mouse / 1-6");
}

void	main_hook(t_data *img)
{
	mlx_hook(img->mlx_win, 2, 0, controls, img);
	mlx_hook(img->mlx_win, 17, 0, destroy_window, img);
	mlx_hook(img->mlx_win, 4, 0, mouse_pressed, img);
	mlx_hook(img->mlx_win, 5, 0, mouse_unpressed, img);
	mlx_hook(img->mlx_win, 6, 0, mouse_move, img);
}

int	destroy_window(t_data *img)
{
	//mlx_destroy_image(img->mlx, img->img);
	//mlx_destroy_window(img->mlx, img->mlx_win);
	free(img->mlx);
	clear_tab(*(&img));
	//close(img->camera->fd);
	//free(img);
	exit (0);
}

void	init_struct(t_data *img, t_var *s)
{
	s->relief = 6;
	s->projection = ISO;
	s->originx = 0;
	s->originy = 0;
	if ((WIDTH - (LEFT * 2)) / s->count_x
		< (HEIGHT - (Y_MARGIN * 2)) / s->count_y)
		s->zoom = ((WIDTH - (X_MARGIN * 2)) / s->count_x) / 3 * 2;
	else
		s->zoom = ((HEIGHT - (Y_MARGIN * 2)) / s->count_y) / 3 * 2;
	if (s->zoom == 0)
		s->zoom = 1;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "FDF");
	img->img = mlx_new_image(img->mlx_win, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int	print_error(t_data *img, char **av, int sign)
{
	if (sign == 1)
		perror(av[1]);
	else if (sign == 2)
	{
		ft_putstr_fd("Invalid map!\n", 2);
		clear_tab(img);
	}
	free(img);
	return (1);
}
