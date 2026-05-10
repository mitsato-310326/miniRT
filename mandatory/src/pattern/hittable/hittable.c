/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:05:31 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/10 20:52:36 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void set_face_normal(t_ray *r, t_vec_three *outward_normal, t_hit_record *rec)
{
	rec->front_face = dot(r->v_dir, *outward_normal) < 0;
	if (rec->front_face)
		rec->normal = *outward_normal;
	else
		rec->normal = vec_three_mult(*outward_normal, -1.0);
}

bool hit_sphere(double t_min, double t_max, t_sphere *sphere, t_ray *r, t_hit_record *rec)
{
	double radius = sphere->radius;
	t_vec_three *center = &sphere->origin;
	t_vec_three oc = vec_three_neg(r->p_origin, *center);
	double a = dot(r->v_dir, r->v_dir);
	double half_b = dot(oc, r->v_dir);
	double c = dot(oc, oc) - radius*radius;
	double discriminant = half_b*half_b - a*c;

	if (discriminant > 0)
	{
		double root = sqrt(discriminant);
		double temp = (-half_b - root) / a;
		if (temp < t_max && temp > t_min) {
			rec->t = temp;
			rec->p = ray_at(*r, rec->t);
			t_vec_three outward_normal = vec_three_mult(vec_three_neg(rec->p, *center), 1 / radius);
			set_face_normal(r, &outward_normal, rec);
			rec->material = sphere->material;
			return true;
		}
		temp = (-half_b + root) / a;
		if (temp < t_max && temp > t_min) {
			rec->t = temp;
			rec->p = ray_at(*r, rec->t);
			t_vec_three outward_normal = vec_three_mult(vec_three_neg(rec->p, *center), 1 / radius);
			set_face_normal(r, &outward_normal, rec);
			rec->material = sphere->material;
			return true;
		}
	}
	return false;
}

// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/04/18 19:05:31 by mitsato           #+#    #+#             */
// /*   Updated: 2026/05/10 20:52:11 by mitsato          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <stdio.h>

// int	add_func(int a, int b)
// {
// 	return (a + b);
// }

// int	sub_func(int a, int b)
// {
// 	return (a - b);
// }

// int	mul_func(int a, int b)
// {
// 	return (a * b);
// }

// int	div_func(int a, int b)
// {
// 	if (b == 0)
// 		return (0);
// 	return (a / b);
// }

// int	main(void)
// {
// 	int	(*p_tbl[4])(int, int);
// 	int	operation;
// 	int	a;
// 	int	b;
// 	int	result;

// 	p_tbl[0] = add_func;
// 	p_tbl[1] = sub_func;
// 	p_tbl[2] = mul_func;
// 	p_tbl[3] = div_func;
// 	a = 10;
// 	b = 5;
// 	printf("演算を選択してください。(0:Add, 1:Sub, 2:Mul, 3:Div)：");
// 	if (scanf("%d", &operation) != 1 || operation < 0 || operation > 3)
// 		return (1);
// 	result = p_tbl[operation](a, b);
// 	printf("演算結果：%d\n", result);
// 	return (0);
// }
