/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_distance_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:42:11 by brappo            #+#    #+#             */
/*   Updated: 2024/06/24 11:14:38 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sprite_bonus.h"

void	get_sprites_distances(t_list *sprites, t_vector *pos)
{
	t_sprite	*sprite;

	while (sprites)
	{
		sprite = sprites->content;
		sprite->distance = get_distance(&sprite->position, pos);
		sprites = sprites->next;
	}
}

int	compare_sprite_distance(void *a, void *b)
{
	return (((t_sprite *)a)->distance - ((t_sprite *)b)->distance);
}
