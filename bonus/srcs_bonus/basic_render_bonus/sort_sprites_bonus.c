/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:56:04 by brappo            #+#    #+#             */
/*   Updated: 2024/06/21 15:30:43 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d_bonus.h"
#include "sprite_bonus.h"

static t_sprite	**max_sprites(t_sprite **sprites, size_t length)
{
	t_sprite	**max_element;
	size_t		index;

	if (sprites == NULL)
		return (NULL);
	index = 1;
	max_element = sprites;
	while (index < length)
	{
		if (sprites[index]->distance - (*max_element)->distance > 0)
			max_element = sprites + index;
		index++;
	}
	return (max_element);
}

static void	swap_sprites(t_sprite **a, t_sprite **b)
{
	t_sprite	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_sprites(t_sprite **sprites, size_t length)
{
	size_t		index;
	t_sprite	**max_element;

	index = 0;
	while (length > 0)
	{
		max_element = max_sprites(sprites + index, length);
		swap_sprites(sprites + index, max_element);
		length--;
		index++;
	}
}
