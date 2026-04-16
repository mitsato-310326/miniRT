/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/16 21:13:26 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int destroy_minirt(t_mlxs *mlxs)
{
	if (mlxs && mlxs->img)
		mlx_destroy_image(mlxs->mlx, mlxs->img);
	if (mlxs && mlxs->win)
		mlx_destroy_window(mlxs->mlx, mlxs->win);
	if (mlxs)
	{
		ft_mlx_destroy_display(mlxs->mlx);
		free(mlxs->mlx);
		free(mlxs);
	}
	return(0);
}

void set_colorset(char *data)
{
	const int image_width = 320;
	const int image_height = 180;

	for (int j = image_height-1; j >= 0; --j) {
		for (int i = 0; i < image_width; ++i) {
		double r = (double)(i) / (image_width-1);
		double g = (double)(j) / (image_height-1);
		double b = 0.25;

		int ir = (int)(255.999 * r);
		int ig = (int)(255.999 * g);
		int ib = (int)(255.999 * b);

		my_pixel_put(data, i, j, (ir * 256 * 256) + (ig * 256) + ib);
		}
	}
}

int	main(void)
{
	t_mlxs	*mlxs;

	// PERROR
	mlxs = init();
	mlx_hook(mlxs->win, 17, 0, stop_minirt, mlxs);
	mlx_key_hook(mlxs->win, key_handler, mlxs);

	// set_colorset(mlxs->data);
	sky(mlxs->data);
	// put_circle();

	// int color = 0xFF0F00;
	// for (int i = 0; i <= 40; ++i)
	// {
	// 	for (int i2 = 0; i2 <= 40; ++i2)
	// 	{
	// 		int offset = (i2 * WIDTH + i) * 4;
	// 		mlxs->data[offset + 0] = color & 0xFF;
	// 		mlxs->data[offset + 1] = (color >> 8) & 0xFF;
	// 		mlxs->data[offset + 2] = (color >> 16) & 0xFF;
	// 		mlxs->data[offset + 3] = 0;
	// 	}
	// }

	print(mlxs);
	mlx_loop(mlxs->mlx);
	destroy_minirt(mlxs);
	return (0);
}
