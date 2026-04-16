/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:09:24 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/16 22:02:59 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_util.h"

double dot(t_vec_three a, t_vec_three b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec_three unit_vector(t_vec_three v)
{
  return (vec_three_mult(v, (double)1 / vec_three_squared(v)));
}
