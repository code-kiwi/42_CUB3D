/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:04:48 by brappo            #+#    #+#             */
/*   Updated: 2024/06/20 13:28:08 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

t_sprite	*get_sprites(t_map *map, size_t x, size_t y, size_t sprite_count)
{
	t_sprite	*sprites;

	while (y < map->lines_count)
	{
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == ID_SPRITE)
			{
				sprites = get_sprites(map, x + 1, y, sprite_count + 1);			
				if (sprites == NULL)
					return (NULL);	
				sprites[sprite_count].position = (t_vector){x + 0.5f, y + 0.5f};
				return (sprites);
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (sprite_count == 0)
		return (NULL);
	return (ft_calloc(sprite_count, sizeof(t_sprite)));
}