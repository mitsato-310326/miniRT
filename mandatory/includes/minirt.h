/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:32:16 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/12 15:08:54 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../mlx/mlx.h"
#include "../../libft/libft.h"
#include "./printer.h"
#include "./hook.h"
#include "./vec_util.h"

#define WIDTH 320
#define HEIGHT 180

/*											*/

typedef struct s_mlxs
{
	char *mlx;
	char *win;
	char *img;
	char *data;
}						t_mlxs;

t_mlxs *init();

/*											*/


/*					DEBUG					*/

#define RED   "\033[31m"
#define RESET "\033[0m"

#define PERROR printf(RED "ERROR" RESET "\n");

/*											*/

#endif
