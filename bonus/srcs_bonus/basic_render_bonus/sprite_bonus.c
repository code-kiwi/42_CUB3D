/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:22:06 by root              #+#    #+#             */
/*   Updated: 2024/06/20 16:36:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

int	compare_sprite_distance(void **a, void **b)
{
	return (((t_sprite *)a)->distance - ((t_sprite *)b)->distance); 
}

size_t	count_sprites(t_map *map)
{
	size_t	y;
	size_t	x;
	size_t	sprites_count;

	y = 0;
	sprites_count = 0;
	while (y < map->lines_count)
	{
		x= 0 ;
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

t_sprite	*get_sprites(t_map *map, size_t sprites_count)
{
	size_t		y;
	size_t		x;
	t_sprite	*sprites;
	size_t		sprite_index;

	sprites = ft_calloc(sprites_count, sizeof(t_sprite));
	if (sprites == NULL)
		return (NULL);
	y = 0;
	sprite_index = 0;
	while (y < map->lines_count)
	{
		x= 0 ;
		while (x < map->lines_lengths[y])
		{
			if (map->tiles[y][x] == ID_SPRITE)
			{
				sprites[sprites_count].position = (t_vector){x + 0.5, y + 0.5};
				sprite_index++;
			}
			x++;
		}
		y++;
	}
	return (sprites);
}

void	get_sprites_distances(t_sprite *sprites, t_vector *pos, size_t length)
{
	size_t	index;

	index = 0;
	while (index < length)
	{
		sprites[index].distance = get_distance(&sprites[index].position, pos);
		index++;
	}
}