/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:01:23 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/18 19:38:18 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

#include "hittable.h"
#include "minirt.h"

// class sphere: public hittable {
// public:
//   sphere(point3 cen, double r) : center(cen), radius(r) {}

bool hit( t_ray* r, double tmin, double tmax, t_hit_record* rec , t_vec_three center, double radius);


#endif
