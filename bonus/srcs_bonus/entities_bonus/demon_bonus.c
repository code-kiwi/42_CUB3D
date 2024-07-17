/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demon_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:59 by brappo            #+#    #+#             */
/*   Updated: 2024/07/17 10:34:47 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

static bool	demon_update(t_game *game, t_entity *entity, float delta_time)
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
		if (sprite->animation == game->textures[IDX_TXTR_DEMON_WALK])
			sprite->animate = false;
		if (entity->cooldown > 0)
			return (true);
		sprite->next_animation = game->textures[IDX_TXTR_DEMON_WALK];
		sprite->animation = game->textures[IDX_TXTR_DEMON_ATTACK];
		entity->cooldown = DEMON_ATTACK_PAUSE;
		player_get_damage(game, DEMON_ATTACK_DAMAGE);
	}
	else
		update_entity_position(entity, delta_time, game->entities, &game->map);
	return (true);
}

static bool	demon_get_killed(t_game *game, t_entity *entity)
{
	if (game == NULL || entity == NULL || game->entities == NULL)
		return (false);
	if (game->last_entity_updated->content == entity)
		game->last_entity_updated = game->last_entity_updated->next;
	entity->sprite->animation = game->textures[IDX_TXTR_DEMON_DEATH];
	entity->sprite->next_animation = NULL;
	ft_lst_remove_if(&game->entities, entity, equal, t_entity_destroy);
	return (true);
}

static bool	demon_get_damage(t_game *game, t_entity *entity, size_t damage)
{
	entity->sprite->next_animation = game->textures[IDX_TXTR_DEMON_WALK];
	entity->sprite->animation = game->textures[IDX_TXTR_DEMON_PAIN];
	entity->sprite->frame_update_delta = 0;
	damage_entity(game, entity, damage);
	return (true);
}

static bool	demon_get_chainsawed(t_game *game, t_entity *entity)
{
	(void)game;
	(void)entity;
	return (true);
}

bool	demon_init(t_entity *entity, t_list *textures[MAP_NB_IDS])
{
	entity->update = demon_update;
	entity->get_killed = demon_get_killed;
	entity->get_damage = demon_get_damage;
	entity->get_chainsawed = demon_get_chainsawed;
	entity->health_point = DEMON_HEALTH_POINT;
	entity->speed = DEMON_SPEED;
	entity->squared_radius = DEMON_SQUARED_RADIUS;
	entity->type = ft_calloc(1, sizeof(t_demon));
	t_sprite_init(entity->sprite, textures[IDX_TXTR_DEMON_WALK], WIN_HEIGHT);
	return (entity->type != NULL);
}
