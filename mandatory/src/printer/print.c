/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:30:48 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/11 15:20:48 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
// #include "printer.h"

bool print(t_mlxs *mlxs)
{
	//first rendering
	mlx_string_put(mlxs->mlx, mlxs->win, 5, 0, 0xFF00FF, "Left Click:   Pan");
	mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, 0, 0);

	return(true);
}
