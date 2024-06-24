/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:56:04 by brappo            #+#    #+#             */
/*   Updated: 2024/06/24 10:39:25 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d_bonus.h"
#include "sprite_bonus.h"

static t_list	*max(t_list *lst, int compare(void *, void *))
{
	t_list	*max_element;

	max_element = lst;
	while (lst)
	{
		if (compare(max_element->content, lst->content) > 0)
			max_element = lst;
		lst = lst->next;
	}
	return (max_element);
}

static void	swap(void **a, void **b)
{
	void	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_list(t_list *lst, int compare(void *, void *))
{
	t_list	*max_element;

	while (lst)
	{
		max_element = max(lst, compare);
		swap(lst->content, max_element->content);
		lst = lst->next;
	}
}
