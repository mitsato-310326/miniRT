/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:01:23 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/05 17:22:04 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec_three ray_color(t_ray* r, t_hittable_list *world, int depth)
{
	if (depth <= 0)
		return init_vec_three(0,0,0);
	t_hit_record rec;

	if (list_hit(r, 0, INFINITY, &rec, world))
	{
		t_vec_three target = (vec_three_add(rec.p, rec.normal), random_in_unit_sphere());
		// return 0.5 * ray_color(ray(rec.p, target - rec.p), world);
		t_ray ray = init_ray(rec.p, vec_three_neg(target, rec.p));
		return vec_three_mult(ray_color(&ray, world, depth -1), 0.5);
		// return vec_three_mult(vec_three_add(rec.normal, init_vec_three(1, 1, 1)), 0.5);
	}

	t_vec_three unit_direction = unit_vector(r->v_dir);
	double t = 0.5*(unit_direction.y + 1.0);

	t_vec_three color1 = init_vec_three(1.0, 1.0, 1.0);
	t_vec_three color2 = init_vec_three(0.5, 0.7, 1.0);
	return (vec_three_add(vec_three_mult(color1, 1.0 - t), vec_three_mult(color2, t)));
}
