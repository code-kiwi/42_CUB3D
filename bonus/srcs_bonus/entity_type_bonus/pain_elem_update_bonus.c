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

static void	stop_walk_animation(t_sprite *sprite, t_animation anim[MAP_NB_IDS])
{
	if (sprite->animation == &anim[IDX_TXTR_PAIN_ELEM_WALK])
		sprite->animate = false;
}

static void	pain_elem_close_attack(t_entity *entity, t_sprite *sprite, t_game *game)
{
	if (entity->cooldown > 0)
		return ;
	sprite->next_animation = &game->anim[IDX_TXTR_PAIN_ELEM_WALK];
	sprite->animation = &game->anim[IDX_TXTR_PAIN_ELEM_ATTACK];
	entity->cooldown = PAIN_ELEM_ATTACK_PAUSE;
	player_get_damage(game, PAIN_ELEM_ATTACK_DAMAGE);
}

static bool	pain_elem_spawn(t_entity *entity, t_sprite *sprite, t_game *game)
{
	t_vector	position;
	t_vector	direction;
	t_entity	*new_lost_soul;

	if (entity->cooldown > 0)
		return (true);
	entity->cooldown = PAIN_ELEM_SPAWN_PAUSE;
	get_entity_direction(&direction, &game->player.position, &sprite->position);
	if (!get_spawn_position(&position, entity, &direction, game))
		return (true);
	new_lost_soul = add_entity(game, 0, 0, ID_MAP_LOST_SOUL);
	if (!new_lost_soul)
		return (false);
	new_lost_soul->sprite->position.x = position.x;
	new_lost_soul->sprite->position.y = position.y;
	sprite->animation = &game->anim[IDX_TXTR_PAIN_ELEM_ATTACK];
	sprite->next_animation = &game->anim[IDX_TXTR_PAIN_ELEM_WALK];
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
	{
		stop_walk_animation(sprite, game->anim);
		pain_elem_close_attack(entity, sprite, game);
	}
	else if (!entity->see_player)
		update_entity_position(entity, delta_time, game->entities, &game->map);
	else
	{
		stop_walk_animation(sprite, game->anim);
		return (pain_elem_spawn(entity, sprite, game));
	}
	return (true);
}
