/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 21:12:56 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/18 21:34:27 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//返り値が関数 hit_operator

bool list_hit(t_ray* r, double t_min, double t_max, t_hit_record* rec, t_hittable_list* list)
{
  t_hit_record temp_rec;
  bool hit_anything = false;
  auto closest_so_far = t_max;

  while (list)
  {
    if (hit_operator(r, t_min, closest_so_far, &temp_rec, list->content)) // <-こいつの調整が必須（オブヘクトの種類によって変更）
	{
      hit_anything = true;
      closest_so_far = temp_rec.t;
      *rec = temp_rec;
    }
	list = list->next;
  }

//   for (const auto& object : objects) {
//     if (object->hit(r, t_min, closest_so_far, temp_rec)) {
//       hit_anything = true;
//       closest_so_far = temp_rec.t;
//       rec = temp_rec;
//     }
//   }

  return hit_anything;
}

t_hittable_list	*ft_lstnew(void *content)
{
	t_hittable_list	*new;

	new = malloc(sizeof(t_hittable_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void ft_lstadd_front(t_hittable_list **lst, t_hittable_list *new)
{
	if (!lst || !*lst)
	{
		PERROR
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void ft_lstclear(t_hittable_list **lst)
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
