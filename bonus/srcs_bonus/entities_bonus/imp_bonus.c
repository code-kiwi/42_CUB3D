/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imp_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:59 by brappo            #+#    #+#             */
/*   Updated: 2024/07/19 10:24:39 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

static bool	imp_update(t_game *game, t_entity *entity, float delta_time)
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
		if (sprite->animation == game->textures[IDX_TXTR_IMP_WALK])
			sprite->animate = false;
		if (entity->cooldown > 0)
			return (true);
		sprite->next_animation = game->textures[IDX_TXTR_IMP_WALK];
		sprite->animation = game->textures[IDX_TXTR_IMP_ATTACK];
		entity->cooldown = IMP_ATTACK_PAUSE;
		player_get_damage(game, IMP_ATTACK_DAMAGE);
	}
	else
		update_entity_position(entity, delta_time, game->entities, &game->map);
	return (true);
}

static bool	imp_get_killed(t_game *game, t_entity *entity)
{
	if (game == NULL || entity == NULL || game->entities == NULL)
		return (false);
	if (game->last_entity_updated->content == entity)
		game->last_entity_updated = game->last_entity_updated->next;
	entity->sprite->animation = game->textures[IDX_TXTR_IMP_DEATH];
	entity->sprite->next_animation = NULL;
	entity->sprite->animate = true;
	ft_lst_remove_if(&game->entities, entity, equal, t_entity_destroy);
	return (true);
}

static bool	imp_get_damage(t_game *game, t_entity *entity, size_t damage)
{
	entity->sprite->next_animation = game->textures[IDX_TXTR_IMP_WALK];
	entity->sprite->animation = game->textures[IDX_TXTR_IMP_PAIN];
	entity->sprite->frame_update_delta = 0;
	damage_entity(game, entity, damage);
	return (true);
}

static bool	imp_get_chainsawed(t_game *game, t_entity *entity)
{
	(void)game;
	(void)entity;
	return (true);
}

bool	imp_init(t_entity *entity, t_list *textures[MAP_NB_IDS])
{
	entity->update = imp_update;
	entity->get_killed = imp_get_killed;
	entity->get_damage = imp_get_damage;
	entity->get_chainsawed = imp_get_chainsawed;
	entity->health_point = IMP_HEALTH_POINT;
	entity->speed = IMP_SPEED;
	entity->squared_radius = IMP_SQUARED_RADIUS;
	entity->type = ft_calloc(1, sizeof(t_demon));
	t_sprite_init(entity->sprite, textures[IDX_TXTR_IMP_WALK], WIN_HEIGHT);
	return (entity->type != NULL);
}
