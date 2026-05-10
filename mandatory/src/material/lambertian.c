/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 21:01:06 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/10 21:11:06 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "lambertian.h"

bool scatter(t_ray *r_in, t_hit_record *rec, t_vec_three *attenuation, t_ray *scattered, t_lambertian *lambertian)
{
	(void)r_in;
	
    t_vec_three scatter_direction = vec_three_add(rec->normal, random_in_unit_sphere());
    *scattered = init_ray(rec->p, scatter_direction);
    *attenuation = lambertian->albedo;
    return true;
}
