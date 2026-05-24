/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/24 16:15:19 by mitsato          ###   ########.fr       */
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

int	main(void)
{
	t_mlxs	*mlxs;

	mlxs = init();
	mlxs->cam = init_camera();
	mlx_hook(mlxs->win, 17, 0, stop_minirt, mlxs);
	mlx_key_hook(mlxs->win, key_handler, mlxs);

	view_calc(mlxs);

	print(mlxs);
	mlx_loop(mlxs->mlx);
	destroy_minirt(mlxs);
	PERROR
	return (0);
}
