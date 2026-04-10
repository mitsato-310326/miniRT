/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:30:48 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/10 20:55:34 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
// #include "printer.h"

bool print(t_mlxs *mlxs)
{
	mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, 0, 0);
	// mlx_string_put(mlxs->mlx, mlxs->mlx, 5, 0, 0xFFFFFF, "Left Click:   Pan");
	//キーの入力検知（キーフック）からレンダリングを呼べば適した回数のレンダリングになる。
	return(true);
}
