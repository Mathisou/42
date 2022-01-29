/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:21:31 by maroly            #+#    #+#             */
/*   Updated: 2022/01/28 15:21:51 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_mouse
{
	bool	is_pressed;
	int		x;
	int		y;
	int		previous_x;
	int		previous_y;
}	t_mouse;

typedef struct s_var
{
	char	***tab;
	int		fd;
	int		count_y;
	int		count_x;
	int		zmin;
	int		zmax;
	int		size;
	int		originx;
	int		originy;
	int		zoom;
	int		x_move;
	int		y_move;
	float	relief;
	int		projection;
	double	gamma;
	double	alpha;
	double	beta;
}	t_var;

typedef struct s_pos
{
	int				x;
	int				y;
	int				z;
	int				signx;
	int				signy;
	int				dx;
	int				dy;
	unsigned int	color;
}	t_pos;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	int		height;
	int		width;
	int		error[2];
	t_var	*camera;
	t_mouse	*mouse;
	t_pos	*pos;
}	t_data;

#endif
