/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/11 15:07:14 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
// #include <iostream>

t_vec_three ray_color(t_ray *r)
{
    t_vec_three unit_direction = unit_vector(r->v_dir);
    
    t_vec_three color1;
    color1.x = 1.0;
    color1.y = 1.0;
    color1.z = 1.0;

    t_vec_three color2;
    color2.x = 0.5;
    color2.y = 0.7;
    color2.z = 1.0;

    double t = 0.5*(unit_direction.y + 1.0);
    // return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
    return (vec_three_add(vec_three_mult(color1, 1.0-t), vec_three_mult(color2, t)));
}

int main()
{
    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 384;
    const int image_height = (int)(image_width / aspect_ratio);

    printf("P3\n%d %d\n255\n", image_width, image_height);

    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    t_vec_three origin;// = vec_three_create(origin_x, origin_y, origin_z);
    origin.x = 0;
    origin.y = 0;
    origin.z = 0;
    t_vec_three horizontal;// = vec_three_create(horizontal_x, horizontal_y, horizontal_z);
    horizontal.x = viewport_width;
    horizontal.y = 0;
    horizontal.z = 0;
    t_vec_three vertical;// = vec_three_create(vertical_x, vertical_y, vertical_z);
    vertical.x = 0;
    vertical.y = viewport_height;
    vertical.z = 0;

    t_vec_three focal_vec;
    focal_vec.x = 0;
    focal_vec.y = 0;
    focal_vec.z = focal_length;
    t_vec_three lower_left_corner = vec_three_neg(vec_three_neg(vec_three_neg(origin, vec_three_mult(horizontal, 0.5)), vec_three_mult(vertical, 0.5)), vec_three_mult(focal_vec, 1.0));

    for (int j = image_height-1; j >= 0; --j)
    {
        perror("\rScanlines remaining: %d \n");
        for (int i = 0; i < image_width; ++i)
        {
            double u = (double)(i) / (image_width-1);
            double v = (double)(j) / (image_height-1);
            t_ray r;
            r.p_origin = origin;
            r.v_dir = vec_three_add(vec_three_add(lower_left_corner, vec_three_mult(horizontal, u)), vec_three_neg(vec_three_mult(vertical, v), origin));
            t_vec_three pixel_color = ray_color(&r);
            (void)pixel_color;
        }
    }
    perror("\nDone.\n");
}
