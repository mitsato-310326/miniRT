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

t_hittable_list *init_obj()
{
    t_hittable_list *world = NULL;

    t_hittable *a_u = malloc(sizeof(t_hittable));
    t_sphere *a = malloc(sizeof(t_sphere));
    t_vec_three point3a = init_vec_three(0, 0, -1);
    a->origin = point3a;
    a->radius = 0.5;
    a_u->hit_fn = &hit_sphere;
    t_material *a_m = malloc(sizeof(t_material));
    a_m->albedo = init_vec_three(0.7, 0.3, 0.3);
    // a_m->type = LAMBERTIAN;
    a_m->scatter_fn = &scatter;
    a_u->material = a_m;
    a_u->object_unique_info = a;

    t_hittable *b_u = malloc(sizeof(t_hittable));
    t_sphere *b = malloc(sizeof(t_sphere));
    t_vec_three point3b = init_vec_three(0, -100.5, -1);
    b->origin = point3b;
    b->radius = 100.0;
    b_u->hit_fn = &hit_sphere;
    t_material *b_m = malloc(sizeof(t_material));
    b_m->albedo = init_vec_three(0.8, 0.8, 0.0);
    b_m->scatter_fn = &scatter;
    b_u->material = b_m;
    b_u->object_unique_info = b;

    t_hittable *c_u = malloc(sizeof(t_hittable));
    t_sphere *c = malloc(sizeof(t_sphere));
    t_vec_three point3c = init_vec_three(1.0 ,0 ,-1.0);
    c->origin = point3c;
    c->radius = 0.5;
    c_u->hit_fn = &hit_sphere;
    t_material *c_m = malloc(sizeof(t_material));
    c_m->albedo = init_vec_three(0.8, 0.6, 0.2);
    c_m->scatter_fn = &scatter_metal;
    c_u->material = c_m;
    c_u->object_unique_info = c;

    t_hittable *d_u = malloc(sizeof(t_hittable));
    t_sphere *d = malloc(sizeof(t_sphere));
    t_vec_three point3d = init_vec_three(-1,0,-1);
    d->origin = point3d;
    d->radius = 0.5;
    d_u->hit_fn = &hit_sphere;
    t_material *d_m = malloc(sizeof(t_material));
    d_m->albedo = init_vec_three(0.8, 0.8, 0.8);
    d_m->scatter_fn = &scatter_metal;
    d_u->material = d_m;
    d_u->object_unique_info = d;

    ft_hlstadd_front(&world, ft_hlstnew(a_u));
    ft_hlstadd_front(&world, ft_hlstnew(b_u));
    ft_hlstadd_front(&world, ft_hlstnew(c_u));
    ft_hlstadd_front(&world, ft_hlstnew(d_u));
    return world;
}

int view_calc(t_mlxs *mlxs)
{
    char *data = mlxs->data;
    t_camera *cam = mlxs->cam;
    ENTRY("view_calc");
    double aspect_ratio = 16.0 / 9.0;
    int image_width = WIDTH;
    int image_height = (int)(image_width / aspect_ratio);
    int samples_per_pixel = 100;

    t_hittable_list *world = init_obj();

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
            double ir = pixel_color.x;
            double ig = pixel_color.y;
            double ib = pixel_color.z;

            double scale = 1.0 / samples_per_pixel;
            ir = sqrt(scale * ir);
            ig = sqrt(scale * ig);
            ib = sqrt(scale * ib);

            int r = (256 * clamp(ir, 0.0, 0.999));
            int g = (256 * clamp(ig, 0.0, 0.999));
            int b = (256 * clamp(ib, 0.0, 0.999));

		    my_pixel_put(data, i, j, (r * 256 * 256) + (g * 256) + b);
        }
    }
    return 1;
}
