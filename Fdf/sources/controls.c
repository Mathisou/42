/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:23:21 by maroly            #+#    #+#             */
/*   Updated: 2022/01/28 19:33:04 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	controls(int keycode, void *param)
{
	if (keycode == ESC)
		destroy_window(param);
	else if (keycode == LEFT || keycode == RIGHT
		|| keycode == DOWN || keycode == UP)
		move(keycode, param);
	else if (keycode == PLUS || keycode == PLUS_NUM
		|| keycode == MINUS || keycode == MINUS_NUM)
		zoom(keycode, param);
	else if (keycode == Z || keycode == X)
		relief(keycode, param);
	else if (keycode == CARTESIAN || keycode == ISO)
		plan(keycode, param);
	else if (keycode == NUM_1 || keycode == NUM_2 || keycode == NUM_3
		|| keycode == NUM_4 || keycode == NUM_5 || keycode == NUM_6)
		rotation(keycode, param);
	return (0);
}
