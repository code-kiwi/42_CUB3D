/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_animation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:32:35 by brappo            #+#    #+#             */
/*   Updated: 2024/07/22 22:23:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx_api_bonus.h"
#include "animation_bonus.h"

void	destroy_animation(t_animation *anim, void *mlx_ptr)
{
	t_list	*current;
	t_list	*previous;

	current = anim->textures;
	while (current)
	{
		t_image_destroy(mlx_ptr, (t_image *)current->content, true);
		previous = current;
		current = current->next;
		free(previous);
	}
}
