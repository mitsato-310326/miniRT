/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:01:23 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/04 15:14:24 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double hit_sphere(t_vec_three *center, double radius, t_ray *r)
{
	t_vec_three oc = vec_three_neg(r->p_origin, *center);
	// print_vec_stat(r->v_dir, "os");
	//   t_vec_three oc = r->p_origin - center;
	double a = dot(r->v_dir, r->v_dir);
	double half_b = dot(oc, r->v_dir);
	double c = dot(oc, oc) - radius*radius;
	double discriminant = half_b*half_b - a*c;
	// printf("%f\n", (-half_b - sqrt(discriminant) ) / a);
	if (discriminant < 0)
	{
		return -1.0;
	}
	else
	{
		return (-half_b - sqrt(discriminant) ) / a;
	}
}

// double hit_sphere(t_vec_three *center, double radius, t_ray *r)
// {
//   vec3 oc = r.origin() - center;
//   auto a = dot(r.direction(), r.direction());
//   auto b = 2.0 * dot(oc, r.direction());
//   auto c = dot(oc, oc) - radius*radius;
//   auto discriminant = b*b - 4*a*c;
//   if (discriminant < 0) {
//     return -1.0;
//   } else {
//     return (-b - sqrt(discriminant) ) / (2.0*a);
//   }
// }

t_vec_three ray_color(t_ray* r, t_hittable_list **world)
{
	double t = 1;
	bool already_hit = false;
	t_vec_three ret;
	int i = 0;
	t_hittable_list *temp = *world;

	while (temp)
	{
		++i;
		// printf("%d, %p\n", i, temp);
		t = hit_sphere(&(((t_hit_record *)(temp->content))->p), ((t_sphere *)(temp->content))->radius, r);
		if (t > 0.0) {
			// t_vec_three  N = unit_vector(r.at(t) - vec3(0,0,-1));
			t_vec_three  N = unit_vector(vec_three_neg(ray_at(*r, t), ((t_hit_record *)(temp->content))->p));
			ret.x = N.x + 1;
			ret.y = N.y + 1;
			ret.z = N.z + 1;

			already_hit = true;
			// printf("%f\n",  N.y);
		}
		t_vec_three unit_direction = unit_vector(r->v_dir);
		t = 0.5*(unit_direction.y + 1.0);
		// break;
		temp = temp->next;
	}
	if (already_hit)
		return vec_three_mult(ret, 0.5);
	t_vec_three color1;
	color1.x = 1.0;
	color1.y = 1.0;
	color1.z = 1.0;

	t_vec_three color2;
	color2.x = 0.5;
	color2.y = 0.7;
	color2.z = 1.0;
	return (vec_three_add(vec_three_mult(color1, 1.0 - t), vec_three_mult(color2, t)));
}

// t_vec_three ray_color(t_ray* r, t_hittable_list **world)
// {
// 	double t;
// 	t_hit_record *test = NULL;
// 	while (*world)
// 	{
// 		// t = list_hit(&(((t_hit_record *)((*world)->content))->p), 0, 100, r);
// 		list_hit(r, -100000000, 100000000, test, *world);
// 		t = test.;
// 		printf("%lf\n", t);
// 		// t = hit_sphere(&(((t_hit_record *)((*world)->content))->p), 100, r);
// 		if (t > 0.0) {
// 			// t_vec_three  N = unit_vector(r.at(t) - vec3(0,0,-1));
// 			t_vec_three  N = unit_vector(vec_three_neg(ray_at(*r, t), ((t_hit_record *)((*world)->content))->p));
// 			t_vec_three ret;
// 			ret.x = N.x + 1;
// 			ret.y = N.y + 1;
// 			ret.z = N.z + 1;
// 			return vec_three_mult(ret, 0.5);
// 		}
// 		t_vec_three unit_direction = unit_vector(r->v_dir);



// 		t = 0.5*(unit_direction.y + 1.0);
// 		// return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
// 		world = &((*world)->next);
// 	}
// 	t_vec_three color1;
// 	color1.x = 1.0;
// 	color1.y = 1.0;
// 	color1.z = 1.0;

// 	t_vec_three color2;
// 	color2.x = 0.5;
// 	color2.y = 0.7;
// 	color2.z = 1.0;
// 	return (vec_three_add(vec_three_mult(color1, 1.0-t), vec_three_mult(color2, t)));
// }

// color ray_color(ray& r) {
//   auto t = hit_sphere(point3(0,0,-1), 0.5, r);
//   if (t > 0.0) {
//     vec3 N = unit_vector(r.at(t) - vec3(0,0,-1));
//     return 0.5*color(N.x()+1, N.y()+1, N.z()+1);
//   }
//   vec3 unit_direction = unit_vector(r.direction());
//   t = 0.5*(unit_direction.y() + 1.0);
//   return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
// }
