/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:41:02 by maroly            #+#    #+#             */
/*   Updated: 2022/01/27 17:10:16 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 600
# define WIDTH 800
# define X_MARGIN 0
# define Y_MARGIN 0
# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

# include <stdbool.h>
# include "libft/libft.h"
# include "keyboard.h"
# include <mlx.h>
# include <math.h>

typedef struct s_mouse
{
    bool    is_pressed;
    int     x;
	int	    y;
	int		previous_x;
	int		previous_y;
}   t_mouse;

typedef struct s_var
{
    char    ***tab;
    int     fd;
    int     count_y;
    int     count_x;
    int     zmin;
    int     zmax;
    int     size;
    int     originx;
    int     originy;
    int     zoom;
    int     x_move;
    int     y_move;
    float     relief;
    int projection;
    double gamma;
    double alpha;
    double beta;
}   t_var;

typedef struct s_pos
{
    int x;
    int y;
    int z;
    int signx;
    int signy;
    int dx;
    int dy;
    unsigned int color;
}   t_pos;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void    *mlx;
	void    *mlx_win;
    int     height;
    int     width;
    t_var      *camera;
    t_mouse     *mouse;
    t_pos      *pos;
}	t_data;

char            *get_next_line(int fd);
int             ft_atoi_base(char *str, char *base);
void	iso(int *x, int *y, int z);
void	bersenham(t_pos beg, t_pos end, t_data *mlx, int sgn);
void    background(t_data *img);
void	put_pixel(t_data *fdf, int x, int y, int color);
void    find_origin(t_var *s);
int     count_lines(t_var *s, char *map);
int     count_elem(t_var *s);
int     ft_strcmp(char *s1, char *s2);
void    clear_tab(t_var *s);
int     check_map(t_var *s);
int     parsing_map(t_var *s, char *map);
int     destroy_window(void *param);
int     move(int keycode, t_data *img);
int     zoom(int keycode, t_data *img);
void    draw(t_var *s, t_data *img, t_pos *pos);
int     relief(int keycode, t_data *img);
int     plan(int keycode, t_data *img);
void    draw_cartesian(t_var *s, t_data *img, t_pos *pos);
int     ter_dw(int f, int s);
void	put_pixel(t_data *fdf, int x, int y, int color);
int     mouse_pressed(int button, int x, int y, t_data *img);
int     mouse_unpressed(int button, int x, int y, t_data *img);
int     mouse_move(int x, int y, t_data *img);
void	rotate_x(int *y, int *z, double alpha);
void	rotate_y(int *x, int *z, double beta);
void	rotate_z(int *x, int *y, double gamma);
int	get_default_color(int z, t_var *s);
int	get_color(t_pos current, t_pos start, t_pos end, t_pos delta);
void    main_hook(t_data *img);
void    add_text(t_data *img);
int controls(int keycode, void *param);
int rotation(int keycode, t_data *img);

#endif