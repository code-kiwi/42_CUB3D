/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:22:06 by root              #+#    #+#             */
/*   Updated: 2024/06/20 21:15:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

size_t	count_sprites(t_map *map)
{
	size_t	y;
	size_t	x;
	size_t	sprites_count;

	y = 0;
	sprites_count = 0;
	while (y < map->lines_count)
	{
		x = 0 ;
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == ID_SPRITE)
				sprites_count++;
			x++;
		}
		y++;
	}
	return (sprites_count);
}

void	get_sprites(t_map *map, size_t sprites_count, t_sprite **sprites)
{
	size_t		y;
	size_t		x;
	size_t		sprite_index;

	y = 0;
	sprite_index = 0;
	while (y < map->lines_count)
	{
		x = 0 ;
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == ID_SPRITE)
			{
				sprites[sprite_index]->position = (t_vector){x + 0.5, y + 0.5};
				sprite_index++;
				if (sprite_index == sprites_count)
					return ;
			}
			x++;
		}
		y++;
	}
}

t_sprite	**alloc_sprites(size_t sprites_count)
{
	t_sprite	**sprites;
	size_t		index;

	sprites = ft_calloc(sprites_count, sizeof(t_sprite *));
	if (sprites == NULL)
		return (NULL);
	index = 0;
	while (index < sprites_count)
	{
		sprites[index] = ft_calloc(1, sizeof(t_sprite));
		if (sprites[index] == NULL)
		{
			while (index - 1 > 0)
			{
				free(sprites[index - 1]);
				index--;
			}
			free(sprites);
			return (NULL);
		}
		index++;
	}
	return (sprites);
}

void	get_sprites_distances(t_sprite **sprites, t_vector *pos, size_t length)
{
	size_t	index;

	index = 0;
	while (index < length)
	{
		sprites[index]->distance = get_distance(&sprites[index]->position, pos);
		index++;
	}
}
