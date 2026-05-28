/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:18:49 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/28 22:03:03 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void put_error(char *errstr, bool systemerr)
{
	if (systemerr)
		perror(NULL);
	else
		ft_putstr_fd(errstr, 2);
}

#define INIT_MLX_ERR "error"
#define TITLE "error"

bool setup_mlx(t_mlxs *mlxs)
{
	mlxs->mlx = mlx_init();
	if (mlxs->mlx == NULL)
		return false;
	mlxs->win = mlx_new_window(mlxs->mlx, WIDTH, HEIGHT, TITLE);
	if (mlxs->win == NULL)
		return false;
	mlxs->img = mlx_new_image(mlxs->mlx, WIDTH, HEIGHT);
	if (mlxs->img == NULL)
		return false;
	mlxs->data = mlx_get_data_addr(mlxs->img, &(int){0}, &(int){0}, &(int){0}); //多分複合リテラル
	if (mlxs->data == NULL)
		return false;
	mlx_hook(mlxs->win, 17, 0, stop_minirt, mlxs);
	mlx_key_hook(mlxs->win, key_handler, mlxs);
	return true;
}

t_camera *init_camera() //カメラオブジェクトは別物だしここでべついいかも
{
    ENTRY("init_camera");

	t_camera *new = malloc(sizeof(t_camera));
    if (!new)
        return NULL;
    double aspect_ratio = 16.0 / 9.0;
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    new->origin = init_vec_three(0, 0, 0);
    new->horizontal = init_vec_three(viewport_width, 0.0, 0.0);
    new->vertical = init_vec_three(0.0, viewport_height, 0.0);
    new->lower_left_corner = vec_three_neg(vec_three_neg(vec_three_neg(new->origin, vec_three_mult(new->horizontal, 0.5)), vec_three_mult(new->vertical, 0.5)), init_vec_three(0, 0, focal_length));
    return new;
}

t_hittable_list *init_obj();

t_hittable_list *init_hittable(char *map)
{
	(void)map;
	//parse();
	t_hittable_list *hittable_list = init_obj();
	if (hittable_list == NULL)
		return NULL;
	return hittable_list;

}

t_mlxs	*init(char *map)
{
	t_mlxs *mlxs;
	mlxs = malloc(sizeof(t_mlxs));
	if (mlxs == NULL)
	{
		put_error(NULL, 1); // malloc失敗
		return NULL;
	}
	mlxs->hittable_list = init_hittable(map);
	if (mlxs->hittable_list == NULL)
	{
		; // 未実装
	}
	if (setup_mlx(mlxs) == false)
	{
		put_error(INIT_MLX_ERR, 0);
		destroy_minirt(mlxs);
		return NULL;
	}
	mlxs->cam = init_camera();
	if (mlxs->cam == NULL)
	{
		; // 未実装
	}
	return mlxs;
}

// ------------ 一時的クソコード ------------ //

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
