/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:09:24 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/05 17:07:40 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_util.h"
#include "ft_weekend.h"

double dot(t_vec_three a, t_vec_three b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec_three unit_vector(t_vec_three v)
{
  return (vec_three_mult(v, (double)1 / vec_three_squared(v)));
}

t_vec_three random_in_unit_sphere()
{
	while (1) {
		t_vec_three p = init_vec_three(random_double_with(-1, 1), random_double_with(-1, 1), random_double_with(-1, 1));
		if (vec_three_squared(p) >= 1) continue;
		return p;
	}
}

