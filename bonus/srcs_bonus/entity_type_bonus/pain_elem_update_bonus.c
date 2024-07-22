/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pain_elem_update_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:49:15 by root              #+#    #+#             */
/*   Updated: 2024/07/19 17:14:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"
#include "bullets_bonus.h"

static void	pain_elem_close_attack(t_entity *entity, t_sprite *sprite, t_game *game)
{
	if (entity->cooldown > 0)
		return ;
	sprite->next_animation = game->textures[IDX_TXTR_PAIN_ELEM_WALK];
	sprite->animation = game->textures[IDX_TXTR_PAIN_ELEM_ATTACK];
	entity->cooldown = PAIN_ELEM_ATTACK_PAUSE;
	player_get_damage(game, PAIN_ELEM_ATTACK_DAMAGE);
}

static bool	pain_elem_spawn(t_entity *entity, t_sprite *sprite, t_game *game)
{
	t_vector	direction;
	t_vector	position;
	float		radius;

	if (entity->cooldown > 0)
		return (true);
	direction.x = game->player.position.x - entity->sprite->position.x;
	direction.y = game->player.position.y - entity->sprite->position.y;
	normalize_vector(&direction);
	radius = sqrt(entity->squared_radius) + 0.1f;
	position.x = entity->sprite->position.x + direction.x * radius;
	position.y = entity->sprite->position.y + direction.y * radius;
	sprite->next_animation = game->textures[IDX_TXTR_PAIN_ELEM_WALK];
	sprite->animation = game->textures[IDX_TXTR_PAIN_ELEM_ATTACK];
	if (!is_walkable(&game->map, )
		|| collide_entity(game->entities, &position))
	entity->cooldown = PAIN_ELEM_SPAW_PAUSE;
	if (!add_entity(game, position.x, position.y, ID_MAP_LOST_SOUL))
		return (false);
	return (true);
}

bool	pain_elem_update(t_game *game, t_entity *entity, float delta_time)
{
	float		distance;
	t_sprite	*sprite;

	if (entity->cooldown > 0)
		entity->cooldown -= delta_time;
	sprite = entity->sprite;
	distance = get_distance(&sprite->position, &game->player.position);
	sprite->animate = true;
	if (distance < PAIN_ELEM_ATTACK_RANGE)
		pain_elem_close_attack(entity, sprite, game);
	else if (!entity->see_player)
		update_entity_position(entity, delta_time, game->entities, &game->map);
	else
		return (pain_elem_spawn(entity, sprite, game));
	return (true);
}
