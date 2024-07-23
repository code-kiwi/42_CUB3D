/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arch_vile_update_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:49:15 by root              #+#    #+#             */
/*   Updated: 2024/07/23 13:19:40 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"
#include "bullets_bonus.h"

static void	stop_walk_animation(t_sprite *sprite, t_animation anim[MAP_NB_IDS])
{
	if (sprite->animation == &anim[IDX_TXTR_ARCH_VILE_WALK])
		sprite->animate = false;
}

static void	arch_vile_close_attack(t_entity *entity, t_sprite *sprite, \
	t_game *game)
{
	if (entity->cooldown > 0)
		return ;
	set_animation(entity->sprite, &game->anim[IDX_TXTR_ARCH_VILE_ATTACK]);
	sprite->next_animation = &game->anim[IDX_TXTR_ARCH_VILE_WALK];
	entity->cooldown = ARCH_VILE_ATTACK_PAUSE;
	player_get_damage(game, ARCH_VILE_ATTACK_DAMAGE);
}

static bool	arch_vile_spawn(t_entity *entity, t_sprite *sprite, t_game *game)
{
	t_vector	position;
	t_vector	direction;
	t_entity	*new_lost_soul;

	if (entity->cooldown > 0)
		return (true);
	entity->cooldown = ARCH_VILE_SPAWN_PAUSE;
	get_entity_direction(&direction, &game->player.position, &sprite->position);
	if (!get_spawn_position(&position, entity, &direction, game))
		return (true);
	new_lost_soul = add_entity(game, 0, 0, ID_MAP_LOST_SOUL);
	if (!new_lost_soul)
		return (false);
	new_lost_soul->sprite->position.x = position.x;
	new_lost_soul->sprite->position.y = position.y;
	set_animation(entity->sprite, &game->anim[IDX_TXTR_ARCH_VILE_ATTACK]);
	sprite->next_animation = &game->anim[IDX_TXTR_ARCH_VILE_WALK];
	return (true);
}

bool	arch_vile_update(t_game *game, t_entity *entity, float delta_time)
{
	float		distance;
	t_sprite	*sprite;

	if (entity->cooldown > 0)
		entity->cooldown -= delta_time;
	sprite = entity->sprite;
	distance = get_distance(&sprite->position, &game->player.position);
	sprite->animate = true;
	if (distance < ARCH_VILE_ATTACK_RANGE)
	{
		stop_walk_animation(sprite, game->anim);
		arch_vile_close_attack(entity, sprite, game);
	}
	else if (!entity->see_player)
		update_entity_position(entity, delta_time, game->entities, &game->map);
	else
	{
		stop_walk_animation(sprite, game->anim);
		return (arch_vile_spawn(entity, sprite, game));
	}
	return (true);
}
