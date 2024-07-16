/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:31:34 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/16 14:45:30 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "entities_bonus.h"
#include "door_bonus.h"
#include "libft.h"

static void	clear_map(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->lines_count)
	{
		j = 0;
		while (j < map->lines_lengths[i])
		{
			if (ft_strchr(MAP_MOVING_CHARS, map->tiles[i][j]) != NULL)
				map->tiles[i][j] = ID_MAP_TILE;
			j++;
		}
		i++;
	}
}

static void	add_player_to_map(t_map *map, t_player *player)
{
	t_mlx_coords	player_coords;

	if (!is_in_bounds(&player->position, map))
		return ;
	player_coords.x = (int) player->position.x;
	player_coords.y = (int) player->position.y;
	map->tiles[player_coords.y][player_coords.x] = ID_MAP_PLAYER;
}

static void	add_entities_to_map(t_map *map, t_list *entities)
{
	t_entity		*entity;
	t_mlx_coords	entity_coords;

	while (entities != NULL)
	{
		entity = (t_entity *) entities->content;
		if (entity != NULL)
		{
			entity_coords.x = (int) entity->sprite->position.x;
			entity_coords.y = (int) entity->sprite->position.y;
			map->tiles[entity_coords.y][entity_coords.x] = ID_MAP_ENTITY;
		}
		entities = entities->next;
	}
}

static void	add_doors_to_map(t_map *map, t_door *doors, size_t door_count)
{
	size_t			i;
	t_mlx_coords	*door_coords;

	i = 0;
	while (i < door_count)
	{
		door_coords = &doors[i].position;
		if (doors[i].state == OPENED)
			map->tiles[door_coords->y][door_coords->x] = ID_MAP_DOOR_OPENED;
		else
			map->tiles[door_coords->y][door_coords->x] = ID_MAP_DOOR_CLOSED;
		i++;
	}
}

void	update_map(t_map *map, t_game *game)
{
	if (map == NULL || game == NULL)
		return ;
	clear_map(map);
	add_doors_to_map(map, game->doors, game->door_count);
	add_player_to_map(map, &game->player);
	add_entities_to_map(map, game->entities);
}
