/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 20:54:48 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/10 21:06:58 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAMBERTIAN_H
# define LAMBERTIAN_H

#include "minirt.h"

typedef struct s_lambertian
{
  t_vec_three albedo;
}				t_lambertian;

bool scatter(t_ray *r_in, t_hit_record *rec, t_vec_three *attenuation, t_ray *scattered, t_lambertian *lambertian);

#endif
