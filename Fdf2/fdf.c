/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:20:45 by maroly            #+#    #+#             */
/*   Updated: 2022/01/21 13:46:13 by maroly           ###   ########.fr       */
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

/*void	my_mlx_pixel_put(t_data *data, t_pos pos, int color)
{
	int		i;

	if (pos.x1 < WIDTH && pos.y1 >= 0 && pos.y1 < HEIGHT)
	{
		i = (pos.x1 * data->bits_per_pixel / 8) + (pos.y1 * data->line_length);
		data->addr[i] = color;
		data->addr[++i] = color >> 8;
		data->addr[++i] = color >> 16;
	}
}*/

void    my_mlx_pixel_put(t_data *data, t_pos *pos, int color)
{
	char *dst;

    //printf("%d et %d\n", pos->y1, pos->x1);
	dst = data->addr + (pos->y1 * data->line_length + pos->x1 * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int    count_elem(t_var *s)
{
    s->count_x = 0;
    while (s->tab[0][s->count_x])
        s->count_x++;
    s->count_x--;
    return (s->count_x);
}

int    count_lines(t_var *s, char *map)
{
    char buffer;

    s->count_y = 0;
    s->fd = open(map, O_RDONLY);
    if (s->fd == -1)
        return (1);
    while (read(s->fd, &buffer, 1) > 0)
    {
        if (buffer == '\n' || buffer == '\0')
            s->count_y++;
    }
    close(s->fd);
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
    *s->tab = ft_split(get_next_line(s->fd), ' ');
    count_elem(s);
    while (s->tab[i++])
        s->tab[i] = ft_split(get_next_line(s->fd), ' ');
    return (0);
}

void iso(int *x, int *y, int z, t_var s)
{
    int previous_x;
    int previous_y;

    (void)s;
    /*if ((WIDTH - (LEFT * 2)) / s.count_x < (HEIGHT - (TOP * 2)) / s.count_y)
        s.sizex = ((WIDTH - (LEFT * 2)) / s.count_x) / 3 * 2;
    else
        s.sizex = ((HEIGHT - (TOP * 2)) / s.count_y) / 3 * 2;
    printf("%d\n", s.sizex);*/
    previous_x = *x * (25 * 86 / 100);
    previous_y = *y * 25 - (-z * 4);
    //*x = (previous_x - previous_y) * cos(0.523599) + 250;
    *x = (z *4) + (previous_x - previous_y) * cos(0.523599) + 250;
    *y = (-z * 4) + (previous_x + previous_y) * sin(0.523599) + 250; // add "(-z * 3) + ..." at start
}

void bersenham(t_pos pos, t_data *img)
{
    if (pos.x1 < pos.x2 && pos.y1 < pos.y2)
        while (pos.x1 <= pos.x2)
        {
            my_mlx_pixel_put(img, &pos, 0x0000FF00);
            pos.x1++;
            pos.e-=pos.dy;
            if (pos.e < 0)
            {
                pos.y1++;
                pos.e+=pos.dx;
            }
        }
        else if (pos.x1 > pos.x2 && pos.y1 < pos.y2)
            while (pos.x1 >= pos.x2)
            {
                my_mlx_pixel_put(img, &pos, 0x0000FF00);
                pos.x1--;
                pos.e-=pos.dy;
                if (pos.e < 0)
                {
                    pos.y1++;
                    pos.e+=pos.dx;
                }
            }
        else if (pos.x1 > pos.x2 && pos.y1 > pos.y2)
            while (pos.x1 >= pos.x2)
            {
                my_mlx_pixel_put(img, &pos, 0x0000FF00);
                pos.x1--;
                pos.e-=pos.dy;
                if (pos.e < 0)
                {
                    pos.y1--;
                    pos.e+=pos.dx;
                }
            }
        else if (pos.x1 < pos.x2 && pos.y1 > pos.y2)
            while (pos.x1 <= pos.x2)
            {
                my_mlx_pixel_put(img, &pos, 0x0000FF00);
                pos.x1++;
                pos.e-=pos.dy;
                if (pos.e < 0)
                {
                    pos.y1--;
                    pos.e+=pos.dx;
                }
            }
}

int main(int ac, char **av) //trouver un moyen de relier les reliefs entre eux (jpense que mon x2 n'est pas bon)
{
    t_data img;
    t_pos pos;
    t_var s;

    if (ac != 2)
        return (1);
    if (parsing_map(&s, av[1]) == 1)
        return (1);
    img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, HEIGHT, WIDTH, "FDF");
    img.img = mlx_new_image(img.mlx_win, HEIGHT, WIDTH);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    count_elem(&s);
    pos.y = -1;
    while (++pos.y < s.count_y)
    {
        pos.x = -1;
        while (++pos.x < s.count_x)
        {
            pos.x1 = pos.x;
            pos.y1 = pos.y;
            pos.x2 = pos.x1 + 1;
            pos.y2 = pos.y1;
            pos.z = ft_atoi(s.tab[pos.y1][pos.x1]);
            iso(&pos.x1, &pos.y1, pos.z, s);
            pos.z = ft_atoi(s.tab[pos.y2][pos.x2]);
            iso(&pos.x2, &pos.y2, pos.z, s);
            pos.e=abs(pos.x2-pos.x1);
            pos.dx=2*pos.e;
            pos.dy=2*abs(pos.y2-pos.y1);
            bersenham(pos, &img);
            if (pos.y < s.count_y - 1)
            {
                pos.x1 = pos.x;
                pos.y1 = pos.y;
                pos.x2 = pos.x1;
                pos.y2 = pos.y1 + 1;
                pos.z = ft_atoi(s.tab[pos.y1][pos.x1]);
                iso(&pos.x1, &pos.y1, pos.z, s);
                pos.z = ft_atoi(s.tab[pos.y2][pos.x2]);
                iso(&pos.x2, &pos.y2, pos.z, s);
                pos.e=abs(pos.x2-pos.x1);
                pos.dx=2*pos.e;
                pos.dy=2*abs(pos.y2-pos.y1);
                bersenham(pos, &img);
            }
            if (pos.x + 1 == s.count_x && pos.y < s.count_y - 1)
            {
                pos.x1 = pos.x + 1;
                pos.y1 = pos.y;
                pos.x2 = pos.x1;
                pos.y2 = pos.y1 + 1;
                pos.z = ft_atoi(s.tab[pos.y1][pos.x1]);
                iso(&pos.x1, &pos.y1, pos.z, s);
                pos.z = ft_atoi(s.tab[pos.y2][pos.x2]);
                iso(&pos.x2, &pos.y2, pos.z, s);
                pos.e=abs(pos.x2-pos.x1);
                pos.dx=2*pos.e;
                pos.dy=2*abs(pos.y2-pos.y1);
                bersenham(pos, &img);
            }
        }
    }
    mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, LEFT, TOP);
	mlx_loop(img.mlx);
    return (0);
}