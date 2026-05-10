/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:01:24 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/10 20:30:43 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//deb
void print_vec_stat(t_vec_three v, char *_string)
{
	printf("%s\t: (x, %lf), (y, %lf), (z, %lf)\n", _string, v.x, v.y, v.z);
}
void print_ray_stat(t_ray* r)
{
	print_vec_stat(r->p_origin, "origin");
	print_vec_stat(r->v_dir, "dir");
}
