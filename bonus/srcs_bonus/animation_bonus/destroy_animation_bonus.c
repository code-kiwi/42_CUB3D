/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_animation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:32:35 by brappo            #+#    #+#             */
/*   Updated: 2024/06/25 12:24:37 by codekiwi         ###   ########.fr       */
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
		t_image_destroy(mlx_ptr, (t_image *)current->content, true);
		previous = current;
		current = current->next;
		free(previous);
	}
}
