/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:18:49 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/11 14:43:58 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void return_with_string(char *errstr, bool systemerr)
{
	if (systemerr)
		perror(NULL);
	else
		ft_putstr_fd(errstr, 2);
}

#define INIT_MLX_ERR "error"
#define TITLE "error"

t_mlxs	*init(void)
{
	t_mlxs *tmp;

	tmp = malloc(sizeof(t_mlxs));
	if (tmp == NULL)
		return_with_string(NULL, 1);
	while(true)
	{
		tmp->mlx = mlx_init();
		if (tmp->mlx == NULL)
			break;
		tmp->win = mlx_new_window(tmp->mlx, WIDTH, HEIGHT, TITLE);
		if (tmp->win == NULL)
			break;
		tmp->img = mlx_new_image(tmp->mlx, WIDTH, HEIGHT);
		if (tmp->img == NULL)
			break;
		tmp->data = mlx_get_data_addr(tmp->img, &(int){0}, &(int){0}, &(int){0});
		if (tmp->data == NULL)
			break;
		return tmp;
	}
	destroy_minirt(tmp);
	return_with_string(INIT_MLX_ERR, 0);
	return NULL;
}
