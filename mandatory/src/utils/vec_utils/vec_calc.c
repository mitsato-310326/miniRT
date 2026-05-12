/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:09:24 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/12 19:39:49 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_util.h"

t_vec_three init_vec_three(double x, double y, double z)
{
	t_vec_three new;

	new.x = x;
	new.y = y;
	new.z = z;
	return new;
}


t_vec_three vec_three_add(t_vec_three a, t_vec_three b)
{
	t_vec_three ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}

t_vec_three vec_three_neg(t_vec_three a, t_vec_three b)
{
	t_vec_three ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}

//dev: vec_three_mult( arg1 , 1 / t );
t_vec_three vec_three_mult(t_vec_three a, double t)
{
	t_vec_three ret;

	ret.x = a.x * t;
	ret.y = a.y * t;
	ret.z = a.z * t;
	return (ret);
}

t_vec_three vec_three_mult_v(t_vec_three a, t_vec_three b)
{
	t_vec_three ret;

	ret.x = a.x * b.x;
	ret.y = a.y * b.y;
	ret.z = a.z * b.z;
	return (ret);
}

double vec_three_squared(t_vec_three a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z *a.z));
}
