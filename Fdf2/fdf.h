/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:41:02 by maroly            #+#    #+#             */
/*   Updated: 2022/01/21 13:11:09 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 800
# define WIDTH 600
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
    int     sizex;
    int     sizey;
}   t_var;

typedef struct s_pos
{
    int x;
    int y;
    int x1;
    int x2;
    int y1;
    int y2;
    int z;
    int e;
    int dx;
    int dy;
}   t_pos;

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>

char    *get_next_line(int fd);

#endif