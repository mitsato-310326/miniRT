/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/04 15:37:14 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int sky(char *data)
{
    double aspect_ratio = 16.0 / 9.0;
    int image_width = WIDTH;
    int image_height = (int)(image_width / aspect_ratio);
    int samples_per_pixel = 100;
    printf("P3\n%d %d\n255\n", image_width, image_height);
    t_camera cam = init_camera();

    t_hittable_list *world = NULL;
    t_sphere a;
    t_vec_three point3a = init_vec_three(0, 0, -1);
    a.origin = point3a;
    a.radius = 0.5;

    t_sphere b;
    t_vec_three point3b = init_vec_three(0, -100.5, -1);
    b.origin = point3b;
    b.radius = 100.0;

    ft_hlstadd_front(&world, ft_hlstnew(&a));
    ft_hlstadd_front(&world, ft_hlstnew(&b));

    for (int j = image_height-1; j >= 0; --j)
    {
        for (int i = 0; i < image_width; ++i)
        {
            t_vec_three pixel_color = init_vec_three(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                double u = (i + random_double()) / (image_width-1);
                double v = (j + random_double()) / (image_height-1);
                t_ray r = get_ray(u, v, cam);
                pixel_color = vec_three_add(pixel_color, ray_color(&r, &world));
            }
            double scale = 1.0 / samples_per_pixel;
            double ir = pixel_color.x;
            double ig = pixel_color.y;
            double ib = pixel_color.z;

            ir *= scale;
            ig *= scale;
            ib *= scale;

            int r = (256 * clamp(ir, 0.0, 0.999));
            int g = (256 * clamp(ig, 0.0, 0.999));
            int b = (256 * clamp(ib, 0.0, 0.999));

		    my_pixel_put(data, i, j, (r * 256 * 256) + (g * 256) + b);
        }
    }
    perror("\nDone.\n");
    return 1;
}
