/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:30:48 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/28 22:21:01 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_pixel_put(char *data, int x, int y, double scale, t_vec_three *color)
{
	// int i_color;
	double ir = color->x;
	double ig = color->y;
	double ib = color->z;

	ir = sqrt(scale * ir);
	ig = sqrt(scale * ig);
	ib = sqrt(scale * ib);

	int r = (256 * clamp(ir, 0.0, 0.999));
	int g = (256 * clamp(ig, 0.0, 0.999));
	int b = (256 * clamp(ib, 0.0, 0.999));

	// i_color = (r * 256 * 256) + (g * 256) + b;

	int	offset;

	int ry = HEIGHT - y;

	offset = (ry * WIDTH + x) * 4;
	data[offset + 0] = b & 0xFF;
	data[offset + 1] = g & 0xFF;
	data[offset + 2] = r & 0xFF;
	// data[offset + 3] = 0;
}

bool print(t_mlxs *mlxs)
{
	ENTRY("print");

	// mlx_string_put(mlxs->mlx, mlxs->win, 5, 0, 0xFF00FF, "Left Click:   Pan");
	mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, 0, 0);

	return(true);
}
