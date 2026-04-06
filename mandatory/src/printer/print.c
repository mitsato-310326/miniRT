/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:30:48 by mitsato           #+#    #+#             */
/*   Updated: 2026/03/26 21:56:58 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
// #include "printer.h"

bool print(t_mlxs *mlxs)
{
	mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, 0, 0);
	// mlx_string_put(mlxs->mlx, mlxs->mlx, 5, 0, 0xFFFFFF, "Left Click:   Pan");
	return(true);
}
