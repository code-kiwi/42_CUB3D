/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demon_update_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:49:15 by root              #+#    #+#             */
/*   Updated: 2024/07/19 17:14:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

static void	stop_walk_animation(t_sprite *sprite, t_list *textures[MAP_NB_IDS])
{
	if (sprite->animation == textures[IDX_TXTR_DEMON_WALK])
		sprite->animate = false;
}

static void	demon_attack(t_entity *entity, t_sprite *sprite, t_game *game)
{
	if (entity->cooldown > 0)
			return ;
	sprite->next_animation = game->textures[IDX_TXTR_DEMON_WALK];
	sprite->animation = game->textures[IDX_TXTR_DEMON_ATTACK];
	entity->cooldown = DEMON_ATTACK_PAUSE;
	player_get_damage(game, DEMON_ATTACK_DAMAGE);
}

bool	demon_update(t_game *game, t_entity *entity, float delta_time)
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
	if (distance < DEMON_ATTACK_RANGE)
	{
		stop_walk_animation(sprite, game->textures);
		demon_attack(entity, sprite, game);
	}
	else
	{
		update_entity_position(entity, delta_time, game->entities, &game->map);
		if (entity->path == NULL)
			stop_walk_animation(sprite, game->textures);
	}
	return (true);
}
