/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:01:23 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/24 15:31:11 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

#include "hittable.h"
#include "minirt.h"

typedef struct t_vtable
{
	void (*hit)(unsigned int, char);
}				s_vtable;

typedef struct s_sphere
{
	t_vec_three origin;
	double	radius;
	t_material * material;
	t_hittable_type type;
}			t_sphere;

bool hit_sphere(double t_min, double t_max, t_sphere *sphere, t_ray *r, t_hit_record *rec);

#endif
