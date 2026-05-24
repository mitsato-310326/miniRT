/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:42:08 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/24 12:28:46 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "camera.h"

t_camera init_camera()
{
    ENTRY("init_camera");

	t_camera new;
    double aspect_ratio = 16.0 / 9.0;
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    new.origin = init_vec_three(0, 0, 0);
    new.horizontal = init_vec_three(viewport_width, 0.0, 0.0);
    new.vertical = init_vec_three(0.0, viewport_height, 0.0);
    new.lower_left_corner = vec_three_neg(vec_three_neg(vec_three_neg(new.origin, vec_three_mult(new.horizontal, 0.5)), vec_three_mult(new.vertical, 0.5)), init_vec_three(0, 0, focal_length));
    return new;
}

t_ray get_ray(double u, double v, t_camera camera)
{
    ENTRY("get_ray");
	return init_ray(camera.origin, vec_three_add(vec_three_add(camera.lower_left_corner, vec_three_mult(camera.horizontal, u)), vec_three_neg(vec_three_mult(camera.vertical, v), camera.origin)));
}
