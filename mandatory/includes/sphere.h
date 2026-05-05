/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:01:23 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/05 16:52:23 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

#include "hittable.h"
#include "minirt.h"

typedef struct s_sphere
{
	t_vec_three origin;
	double	radius;
}			t_sphere;

bool hit( t_ray* r, double tmin, double tmax, t_hit_record* rec , t_vec_three center, double radius);
bool hit_sphere(double t_min, double t_max, t_vec_three *center, double radius, t_ray *r, t_hit_record *rec);

#endif
