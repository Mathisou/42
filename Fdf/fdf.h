/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:41:02 by maroly            #+#    #+#             */
/*   Updated: 2022/01/22 18:54:31 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 600
# define WIDTH 800
# define LEFT 0
# define TOP 0

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
}				t_data;

typedef struct s_var
{
    char    ***tab;
    int     fd;
    int     count_y;
    int     count_x;
    int     zmin;
    int     zmax;
    int     size;
    int originx;
    int originy;
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

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>

char            *get_next_line(int fd);
//unsigned int    get_color(char *str);
int             ft_atoi_base(char *str, char *base);
t_pos iso(int x, int y, int z, t_var s);
void	bersenham(t_pos beg, t_pos end, t_data *mlx, unsigned int color);
void    background(t_data *img);
void	put_pixel(t_data *fdf, int x, int y, int color);
void    find_origin(t_var *s);
int    count_lines(t_var *s, char *map);
int    count_elem(t_var *s);
int ft_strcmp(char *s1, char *s2);
void    clear_tab(t_var *s);
int    check_map(t_var *s);
int parsing_map(t_var *s, char *map);

#endif