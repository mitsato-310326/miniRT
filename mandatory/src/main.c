/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/10 21:06:26 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_mlxs	*mlxs;

	// PERROR
	mlxs = init();
	mlx_hook(mlxs->win, 17, 0, NULL, NULL);
	mlx_key_hook(mlxs->win, NULL, NULL);

	// for (int n = 0; n <= 1000; n++)
	// {
	// 	mlxs->data[n] = (char)255;
	// }

	print(mlxs);
	mlx_loop(mlxs->mlx);
	return (0);
}
