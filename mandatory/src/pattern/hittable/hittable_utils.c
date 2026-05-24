/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 21:12:56 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/24 12:34:21 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//返り値が関数 hit_operator

bool hit_operator(t_ray* r, double t_min, double t_max, t_hit_record *rec , void *hittable)
{
	ENTRY("hit_operator");
	if (((t_sphere *)hittable)->type == SPHERE)// circleじゃなくていい
	{
		return hit_sphere(t_min, t_max, ((t_sphere *)hittable), r, rec);
	}
	return false;
}

bool list_hit(t_ray* r, double t_min, double t_max, t_hit_record* rec, t_hittable_list* top)
{
	ENTRY("list_hit");
	t_hit_record temp_rec;
	bool hit_anything = false;
	double closest_so_far = t_max;
	t_hittable_list *tmp = top;

	while (tmp)
	{
		if (hit_operator(r, t_min, closest_so_far, &temp_rec, tmp->content))
		{
			hit_anything = true;
			closest_so_far = temp_rec.t;
			*rec = temp_rec;
		}
		tmp = tmp->next;
	}
	return hit_anything;
}

t_hittable_list	*ft_hlstnew(void *content)
{
	t_hittable_list	*new;

	new = malloc(sizeof(t_hittable_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void ft_hlstadd_front(t_hittable_list **lst, t_hittable_list *new)
{
	ENTRY("ft_hlstadd_front");
	new->next = *lst;
	*lst = new;
}

void ft_hlstclear(t_hittable_list **lst)
{
	t_hittable_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
