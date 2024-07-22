/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imp_update_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:50:44 by root              #+#    #+#             */
/*   Updated: 2024/07/22 11:02:19 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "sprite_bonus.h"
#include "entities_bonus.h"
#include "bullets_bonus.h"

static void	stop_walk_animation(t_sprite *sprite, t_list *textures[MAP_NB_IDS])
{
	if (sprite->animation == textures[IDX_TXTR_IMP_WALK])
		sprite->animate = false;
}

static void	imp_close_attack(t_entity *entity, t_sprite *sprite, t_game *game)
{
	if (entity->cooldown > 0)
		return ;
	sprite->next_animation = game->textures[IDX_TXTR_IMP_WALK];
	sprite->animation = game->textures[IDX_TXTR_IMP_ATTACK];
	entity->cooldown = IMP_ATTACK_PAUSE;
	player_get_damage(game, IMP_ATTACK_DAMAGE);
}

static bool	imp_range_attack(t_entity *entity, t_sprite *sprite, t_game *game)
{
	if (entity->cooldown > 0)
		return (true);
	sprite->next_animation = game->textures[IDX_TXTR_IMP_WALK];
	sprite->animation = game->textures[IDX_TXTR_IMP_ATTACK];
	entity->cooldown = IMP_ATTACK_PAUSE;
	return (entity_shoot_bullet(game, entity, imp_projectile_init));
}

bool	imp_update(t_game *game, t_entity *entity, float delta_time)
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
	if (distance < IMP_ATTACK_RANGE)
	{
		stop_walk_animation(sprite, game->textures);
		imp_close_attack(entity, sprite, game);
	}
	else if (!entity->see_player)
	{
		update_entity_position(entity, delta_time, game->entities, &game->map);
		if (entity->path == NULL)
			stop_walk_animation(sprite, game->textures);
	}
	else
	{
		stop_walk_animation(sprite, game->textures);
		return (imp_range_attack(entity, sprite, game));
	}
	return (true);
}
