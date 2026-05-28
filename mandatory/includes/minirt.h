/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:32:16 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/28 22:23:42 by mitsato          ###   ########.fr       */
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
#include "./hook.h"
#include "./printer.h"
#include "./ray_util.h"
#include "./vec_util.h"
#include "./math_util.h"

//debug includes
#include "../../ft_mlx.h"
#include "../../os_setting.h"
#include "./pattern.h"
#include "./hittable.h"
#include "./hittable_list.h"
#include "./sphere.h"
#include "./camera.h"
#include "./ft_weekend.h"
#include "./lambertian.h"

#define WIDTH 640
#define HEIGHT 360

/*											*/

typedef struct s_mlxs
{
	char *mlx;
	char *win;
	char *img;
	char *data;

	t_hittable_list *hittable_list;
	t_camera *cam;
}						t_mlxs;

void put_error(char *errstr, bool systemerr);
t_mlxs *init(char *map);
int destroy_minirt(t_mlxs *mlxs);

/*											*/


/*					DEBUG					*/

#define BLUE   "\033[34m"
#define GREEN   "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

#define PERROR printf(RED "ERROR" RESET "\n");
#define PSUCCESS printf(GREEN "SUCCESS" RESET "\n");
#define ENTRY(str) do { \
    static int i = 0; \
    if (i++ == 0) { \
        printf(BLUE "GET IN %s FUNCTION" RESET "\n", (str)); \
    } \
} while(0)

/*											*/

#endif
