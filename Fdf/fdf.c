/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:40:24 by maroly            #+#    #+#             */
/*   Updated: 2022/01/13 14:48:37 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main()
{
    void *mlx = mlx_init();

    mlx_new_window(mlx, 1920, 1080, "Fdf");
    return (0);
}