/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:30:48 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/24 15:33:01 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_pixel_put(char *data, int x, int y, int color)
{
	int	offset;

	int ry = HEIGHT - y;

	offset = (ry * WIDTH + x) * 4;
	data[offset + 0] = color & 0xFF;
	data[offset + 1] = (color >> 8) & 0xFF;
	data[offset + 2] = (color >> 16) & 0xFF;
	data[offset + 3] = 0;
}

bool print(t_mlxs *mlxs)
{
	ENTRY("print");

	// mlx_string_put(mlxs->mlx, mlxs->win, 5, 0, 0xFF00FF, "Left Click:   Pan");
	mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, 0, 0);

	return(true);
}
