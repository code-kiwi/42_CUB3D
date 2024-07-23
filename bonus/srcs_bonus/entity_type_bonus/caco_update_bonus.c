/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caco_update_bonus.c                               :+:      :+:    :+:   */
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

static void	caco_close_attack(t_entity *entity, t_sprite *sprite, t_game *game)
{
	if (entity->cooldown > 0)
		return ;
	sprite->next_animation = &game->anim[IDX_TXTR_CACO_WALK];
	sprite->animation = &game->anim[IDX_TXTR_CACO_ATTACK];
	entity->sprite->texture = entity->sprite->animation->textures;
	entity->cooldown = CACO_CLOSE_ATTACK_PAUSE;
	player_get_damage(game, CACO_CLOSE_ATTACK_DAMAGE);
}

static bool	caco_range_attack(t_entity *entity, t_sprite *sprite, t_game *game)
{
	if (entity->cooldown > 0)
		return (true);
	sprite->next_animation = &game->anim[IDX_TXTR_CACO_WALK];
	sprite->animation = &game->anim[IDX_TXTR_CACO_ATTACK];
	entity->sprite->texture = entity->sprite->animation->textures;
	entity->cooldown = CACO_RANGE_ATTACK_PAUSE;
	return (entity_shoot_bullet(game, entity, caco_projectile_init));
}

bool	caco_update(t_game *game, t_entity *entity, float delta_time)
{
	t_player	*player;
	float		distance;
	t_sprite	*sprite;

	if (entity->cooldown > 0)
		entity->cooldown -= delta_time;
	sprite = entity->sprite;
	player = &game->player;
	distance = get_distance(&sprite->position, &player->position);
	sprite->animate = true;
	if (distance < CACO_CLOSE_ATTACK_RANGE)
	{
		caco_close_attack(entity, sprite, game);
	}
	else
	{
		if (!caco_range_attack(entity, sprite, game))
			return (false);
		update_entity_position(entity, delta_time, game->entities, &game->map);
	}
	return (true);
}
