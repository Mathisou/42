/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:20:45 by maroly            #+#    #+#             */
/*   Updated: 2022/01/22 02:36:28 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;
    
    i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    return (0);
}

static void	put_pixel(t_data *fdf, int x, int y, int color)
{
	int		i;

	if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->line_length);
		fdf->addr[i] = color;
		fdf->addr[++i] = color >> 8;
		fdf->addr[++i] = color >> 16;
	}
}

int    count_elem(t_var *s)
{
    s->count_x = 0;
    while (s->tab[0][s->count_x] && ft_strcmp(s->tab[0][s->count_x], "\n") == 1)
        s->count_x++;
    return (s->count_x);
}

int    count_lines(t_var *s, char *map)
{
    char *str;

    s->count_y = 0;
    s->fd = open(map, O_RDONLY);
    if (s->fd == -1)
        return (1);
    str = get_next_line(s->fd);
    while (str != NULL)
    {
        str = get_next_line(s->fd);
        s->count_y++;
    }
    free(str);
    return (0); 
}

int parsing_map(t_var *s, char *map)
{
    int i;

    i = 0;
    if (count_lines(s, map) == 1)
        return (1);
    s->fd = open(map, O_RDONLY);
    if (s->fd == -1)
        return (1);
    s->tab = malloc(sizeof(char **) * (s->count_y + 1));
    if (!s->tab)
        return (1);
    s->tab[i] = ft_split(get_next_line(s->fd), ' ');
    count_elem(s);
    while (s->tab[i++])
        s->tab[i] = ft_split(get_next_line(s->fd), ' ');
    close(s->fd);
    return (0);
}

 t_pos iso(int x, int y, int z, t_var s)
{
    int previous_x;
    int previous_y;
    t_pos pos;

    (void)s;
    if ((WIDTH - (LEFT * 2)) / s.count_x < (HEIGHT - (TOP * 2)) / s.count_y)
        s.size = ((WIDTH - (LEFT * 2)) / s.count_x) / 3 * 2;
    else
        s.size = ((HEIGHT - (TOP * 2)) / s.count_y) / 3 * 2;
    previous_x = x * (s.size * 86 / 100);
    previous_y = y * s.size;
    pos.x = (previous_x - previous_y) * cos(0.523599) + 500;
    pos.y = -(z * 4) + (previous_x + previous_y) * sin(0.523599) + 50;
    return (pos);
}

int	ter_dw(int f, int s)
{
	if (f < s)
		return (1);
	return (-1);
}

void	bersenham(t_pos beg, t_pos end, t_data *mlx, unsigned int color)
{
	t_pos	delta;
	t_pos   sign;
	int		error[2];

	delta.dx = abs(end.x - beg.x);
	delta.dy = abs(end.y - beg.y);
	sign.signx = ter_dw(beg.x, end.x);
	sign.signy = ter_dw(beg.y, end.y);
	error[0] = delta.dx - delta.dy;
	while (beg.x != end.x || beg.y != end.y)
	{
        put_pixel(mlx, beg.x, beg.y, color);
        error[1] = error[0] * 2;
        if (error[1] > -delta.dy)
		{
			error[0] -= delta.dy;
			beg.x += sign.signx;
		}
		if (error[1] < delta.dx)
		{
			error[0] += delta.dx;
			beg.y += sign.signy;
		}
	}
}

void    background(t_data *img)
{
    t_pos   beg;
    t_pos   end;

    beg.x = -1;
    while (++beg.x < WIDTH)
    {
        beg.y = 0;
        end.x = beg.x;
        end.y = HEIGHT;
        bersenham(beg, end, img, 0x222222);
    }
}

void    clear_tab(t_var *s)
{
    int i;
    int j;

    i = -1;
    while (s->tab[++i])
    {
        j = -1;
        while (s->tab[i][++j])
            free(s->tab[i][j]);
        free(s->tab[i]);
    }
    free(s->tab);
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
    img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "FDF");
    img.img = mlx_new_image(img.mlx_win, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    pos.y = -1;
    background(&img);
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
    mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, LEFT, TOP);
	mlx_loop(img.mlx);
    clear_tab(&s);
    close(s.fd);
    return (0);
}