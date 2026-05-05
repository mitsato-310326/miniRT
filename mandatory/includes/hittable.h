/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:58:40 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/05 17:22:31 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
#define HITTABLE_H

# include "minirt.h"

typedef struct s_hit_record {
  t_vec_three p;
  t_vec_three normal;
  double t;
  bool front_face;
}				t_hit_record;

bool hit_sphere(double t_min, double t_max, t_vec_three *center, double radius, t_ray *r, t_hit_record *rec);

#endif
