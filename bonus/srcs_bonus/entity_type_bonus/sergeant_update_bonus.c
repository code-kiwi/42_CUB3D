/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sergeant_update_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:50:44 by root              #+#    #+#             */
/*   Updated: 2024/07/23 12:13:35 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "sprite_bonus.h"
#include "entities_bonus.h"
#include "bullets_bonus.h"

static void	stop_walk_animation(t_sprite *sprite, t_animation anim[MAP_NB_IDS])
{
	if (sprite->animation == &anim[IDX_TXTR_SERGEANT_WALK])
		sprite->animate = false;
}

static bool	sergeant_range_attack(t_entity *entity, t_sprite *sprite,
	t_game *game)
{
	if (entity->cooldown > 0)
		return (true);
	sprite->next_animation = &game->anim[IDX_TXTR_SERGEANT_WALK];
	sprite->animation = &game->anim[IDX_TXTR_SERGEANT_ATTACK];
	entity->sprite->texture = entity->sprite->animation->textures;
	entity->cooldown = SERGEANT_ATTACK_PAUSE;
	return (entity_shoot_bullet(game, entity, imp_projectile_init));
}

bool	sergeant_update(t_game *game, t_entity *entity, float delta_time)
{
	float		distance;
	t_sprite	*sprite;

	if (entity->cooldown > 0)
		entity->cooldown -= delta_time;
	sprite = entity->sprite;
	distance = get_distance(&sprite->position, &game->player.position);
	sprite->animate = true;
	if (!entity->see_player)
	{
		update_entity_position(entity, delta_time, game->entities, &game->map);
		if (entity->path == NULL)
			stop_walk_animation(sprite, game->anim);
	}
	else
	{
		stop_walk_animation(sprite, game->anim);
		return (sergeant_range_attack(entity, sprite, game));
	}
	return (true);
}
