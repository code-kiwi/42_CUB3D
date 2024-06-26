/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:22:06 by root              #+#    #+#             */
/*   Updated: 2024/06/24 15:10:35 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "sprite_bonus.h"
#include "libft.h"

static bool	add_sprite(t_list **sprites, float x, float y)
{
	t_list		*new_node;
	t_sprite	*new_sprite;

	new_sprite = ft_calloc(1, sizeof(t_sprite));
	if (new_sprite == NULL)
		return (false);
	new_sprite->position.x = x;
	new_sprite->position.y = y;
	new_node = ft_lstnew(new_sprite);
	if (new_node == NULL)
	{
		free(new_sprite);
		return (false);
	}
	ft_lstadd_front(sprites, new_node);
	return (true);
}

bool	get_sprites(t_map *map, t_list **sprites)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < map->lines_count)
	{
		x = 0 ;
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == ID_SPRITE)
			{
				if (!add_sprite(sprites, x + 0.5, y + 0.5))
				{
					ft_lstclear(sprites, free);
					return (false);
				}
			}
			x++;
		}
		y++;
	}
	return (true);
}
