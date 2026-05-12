/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:18:37 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/12 20:19:51 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "lambertian.h"

bool list_scatter(t_ray *r_in, t_hit_record *rec, t_vec_three *attenuation, t_ray *scattered, t_material *material)
{
	if (material->type == METAL)
		return scatter_metal(r_in, rec, attenuation, scattered, material);
	if (material->type == LAMBERTIAN)
		return scatter(r_in, rec, attenuation, scattered, material);
	PERROR
	return false;
}

bool scatter_metal(t_ray *r_in, t_hit_record *rec, t_vec_three *attenuation, t_ray *scattered, t_material *material)
{
	t_vec_three tmp = unit_vector(r_in->v_dir);
	t_vec_three reflected = reflect(&tmp, &rec->normal);
	*scattered = init_ray(rec->p, reflected);
	*attenuation = material->albedo;
	return (dot(scattered->v_dir, rec->normal) > 0);
}
