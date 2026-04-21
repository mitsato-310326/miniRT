/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:18:54 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/16 21:12:43 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

/*											*/

typedef struct s_vec_three t_vec_three;
typedef struct s_hittable_list t_hittable_list;

/*					UTILS					*/

int sky(char *data);
t_vec_three ray_color(t_ray* r, t_hittable_list **world);

/*					DEBUG					*/

/*											*/

#endif
