/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_animation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:32:35 by brappo            #+#    #+#             */
/*   Updated: 2024/06/24 14:22:28 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx_api_bonus.h"

void	destroy_animation(t_list *anim, void *mlx_ptr, bool is_circular)
{
	t_list	*current;
	t_list	*previous;

	if (is_circular && anim != NULL)
	{
		current = anim->next;
		anim->next = NULL;
	}
	else
		current = anim;
	while (current)
	{
		t_image_destroy(mlx_ptr, (t_image *)current->content);
		previous = current;
		current = current->next;
		free(previous);
	}
}
