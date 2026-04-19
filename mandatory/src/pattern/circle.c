/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:01:24 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/18 18:32:47 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//deb
void print_vec_stat(t_vec_three v, char *_string)
{
	printf("%s\t: (x, %lf), (y, %lf), (z, %lf)\n", _string, v.x, v.y, v.z);
}
void print_ray_stat(t_ray* r)
{
	print_vec_stat(r->p_origin, "origin");
	print_vec_stat(r->v_dir, "dir");
}

// bool hit_sphere(t_vec_three *center, double radius, t_ray *r)
// {
// 	t_vec_three oc = vec_three_neg(r->p_origin, *center);
// 	// print_vec_stat(r->v_dir, "os");
// 	//   t_vec_three oc = r->p_origin - center;
// 	double a = dot(r->v_dir, r->v_dir);
// 	double b = 2.0 * dot(oc, r->v_dir);
// 	double c = dot(oc, oc) - radius*radius;
// 	double discriminant = b*b - 4*a*c;
// 	return (discriminant > 0);
// }

// t_vec_three ray_color(t_ray* r)
// {
// 	t_vec_three point3;
// 	point3.x = 0;
// 	point3.y = 0;
// 	point3.z = -1;

// 	if (hit_sphere(&point3, 0.5, r))
// 	{
// 		// print_ray_stat(r);
// 		t_vec_three color;
// 		color.x = 1;
// 		color.y = 0;
// 		color.z = 0;
// 		return color;
// 	}
// 	t_vec_three unit_direction = unit_vector(r->v_dir);

// 	t_vec_three color1;
// 	color1.x = 1.0;
// 	color1.y = 1.0;
// 	color1.z = 1.0;

// 	t_vec_three color2;
// 	color2.x = 0.5;
// 	color2.y = 0.7;
// 	color2.z = 1.0;

// 	double t = 0.5*(unit_direction.y + 1.0);
// 	// return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
// 	return (vec_three_add(vec_three_mult(color1, 1.0-t), vec_three_mult(color2, t)));
// }
