/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_calc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/04 15:37:14 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int view_calc(t_mlxs *mlxs)
{
    char *data = mlxs->data;
    t_camera *cam = mlxs->cam;
    ENTRY("view_calc");
    double aspect_ratio = (double)WIDTH / HEIGHT;
    int image_width = WIDTH;
    int image_height = (int)(image_width / aspect_ratio);
    int samples_per_pixel = 100;
    double scale = 1.0 / samples_per_pixel;

    t_hittable_list *world = mlxs->hittable_list;

    for (int j = image_height-1; j >= 0; --j)
    {
        for (int i = 0; i < image_width; ++i)
        {
            t_vec_three pixel_color = init_vec_three(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                double u = (i + random_double()) / (image_width-1);
                double v = (j + random_double()) / (image_height-1);
                t_ray r = get_ray(u, v, *cam);
                pixel_color = vec_three_add(pixel_color, ray_color(&r, world, 3));
            }
            // double ir = pixel_color.x;
            // double ig = pixel_color.y;
            // double ib = pixel_color.z;

            // ir = sqrt(scale * ir);
            // ig = sqrt(scale * ig);
            // ib = sqrt(scale * ib);

            // int r = (256 * clamp(ir, 0.0, 0.999));
            // int g = (256 * clamp(ig, 0.0, 0.999));
            // int b = (256 * clamp(ib, 0.0, 0.999));

		    // // my_pixel_put(data, i, j, (r * 256 * 256) + (g * 256) + b);
            my_pixel_put(data, i, j, scale, &pixel_color);
        }
    }
    return 1;
}
