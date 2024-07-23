/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_shoot_bullet_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:39:12 by brappo            #+#    #+#             */
/*   Updated: 2024/07/23 11:21:18 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"
#include "bullets_bonus.h"

#include <math.h>

bool	get_spawn_position(t_vector *result, t_entity *entity,
	t_vector *direction, t_game *game)
{
	float			radius;
	t_mlx_coords	tile_pos;

	radius = sqrt(entity->squared_radius) + 0.1f;
	result->x = entity->sprite->position.x + direction->x * radius;
	result->y = entity->sprite->position.y + direction->y * radius;
	tile_pos.x = result->x;
	tile_pos.y = result->y;
	return (is_walkable(&game->map, &tile_pos)
		&& !collide_entity(game->entities, result));
}

void	get_entity_direction(t_vector *result, t_vector *player_pos,
	t_vector *entity_pos)
{
	result->x = player_pos->x - entity_pos->x;
	result->y = player_pos->y - entity_pos->y;
	normalize_vector(result);
}

bool	entity_shoot_bullet(t_game *game, t_entity *entity,
	void (*bullet_init)(t_animation anim[MAP_NB_IDS], t_bullet *))
{
	t_vector	direction;
	t_vector	position;

	get_entity_direction(&direction, &game->player.position,
		&entity->sprite->position);
	if (!get_spawn_position(&position, entity, &direction, game))
		return (true);
	return (shoot_bullet(game, &position, &direction, bullet_init));
}
