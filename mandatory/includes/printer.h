/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:51:59 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/28 22:18:30 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

typedef struct s_mlxs	t_mlxs;
typedef struct s_vec_three	t_vec_three;

# include <math.h>

/*											*/

/*											*/

bool print(t_mlxs * mlxs);

void	my_pixel_put(char *data, int x, int y, double scale, t_vec_three *color);

/*											*/


/*					DEBUG					*/

/*											*/

#endif
