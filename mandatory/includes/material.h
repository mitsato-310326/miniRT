/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:06:13 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/10 21:07:26 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

#include "hittable_list.h"
#include "minirt.h"

// bool scatter(t_ray *r_in, t_hit_record *rec, t_vec_three *attenuation, t_ray *scattered);

typedef struct s_material
{
	t_ray *r_in;
	t_ray *scattered;
	t_vec_three attenuation;
}			t_material;

#endif
