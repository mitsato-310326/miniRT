/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/03/26 21:51:20 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main()
{
	// PERROR
	t_mlxs *mlxs = init();

	mlx_hook(mlxs->win, 17, 0, NULL, NULL);
	mlx_key_hook(mlxs->win, NULL, NULL);
	print(mlxs);
	mlx_loop(mlxs->mlx);
	return (0);
}
