/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 20:54:48 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/24 16:37:23 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAMBERTIAN_H
# define LAMBERTIAN_H

#include "minirt.h"

// typedef struct s_lambertian
// {
//   t_vec_three albedo;
// }				t_lambertian;

bool list_scatter(t_ray *r_in, t_hit_record *rec, t_vec_three *attenuation, t_ray *scattered, t_material *material);
bool scatter(t_ray *r_in, t_hit_record *rec, t_vec_three *attenuation, t_ray *scattered, void *material);
bool scatter_metal(t_ray *r_in, t_hit_record *rec, t_vec_three *attenuation, t_ray *scattered, void *material);

#endif
