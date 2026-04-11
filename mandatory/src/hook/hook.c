/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/11 15:07:14 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int stop_minirt(void *v_mlxs)
{
	mlx_loop_end(((t_mlxs *)v_mlxs)->mlx);
	return (0);
}

int	key_handler(int keycode, void *v_mlxs)
{
	if (keycode == 0xFF1B)
		mlx_loop_end(((t_mlxs *)v_mlxs)->mlx);
	return (0);
}
