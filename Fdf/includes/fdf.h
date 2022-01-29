/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:41:02 by maroly            #+#    #+#             */
/*   Updated: 2022/01/29 02:59:48 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 800
# define WIDTH 1080
# define X_MARGIN 0
# define Y_MARGIN 0
# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

# include <stdbool.h>
# include "../sources/libft/libft.h"
# include "keyboard.h"
# include "struct.h"
# include <mlx.h>
# include <math.h>

char	*get_next_line(int fd);
void	iso(int *x, int *y, int z);
void	bersenham(t_pos beg, t_pos end, t_data *mlx);
void	background(t_data *img);
void	put_pixel(t_data *fdf, int x, int y, int color);
void	find_origin(t_var *s);
int		count_lines(t_var *s, char *map);
int		count_elem(t_var *s);
int		ft_strcmp(char *s1, char *s2);
void	clear_tab(t_data *img);
int		check_map(t_var *s);
int		parsing_map(t_var *s, char *map);
int		destroy_window(t_data *img);
int		move(int keycode, t_data *img);
int		zoom(int keycode, t_data *img);
void	draw(t_var *s, t_data *img, t_pos *pos);
int		relief(int keycode, t_data *img);
int		plan(int keycode, t_data *img);
void	draw_cartesian(t_var *s, t_data *img, t_pos *pos);
int		ter_dw(int f, int s);
void	put_pixel(t_data *fdf, int x, int y, int color);
int		mouse_pressed(int button, int x, int y, t_data *img);
int		mouse_unpressed(int button, int x, int y, t_data *img);
int		mouse_move(int x, int y, t_data *img);
void	rotate_x(int *y, int *z, double alpha);
void	rotate_y(int *x, int *z, double beta);
void	rotate_z(int *x, int *y, double gamma);
int		get_default_color(int z, t_var *s);
int		get_color(t_pos current, t_pos start, t_pos end, t_pos delta);
void	main_hook(t_data *img);
void	add_text(t_data *img);
int		controls(int keycode, void *param);
int		rotation(int keycode, t_data *img);
int		ter_dw(int f, int s);
t_pos	new_point(int x, int y, int z, t_var *s);
t_pos	project(t_pos p, t_data *img);
int		controls(int keycode, void *param);
void	init_struct(t_data *img, t_var *s);
int		print_error(t_data *img, char **av, int sign);

#endif