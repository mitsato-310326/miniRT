/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:32:16 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/18 18:50:08 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_UTIL_H
# define VEC_UTIL_H

# include <math.h>

/*											*/

typedef struct s_vec_three
{
	double	x;
	double	y;
	double	z;
}			t_vec_three;

typedef struct s_point3
{
	double	x;
	double	y;
	double	z;
}			t_point3;

typedef struct s_color
{
	double	x;
	double	y;
	double	z;
}			t_color;

/*					UTILS					*/

t_vec_three	vec_three_add(t_vec_three a, t_vec_three b);
t_vec_three	vec_three_neg(t_vec_three a, t_vec_three b);
t_vec_three	vec_three_mult(t_vec_three a, double t);
double		vec_three_squared(t_vec_three a);

double		dot(t_vec_three a, t_vec_three b);
t_vec_three unit_vector(t_vec_three v);

/*					DEBUG					*/

/*											*/

#endif
