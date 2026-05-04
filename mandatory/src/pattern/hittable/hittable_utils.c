/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 21:12:56 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/26 19:01:26 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//返り値が関数 hit_operator

typedef enum e_hittable_type
{
	SPHERE,
	PLANE,
	// ...
}	t_hittable_type;

typedef struct s_circle
{
	t_vec_three center;
	t_hittable_type type;
	double radius;
}			t_circle;

bool hit_operator(t_ray* r, double t_min, double t_max, t_hit_record *rec , void *hittable)
{
	if (((t_circle *)hittable)->type == SPHERE)// circleじゃなくていい
		return hit(r, t_min, t_max, rec , ((t_circle *)hittable)->center, ((t_circle *)hittable)->radius);
	return false;
}

bool list_hit(t_ray* r, double t_min, double t_max, t_hit_record* rec, t_hittable_list* top)
{
  t_hit_record temp_rec;
  bool hit_anything = false;
  double closest_so_far = t_max;
  t_hittable_list *tmp = top;

  while (tmp)
  {
    if (hit_operator(r, t_min, closest_so_far, &temp_rec, tmp->content)) // <-こいつの調整が必須（オブヘクトの種類によって変更）
	{
      hit_anything = true;
      closest_so_far = temp_rec.t;
      *rec = temp_rec;
    }
	tmp = tmp->next;
  }

//   for (auto& object : objects) {
//     if (object->hit(r, t_min, closest_so_far, temp_rec)) {
//       hit_anything = true;
//       closest_so_far = temp_rec.t;
//       rec = temp_rec;
//     }
//   }

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
	// if (!lst || !*lst)
	// {
	// 	PERROR
	// 	return ;
	// }
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
