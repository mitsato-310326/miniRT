/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/12 13:02:00 by mitsato          ###   ########.fr       */
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
		mlx_destroy_display(mlxs->mlx);
		free(mlxs->mlx);
		free(mlxs);
	}
	return(0);
}

void set_colorset(char *data)
{
	const int image_width = 256;
	const int image_height = 256;

	// printf("P3\n%d %d\n255\n", image_width, image_height);

	for (int j = image_height-1; j >= 0; --j) {
		for (int i = 0; i < image_width; ++i) {
		double r = (double)(i) / (image_width-1);
		double g = (double)(j) / (image_height-1);
		double b = 0.25;

		int ir = (int)(255.999 * r);
		int ig = (int)(255.999 * g);
		int ib = (int)(255.999 * b);

		// printf("%d %d %d\n", ir, ig, ib);
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

	set_colorset(mlxs->data);

	print(mlxs);
	mlx_loop(mlxs->mlx);
	destroy_minirt(mlxs);
	return (0);
}
