/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:18:54 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/24 16:08:19 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

#include "camera.h"

/*											*/

typedef struct s_vec_three t_vec_three;
typedef struct s_hittable_list t_hittable_list;

/*					UTILS					*/

int view_calc(t_mlxs *mlx);
t_vec_three ray_color(t_ray* r, t_hittable_list *world, int depth);

/*					DEBUG					*/

/*											*/

#endif
